#pragma once

#include <stdexcept>
#include <string>

class PreconViolatedExcept : public std::logic_error
{
public:
	PreconViolatedExcept(const std::string& message = "");
};