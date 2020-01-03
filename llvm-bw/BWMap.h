#pragma once
#include <string>
#include "../chklib/MappingCore.h"

namespace llvmbw {
  static constexpr int TRIGGER_FLAG_COMPILED = 1 << 19;

  class BWMap {
  private:
    std::string filename;
    MapFile map;

  public:
    BWMap(const std::string& mapFileName);

    void createBackup();
    void deleteCompiledTriggers();

    void save();
  };
}