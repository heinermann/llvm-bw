#include "ConstPtr.h"

#include <ostream>

using namespace llvmbw;

bool ConstPtr::optimizationPass()
{
  return false;
}

std::ostream& ConstPtr::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& ConstPtr::writeTxt(std::ostream& os, int tab = 0)
{
  os << std::string(tab, ' ') << "[" << this->value << "]";
  return os;
}
