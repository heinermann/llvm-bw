#include "Constant.h"

#include <ostream>

using namespace llvmbw;

bool Constant::optimizationPass()
{
  return false;
}

std::ostream& Constant::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& Constant::writeTxt(std::ostream& os, int tab = 0)
{
  os << std::string(tab, ' ') << this->value;
  return os;
}
