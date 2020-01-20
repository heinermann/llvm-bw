#include "Program.h"

using namespace llvmbw;

bool Program::add_function(std::shared_ptr<Function> function)
{
  if (!function->getId()) return false;
  if (this->symbol_map.count(function->getId().value()) > 0) return false;

  this->symbol_map[function->getId().value()] = function;
  this->functions.push_back(function);
  return true;
}
