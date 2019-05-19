#pragma once
#include "contador.hpp"
#include <iostream>

template <class CLAVE>
class Celda_t
{
  private:
    int nBlock_;
    CLAVE *v;
    int pos_;
    //nBlock nos indica el número de bloques que tiene la elda, el puntero tipo clave
    //apunta a las claves que contiene la Celda y la posición nos indica hasta dónde está llena la caleda
  public:
    //Constructor por parámetro
    Celda_t(int n) : nBlock_(n), pos_(0)
    {
        v = new CLAVE[n];
    }

    ~Celda_t()
    {
        if (v != NULL)
        {
            delete[] v;
            v = NULL;
        }
    }

    //Constructor de copia
    Celda_t operator=(Celda_t C)
    {
        nBlock_ = C.nBlock_;
        pos_ = C.pos_;
        v = new CLAVE(nBlock_);
        for (int i = 0; i < nBlock_; i++)
        {
            v[i] = C.v[i];
        }
        return (*this);
    }

    //Se busca la clave en todos los bloques de la Celda, si no se encuentra se retorna false
    bool search(CLAVE k) const
    {
        for (int i = 0; i < nBlock_; i++)
        {
            Contador A;
            A++;
            if (v[i] == k)
            {
                return true;
            }
        }
        return false;
    }

    //Se inserta la clave si no se encuentra dentro y no está llena la celda
    bool insertk(CLAVE k)
    {
        if ((!search(k)) && (!full()))
        {
            Contador A;
            A++;
            v[pos_] = k;
            pos_++;
            return true;
        }
        return false;
    }

    //Se comprueba si está llena la celda mediante el elemento pos_;
    bool full() const
    {
        if (pos_ == nBlock_)
        {
            return true;
        }
        return false;
    }

    std::ostream &operator<<(std::ostream &os)
    {
        for (int i = 0; i < nBlock_; i++)
        {
            os << v[i] << "|";
        }
        return os;
    }
};
