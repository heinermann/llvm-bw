#include "Assign.h"

#include <ostream>

using namespace llvmbw;

bool Assign::optimizationPass()
{
  return false;
}

std::ostream& Assign::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& Assign::writeTxt(std::ostream& os, int tab = 0)
{
  os << std::string(tab, ' ');
  lhs->writeTxt(os);
  os << " = ";
  rhs->writeTxt(os);
  os << "\n";
  return os;
}
