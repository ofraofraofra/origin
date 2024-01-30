#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include <string>


class Leaver {
public:
    LIBRARY_API std::string leav(const std::string& name);
};
