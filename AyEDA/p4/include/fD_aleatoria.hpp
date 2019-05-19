#pragma once
#include "fdispersion.hpp"

template <class CLAVE>
class fD_aleatoria : public fDispersion<CLAVE>
{
  private:
    int nCeldas;

  public:
    fD_aleatoria(int size);
    ~fD_aleatoria();

    int dispersion(CLAVE k);
};

template <class CLAVE>
fD_aleatoria<CLAVE>::fD_aleatoria(int size) : nCeldas(size)
{
}

template <class CLAVE>
fD_aleatoria<CLAVE>::~fD_aleatoria()
{
}

template <class CLAVE>
int fD_aleatoria<CLAVE>::dispersion(CLAVE k)
{
    srand(k);
    return (rand() % nCeldas);
}