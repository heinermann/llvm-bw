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

std::ostream& Block::writeTxt(std::ostream& os, int tab)
{
  os << std::string(tab, ' ') << "BLOCK \"" << this->getId().value_or("__NO_ID__") << "\":\n";
  for (const auto& inst : instructions) {
    inst->writeTxt(os, tab + 2);
  }
  return os;
}

bool Block::add_instruction(std::shared_ptr<TrigInst> instruction)
{
  this->instructions.push_back(instruction);
  return true;
}
