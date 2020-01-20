#include "Block.h"

#include <ostream>
#include <string>

using namespace llvmbw;

bool Block::optimizationPass()
{
  return false;
}

std::ostream& Block::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& Block::writeTxt(std::ostream& os, int tab = 0)
{
  os << std::string(tab, ' ') << "BLOCK \"" << this->getId().value_or("__NO_ID__") << "\":\n";
  return os;
}
