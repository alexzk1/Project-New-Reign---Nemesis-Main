#ifndef ALPHANUM_HPP_
#define ALPHANUM_HPP_

#include <string>

#ifdef WIN32
    #include <shlwapi.h>
#else
    #include <string.h>
    #include<cstring>
#endif

struct alphanum_less
{
#ifdef WIN32
    bool operator()(const std::string& x, const std::string& y) const
    {
        return lstrcmpiA(LPCSTR(x.c_str()), LPCSTR(y.c_str())) < 0;
    }
#else
    static inline std::string toLower(std::string src)
    {
        std::transform(src.begin(), src.end(), src.begin(), ::tolower);
        return src;
    }
    bool operator()(const std::string& x, const std::string& y) const
    {
        return toLower(x) < toLower(y);
    }
#endif
    typedef std::string first_argument_type;
    typedef std::string second_argument_type;
    typedef bool result_type;
};

#endif
