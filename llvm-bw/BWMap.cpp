#include "BWMap.h"

#include <string>
#include <filesystem>

using namespace llvmbw;

BWMap::BWMap(const std::string& mapFileName)
  : filename(mapFileName)
  , map(mapFileName)
{
}

void BWMap::createBackup() {
  std::filesystem::path backupPath{ this->filename };
  const std::filesystem::path originalStem = backupPath.stem();
  const std::filesystem::path originalExt = backupPath.extension();
  
  // Find a backup file name that doesn't exist
  int i = 0;
  do {
    backupPath.replace_filename(originalStem.string() + "-backup-" + std::to_string(i));
    backupPath.replace_extension(originalExt);
    ++i;
  } while (std::filesystem::exists(backupPath));
 
  std::filesystem::copy(this->filename, backupPath);
}

void BWMap::save() {
  map.SaveFile();
}
