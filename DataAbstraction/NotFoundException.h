#pragma once

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
	NotFoundException(const std::string& message = "");
};