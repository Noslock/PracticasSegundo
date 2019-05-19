#pragma once
#include <iostream>

template <class CLAVE>
class sort
{
    public:
    virtual void sorting(CLAVE *A, int B) = 0;
};