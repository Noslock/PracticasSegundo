#pragma once
#include <iostream>
#include <fDispersion.hpp>

template <class CLAVE>
class fD_modulo : public fDispersion<CLAVE>
{
  private:
    int nCeldas;

  public:
    fD_modulo(int size);
    ~fD_modulo();

    virtual int h(CLAVE clave);
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
int fD_modulo<CLAVE>::h(CLAVE clave)
{
    int modulo = (clave % nCeldas);
    return modulo;
}
