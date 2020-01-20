#pragma once

#include <iosfwd>
#include <cstdint>
#include <string>
#include <optional>

namespace llvmbw {
  class TrigInst {
  public:
    /**
      * Node types in Trigger IR.
      */
    enum class Type {
      Invalid,

      Prologue,
      Epilogue,
      Function,
      Block,

      Allocate,
      StackAlloc,

      Constant,
      ConstPtr,
      Variable,
      NextPtr,

      Assign,
      Add,
      Subtract,

      BitwiseNot,
      Negate,

      BitwiseAnd,
      BitwiseOr,
      BitwiseXor,

      Shl,
      Shr
    };

  private:
    Type type;
    std::optional<std::string> id;

  protected:
    TrigInst(Type _type, const std::optional<std::string>& _id = std::nullopt)
      : type(_type)
      , id(_id)
    {}

  public:
    virtual ~TrigInst() {}

    /**
      * Gets the node type.
      */
    Type getType() const {
      return this->type;
    }

    const std::optional<std::string>& getId() const {
      return this->id;
    }

    /**
      * Runs a pass at attempting to optimize the IR.
      * Returns true if an optimization occurred and false if it has not.
      */
    virtual bool optimizationPass() = 0;

    /**
      * Assigns a memory address to this IR node (to be allocated throughout its subnodes).
      * Returns `startAddress + size()`.
      */
    virtual uint32_t assignMemAddress(uint32_t startAddress) = 0;

    /**
      * Get the number of bytes needed to allocate this block.
      */
    virtual size_t size() = 0;

    /**
      * Write a graphviz graph (dot format) to `os`.
      */
    virtual std::ostream& writeDot(std::ostream& os) = 0;

    /**
      * Write a plaintext representation to `os`.
      */
    virtual std::ostream& writeTxt(std::ostream& os, int tab = 0) = 0;

    /**
      * Write data to `os`.
      */
    virtual std::ostream& writeData(std::ostream& os, bool finished = false) = 0;
  };
}
