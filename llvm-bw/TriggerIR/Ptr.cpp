#include "Ptr.h"

#include <ostream>

using namespace llvmbw;

bool Ptr::optimizationPass()
{
  return false;
}

std::ostream& Ptr::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& Ptr::writeTxt(std::ostream& os, int tab)
{
  os << "[" << std::hex;
  this->value->writeTxt(os);
  os << "]" << std::dec;
  return os;
}
