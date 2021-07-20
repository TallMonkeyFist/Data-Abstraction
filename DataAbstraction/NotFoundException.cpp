#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string& message) : std::logic_error("Not Found Exception: " + message)
{
}