#include "Number.hpp"

class BinaryNumber : public Number<8, 2>
{
  public:
    BinaryNumber(int n = 0) : Number<8, 2>(n) {}
};

class DecimalNumber : public Number<8, 10>
{
  public:
    DecimalNumber(int n = 0) : Number<8, 10>(n) {}
};

class OctalNumber : public Number<8, 8>
{
  public:
    OctalNumber(int n = 0) : Number<8, 8>(n) {}
};

class HexadecimalNumber : public Number<8, 16>
{
  public:
    HexadecimalNumber(int n = 0) : Number<8, 16>(n) {}
};