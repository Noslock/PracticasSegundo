#pragma once
#include <iostream>

template <class CLAVE>
class fDispersion
{
public:
  virtual int h(CLAVE clave) = 0;
};