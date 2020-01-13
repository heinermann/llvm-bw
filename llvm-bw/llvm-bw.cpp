#include <iostream>
#include <limits>

#include "IRReader.h"
#include "BWMap.h"

#include "../chklib/Logger.h"

Logger logger;

void askPressEnter() {
#ifdef _DEBUG
  std::cout << "Press enter to continue..." << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    std::cerr << "Expected usage: llvm-bw <IR_input> <trg_output>" << std::endl;
    return 1;
  }
  askPressEnter();  // to attach debugger

  // ---

  llvmbw::IRReader ir{ argv[1] };
  ir.debugPrintAll();
  
  // ---

  llvmbw::BWMap map{ argv[2] };
  map.createBackup();
  map.deleteCompiledTriggers();

  // stuff

  map.save();
}
