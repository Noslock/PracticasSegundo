#pragma once
#include <iostream>

class DNI
{
private:
  int numero;

public:
  DNI();
  DNI(int num);
  ~DNI();

  bool operator==(const DNI &dni);
  operator unsigned int() const { return numero; } //pdf pide long
};