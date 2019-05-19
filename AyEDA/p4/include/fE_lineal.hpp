#pragma once
#include "fexploracion.hpp"
#include "fD_aleatoria.hpp"
#include "fD_modulo.hpp"
#include "fD_suma.hpp"

template <class CLAVE>
class fE_lineal : public fExploracion<CLAVE>
{
private:
  int nCeldas;
  fDispersion<CLAVE> *hx;

public:
  fE_lineal(int size, fDispersion<CLAVE> *funcion_h);
  ~fE_lineal();

  int exploracion(CLAVE clave, int i);
};

template <class CLAVE>
fE_lineal<CLAVE>::fE_lineal(int size, fDispersion<CLAVE> *funcion_h) : nCeldas(size), hx(funcion_h)
{
}

template <class CLAVE>
fE_lineal<CLAVE>::~fE_lineal()
{
}

template <class CLAVE>
int fE_lineal<CLAVE>::exploracion(CLAVE k, int i)
{
  int lineal = (*hx).dispersion(k);
  return ((lineal + i) % nCeldas);
}