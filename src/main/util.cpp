#include "util.hpp"

#include <math.h>

namespace util
{
  int lengthOfNumber(int number)
  {
    return static_cast<int>(ceil(log10(number + 1)));
  }
} // namespace util