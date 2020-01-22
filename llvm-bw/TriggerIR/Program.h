#pragma once

#include "Function.h"

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <iosfwd>

namespace llvmbw {
  class Program {
  private:
    std::vector<std::shared_ptr<Function>> functions;

    std::unordered_map<std::string, std::shared_ptr<Function>> symbol_map;

  public:

    bool add_function(std::shared_ptr<Function> function);

    std::ostream& writeTxt(std::ostream& os);
  };
}