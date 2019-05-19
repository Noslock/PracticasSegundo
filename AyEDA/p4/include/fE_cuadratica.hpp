#pragma once
#include "fexploracion.hpp"
#include "fD_aleatoria.hpp"
#include "fD_modulo.hpp"
#include "fD_suma.hpp"

template <class CLAVE>
class fE_cuadratica : public fExploracion<CLAVE>
{
  private:
    int nCeldas;
    fDispersion<CLAVE> *hx;

  public:
    fE_cuadratica(int size, fDispersion<CLAVE> *funcion_h);
    ~fE_cuadratica();

    virtual int exploracion(CLAVE clave, int i);
};

template <class CLAVE>
fE_cuadratica<CLAVE>::fE_cuadratica(int size, fDispersion<CLAVE> *funcion_h) : nCeldas(size), hx(funcion_h)
{
}

template <class CLAVE>
fE_cuadratica<CLAVE>::~fE_cuadratica()
{
}

template <class CLAVE>
int fE_cuadratica<CLAVE>::exploracion(CLAVE k, int i)
{
    int cuadratica = (*hx).dispersion(k);
    return ((cuadratica + (i * i)) % nCeldas);
}