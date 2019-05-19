#pragma once

template <class CLAVE>
class fExploracion
{
  public:
    virtual int exploracion(CLAVE, int) = 0;
};