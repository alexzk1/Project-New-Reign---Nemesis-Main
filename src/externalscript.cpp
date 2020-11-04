#include "Global.h"

//#undef pyslots
//#define MS_NO_COREDLL
#include <Python.h>
//#define pyslots

#include <QProcess>
#include <QDir>

#include "externalscript.h"

#include "generate/generator_utility.h"
#include "generate/alternateanimation.h"

#include "utilities/algorithm.h"
#include "auto_close_fp.h"

using namespace std;

bool dummyScript = false;


void BatchScriptThread(const FileNameString& filename, const filesystem::path& filepath, bool hidden);
void PythonScriptThread(const FileNameString& filename, const FileNameString::value_type* filepath);

#ifdef WIN32
    using Vecs = VecWStr;
    const static FileNameString separator = "\\";
#else
    using Vecs = VecStr;
    const static FileNameString separator = "/";
#endif

void RunScript(const filesystem::path& directory, bool& hasScript)
{
    if (!isFileExist(directory))
    {
        FolderCreate(directory);
        return;
    }

    bool warning = false;
    Vecs scriptlist;
    read_directory(directory, scriptlist);

    for (auto& file : scriptlist)
    {
        auto scriptpath = dir2str(directory) + file;
        std::filesystem::path scriptfile(scriptpath);

        // hidden scripts
        if (!std::filesystem::is_directory(scriptfile))
        {
            const auto ext = dir2str(scriptfile.extension());
#ifdef WIN32
            // bat script
            if (nemesis::iequals(ext, STR(".bat")))
            {
                hasScript = true;
                BatchScriptThread(dir2str(scriptfile.filename()), scriptpath, false);
            }
            // python script
            else
#endif
                if (nemesis::iequals(ext, STR(".py")))
                {
                    hasScript = true;
                    PythonScriptThread(dir2str(scriptfile.filename()), scriptpath.c_str());
                }
        }
        // visible scripts
        else
            if (nemesis::iequals(file, STR("show")) && std::filesystem::is_directory(scriptfile))
            {
                Vecs shownscriptlist;
                read_directory(scriptpath, shownscriptlist);

                for (auto& shown : shownscriptlist)
                {
                    auto shownpath = scriptpath + separator + shown;
                    std::filesystem::path shownscript(shownpath);

                    if (!std::filesystem::is_directory(shownscript))
                    {
                        const auto ext = dir2str(shownscript.extension());
#ifdef WIN32
                        // bat script
                        if (nemesis::iequals(ext, STR(".bat")))
                        {
                            hasScript = true;
                            BatchScriptThread(dir2str(shownscript.filename()), shownpath, true);
                        }
                        // python script
                        else
#endif
                            if (nemesis::iequals(ext, STR(".py")))
                            {
                                hasScript = true;
                                PythonScriptThread(dir2str(shownscript.filename()), shownpath.c_str());
                            }
                    }
                }
            }
    }

    if (hasScript) interMsg("");
}

void BatchScriptThread(const FileNameString& filename, const filesystem::path& filepath, bool hidden)
{
    try
    {
#ifdef WIN32
        FileNameString msg = TextBoxMessage(1016) + L": " + filename;
        interMsg(msg);
        DebugLogging(msg);
#endif
        if (hidden)
        {
            QProcess* p = new QProcess();
            p->start(fns2qs(filepath));
            p->waitForFinished();
            delete p;
        }
        else
        {
            if (QProcess::execute(fns2qs(filepath)) != 0) WarningMessage(1023, filepath);
        }
    }
    catch (const exception& ex)
    {
        ErrorMessage(6008, filename, ex.what());
    }
    catch (...)
    {
        ErrorMessage(6008, filename, "Unknown exception");
    }
}

void PythonScriptThread(const FileNameString& filename, const FileNameString::value_type *filepath)
{
    try
    {
#ifdef WIN32
        FileNameString msg = TextBoxMessage(1016) + L": " + filename;
        interMsg(msg);
        DebugLogging(msg);
#endif
        auto_close_fp f(filepath, STR("r"));

        if (f)
        {
            try
            {
                Py_Initialize();
                PyRun_SimpleFile(f, nemesis::transform_to<string>(FileNameString(filepath)).c_str());
                Py_Finalize();
            }
            catch (const exception& ex)
            {
                ErrorMessage(6008, filename, ex.what());
            }
            catch (...)
            {
                ErrorMessage(6008, filename, "Unknown exception");
            }

            fclose(f);
        }
    }
    catch (const exception& ex)
    {
        ErrorMessage(6008, filename, ex.what());
    }
    catch (...)
    {
        ErrorMessage(6008, filename, "Unknown exception");
    }
}
