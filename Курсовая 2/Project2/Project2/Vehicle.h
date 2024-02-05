#pragma once

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include <string>

class LIBRARY_API Vehicle {
protected:
     std::string name;
     int speed;
public:
     Vehicle(const std::string& n, const int& s);
     std::string getName() const;
     virtual double calculateTime(double distance) const;
};
