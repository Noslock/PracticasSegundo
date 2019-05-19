#pragma once
#include "fexploracion.hpp"
#include "fD_aleatoria.hpp"
#include "fD_modulo.hpp"
#include "fD_suma.hpp"

template <class CLAVE>
class fE_doble : public fExploracion<CLAVE>
{
private:
  int nCeldas;
  fDispersion<CLAVE> *hx;

public:
  fE_doble(int size, fDispersion<CLAVE> *funcion_h);
  ~fE_doble();

  int exploracion(CLAVE clave, int i);
};

template <class CLAVE>
fE_doble<CLAVE>::fE_doble(int size, fDispersion<CLAVE> *funcion_h) : nCeldas(size), hx(funcion_h)
{
}

template <class CLAVE>
fE_doble<CLAVE>::~fE_doble()
{
}

template <class CLAVE>
int fE_doble<CLAVE>::exploracion(CLAVE k, int i)
{
  int doble = (*hx).dispersion(k);
  return ((doble + (i * doble)) % nCeldas);
}