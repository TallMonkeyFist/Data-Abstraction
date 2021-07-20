#include "PreconViolatedExcept.h"

PreconViolatedExcept::PreconViolatedExcept(const std::string& message) : std::logic_error("Precondition Violated Exception: " + message)
{
}