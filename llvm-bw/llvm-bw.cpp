﻿#include <iostream>
#include <limits>

#include "IRReader.h"
#include "BWMap.h"

#include "TriggerIR/Program.h"

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
  //ir.debugPrintAll();

  std::shared_ptr<llvmbw::Program> program = ir.lower_all();
  std::cout << "Writing...\n\n";
  program->writeTxt(std::cout);
  std::cout.flush();
  // ---

  //llvmbw::BWMap map{ argv[2] };
  //map.createBackup();
  //
  //// stuff
  //
  //map.save();
}
