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

std::ostream& Constant::writeTxt(std::ostream& os, int tab)
{
  os << this->value;
  if (this->bitmask != 0xFFFFFFFF) {
    os << std::hex << " & 0x" << this->bitmask << std::dec;
  }
  return os;
}
