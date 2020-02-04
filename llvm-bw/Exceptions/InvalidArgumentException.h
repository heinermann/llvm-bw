#pragma once
#include <exception>
#include <string>

class InvalidArgumentException : public std::exception
{
private:
  const std::string exception_str;
public:
  InvalidArgumentException(const std::string& context)
    : exception_str("Invalid argument. Context: " + context)
  {}

  const char* what() const throw() {
    return this->exception_str.c_str();
  }
};
