#pragma once
#include <iostream>
#include "fdispersion.hpp"

template <class CLAVE>
class fD_modulo : public fDispersion<CLAVE>
{
private:
  int nCeldas;

public:
  fD_modulo(int size);
  ~fD_modulo();

  int dispersion(CLAVE k);
};

template <class CLAVE>
fD_modulo<CLAVE>::fD_modulo(int size) : nCeldas(size)
{
}

template <class CLAVE>
fD_modulo<CLAVE>::~fD_modulo()
{
}

template <class CLAVE>
int fD_modulo<CLAVE>::dispersion(CLAVE k)
{
  int modulo = (k % nCeldas);
  return modulo;
}
