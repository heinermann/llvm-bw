#include "Program.h"

#include <iostream>

using namespace llvmbw;

bool Program::add_function(std::shared_ptr<Function> function)
{
  if (!function->getId()) return false;
  if (this->symbol_map.count(function->getId().value()) > 0) return false;

  this->symbol_map[function->getId().value()] = function;
  this->functions.push_back(function);
  return true;
}

std::ostream& Program::writeTxt(std::ostream& os) {
  for (const auto fn : this->functions) {
    fn->writeTxt(os);
  }
  return os;
}
