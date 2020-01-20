#include "Function.h"

#include "../Exceptions/MissingIdException.h"
#include "../Exceptions/NameConflictException.h"

#include <ostream>
#include <string>

using namespace llvmbw;

bool Function::optimizationPass()
{
  return false;
}

std::ostream& Function::writeDot(std::ostream& os)
{
  return os;
}

std::ostream& Function::writeTxt(std::ostream& os, int tab = 0)
{
  os << std::string(tab, ' ') << "FUNCTION \"" << this->getId().value_or("__NO_ID__") << "\":\n";
  return os;
}

void Function::add_block(std::shared_ptr<Block> block) {
  const std::string context = "add_block for \"" + this->getId().value() + "\"";
  if (!block->getId()) throw MissingIdException(context);
  if (this->local_symbol_map.count(block->getId().value) > 0) throw NameConflictException(block->getId().value(), context);

  this->blocks.push_back(block);
  this->local_symbol_map[block->getId().value] = block;
}
