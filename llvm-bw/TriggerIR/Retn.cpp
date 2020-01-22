#include "Retn.h"

#include <ostream>

using namespace llvmbw;

bool Retn::optimizationPass()
{
  return false;
}

std::ostream& Retn::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& Retn::writeTxt(std::ostream& os, int tab)
{
  os << std::string(tab, ' ') << "return";
  if (this->value) {
    os << ' ';
    this->value.value()->writeTxt(os);
  }
  return os << '\n';
}
