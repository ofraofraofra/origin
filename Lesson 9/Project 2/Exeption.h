#pragma once

#include <exception>
#include <stdexcept>

class WrongFigure : public std::domain_error
{
public:
	WrongFigure(const std::string& message) : std::domain_error (message) {}
};


