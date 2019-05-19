#pragma once
#include "contador.hpp"
#include <iostream>

template <class CLAVE>
class sort
{
    public:
    virtual void sorting(CLAVE *A, int B, char *modo) = 0;
};