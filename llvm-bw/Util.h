#pragma once

#include "Exceptions/InvalidArgumentException.h"

#include <string>

namespace llvmbw {
  void require(bool req, const std::string& message_not_met = "") {
    if (!req) throw new InvalidArgumentException(message_not_met);
  }
}