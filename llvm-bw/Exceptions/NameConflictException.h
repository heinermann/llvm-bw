#pragma once
#include <exception>
#include <string>

class NameConflictException : public std::exception
{
private:
  const std::string exception_str;
public:
  NameConflictException(const std::string& name, const std::string& context)
    : exception_str("There is a naming conflict with \"" + name + "\", context: " + context)
  {}

  const char* what() const throw() {
    return this->exception_str.c_str();
  }
};
