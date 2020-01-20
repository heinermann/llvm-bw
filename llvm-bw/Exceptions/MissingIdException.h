#pragma once
#include <exception>
#include <string>

class MissingIdException : public std::exception
{
private:
  const std::string exception_str;
public:
  MissingIdException(const std::string& context)
    : exception_str("An ID is expected. Context: " + context)
  {}

  const char* what() const throw() {
    return this->exception_str.c_str();
  }
};
