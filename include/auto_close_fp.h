#pragma once
#include <memory>
#include <stdlib.h>
#include "containers_helpers.h"

//warning! do not call fclose manually, otherwise it is UB
class auto_close_fp
{
private:
    std::shared_ptr<FILE> fp{nullptr};
public:
    auto_close_fp() = default;
    auto_close_fp(const auto_close_fp& )  = default;
    auto_close_fp(auto_close_fp&& ) = default;

    auto_close_fp& operator=(const auto_close_fp& )  = default;
    auto_close_fp& operator=(auto_close_fp&& )  = default;

    auto_close_fp(const std::string& fn, const std::string& mode)
    {
        const static std::string ro[] =
        {
            "rb",
            "rt",
            "r",
        };
        const bool flush = !types_ns::contains(ro, mode);
        fp = std::shared_ptr<FILE>(std::fopen(fn.c_str(), mode.c_str()), [flush](auto f)
        {
            if (f)
            {
                if (flush)
                    std::fflush(f);
                std::fclose(f);
            }
        });
    }
#ifdef WIN32
    auto_close_fp(const std::wstring& fn, const std::wstring& mode)
    {
        const static std::wstring ro[] =
        {
            "rb",
            "rt",
            "r",
        };
        const bool flush = !types_ns::contains(ro, mode);
        FILE *f = NULL;
        _wfopen_s(&f, fn.c_str(), mode.c_str());

        fp = std::shared_ptr<FILE>(f, [flush](auto f)
        {
            if (f)
            {
                if (flush)
                    std::fflush(f);
                std::fclose(f);
            }
        });
    }
#endif
    operator FILE*() const
    {
        return get();
    }

    operator bool() const
    {
        return fp != nullptr;
    }

    FILE* get() const
    {
        return fp.get();
    }

};

//warning! don't do like that FILE* f = fopen(std::string, std::string)
//it will create tmp auto_close_fp, which will close file immediatly, buf f remains some value

//do as auto f = fopen(std::string, std::string)
auto inline fopen(const std::string& fn, const std::string& mode)
{
    return auto_close_fp(fn, mode);
}

auto inline fopen64(const std::string& fn, const std::string& mode)
{
    return auto_close_fp(fn, mode);
}


void inline fclose(const auto_close_fp&)
{
    //do nothing, it is safe-guard against case described above
}
