#pragma once
#include <string>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

namespace llvmbw {

  class IRConverter
  {
  private:
    llvm::LLVMContext context;
    std::unique_ptr<llvm::Module> module;

  public:
    IRConverter(const std::string& filename);

    bool loadFile(const std::string& filename);

    void debugPrintSymbols();
    void debugPrintGlobals();
    void debugPrintFunctions();
    void debugPrintAliases();
    void debugPrintIFuncs();
    void debugPrintMetadata();

    void debugPrintAll();
  };
}
