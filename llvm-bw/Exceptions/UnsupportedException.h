#pragma once
#include <exception>
#include <string>

class UnsupportedException : public std::exception
{
private:
  const std::string exception_str;
public:
  UnsupportedException(const std::string &str)
    : exception_str(str + " is/are currently unsupported")
  {}

  const char* what() const throw() {
    return this->exception_str.c_str();
  }
};

class NamedUnsupportedException : public std::exception
{
private:
  const std::string exception_str;
public:
  NamedUnsupportedException(const std::string& name, const std::string& str)
    : exception_str(std::string("[") + name + "] " + str + " is/are currently unsupported")
  {}

  const char* what() const throw() {
    return this->exception_str.c_str();
  }
};
