#pragma once
#include <string>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

namespace llvmbw {

  class IRReader
  {
  private:
    llvm::LLVMContext context;

  public:
    std::unique_ptr<llvm::Module> module;

    IRReader(const std::string& filename);

    bool loadFile(const std::string& filename);

    void debugPrintSymbols() const;
    void debugPrintGlobals() const;
    void debugPrintFunctions() const;
    void debugPrintAliases() const;
    void debugPrintIFuncs() const;
    void debugPrintMetadata() const;

    void debugPrintAll() const;
  };
}
