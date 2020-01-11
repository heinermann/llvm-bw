#include "IRConverter.h"

#include <llvm/Support/SourceMgr.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/ValueSymbolTable.h>

#include <iostream>

using namespace llvmbw;

IRConverter::IRConverter(const std::string& filename) {
  this->loadFile(filename);
}

bool IRConverter::loadFile(const std::string& filename) {
  llvm::SMDiagnostic err;

  this->module = llvm::parseIRFile(filename, err, context);
  if (!this->module) {
    // TODO fix whatever this was...
    std::string output_str;
    llvm::raw_string_ostream out(output_str);
    err.print("llvm-bw", out);

    std::cerr << output_str << std::endl;
    std::cerr << err.getMessage().str() << std::endl;
    return false;
  }

  std::cout << "Loaded.\n";
  std::cout << "  Module Name: " << module->getName().str() << "\n";
  std::cout << "  Data layout: " << module->getDataLayoutStr() << "\n";
  std::cout << std::endl;

  return true;
}

void IRConverter::debugPrintAll() {
  debugPrintSymbols();
  debugPrintGlobals();
  debugPrintFunctions();
  debugPrintAliases();
  debugPrintIFuncs();
  debugPrintMetadata();
}

void IRConverter::debugPrintSymbols() {
  std::cout << "Symbols:\n";
  for (const llvm::ValueName& symbol : module->getValueSymbolTable()) {
    std::cout << "  " << symbol.getKey().str() << "\n";
  }
  std::cout << std::endl;
}

void IRConverter::debugPrintGlobals() {
  std::cout << "Global Variables:\n";
  for (llvm::GlobalVariable& g : module->globals()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    g.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
void IRConverter::debugPrintFunctions() {
  std::cout << "Functions:\n";
  for (llvm::Function& f : module->functions()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;

  std::cout << "MAIN\n";
  llvm::Function* f_main = module->getFunction("main");
  for (llvm::BasicBlock& b : *f_main) {
    std::cout << "  BLOCK:\n";
    for (llvm::Instruction& in : b) {
      std::cout << in.getOpcodeName() << " - " << in.getNumOperands() << " operands\n";
    }
  }
}
void IRConverter::debugPrintAliases() {
  std::cout << "Aliases:\n";
  for (llvm::GlobalAlias& f : module->aliases()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
void IRConverter::debugPrintIFuncs() {
  std::cout << "IFuncs:\n";
  for (llvm::GlobalIFunc& f : module->ifuncs()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
void IRConverter::debugPrintMetadata() {
  std::cout << "Named Metadata:\n";
  for (llvm::NamedMDNode& f : module->named_metadata()) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    f.print(rso);

    std::cout << "  " << type_str << "\n";
  }
  std::cout << std::endl;
}
