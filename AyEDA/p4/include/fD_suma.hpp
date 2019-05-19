#pragma once
#include <iostream>
#include "fdispersion.hpp"

template <class CLAVE>
class fD_suma : public fDispersion<CLAVE>
{
  private:
    int nCeldas;

  public:
    fD_suma(int size);
    ~fD_suma();

    virtual int dispersion(CLAVE k);
};

template <class CLAVE>
fD_suma<CLAVE>::fD_suma(int size) : nCeldas(size)
{
}

template <class CLAVE>
fD_suma<CLAVE>::~fD_suma()
{
}

template <class CLAVE>
int fD_suma<CLAVE>::dispersion(CLAVE k)
{
    long int x;
    x = k;
    return (x % nCeldas);
}