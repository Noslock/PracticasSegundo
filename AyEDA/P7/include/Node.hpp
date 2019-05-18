#pragma once

#include "iostream"

template <class T>
class NodeB
{
  private:
    T data;
    NodeB<T> *izq, *der;

  public:
    NodeB(T nodo) : data(nodo), izq(NULL), der(NULL)
    {
    }

    NodeB(const NodeB<T> &N)
    {
        data = N.data;
        izq = NULL;
        der = NULL;
    }

    T get_data(void) const
    {
        return data;
    }

    void set_data(T dato)
    {
        data = dato;
    }

    NodeB<T> *&get_izq(void)
    {
        return izq;
    }

    NodeB<T> *&get_der(void)
    {
        return der;
    }

    std::ostream &write(std::ostream &os)
    {
        std::cout << data;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const NodeB<T> &node)
    {
        os << node.get_data();
        return os;
    }
};
