#pragma once
#include <iostream>
#include <fDispersion.hpp>

template <class CLAVE>
class fD_aleatoria : public fDispersion<CLAVE>
{
  private:
    int nCeldas;

  public:
    fD_aleatoria(int size);
    ~fD_aleatoria();

    virtual int h(CLAVE clave);
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
int fD_aleatoria<CLAVE>::h(CLAVE clave)
{
    srand(clave);
    return (rand() % nCeldas);
}
