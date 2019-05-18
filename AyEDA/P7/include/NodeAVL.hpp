#pragma once

#include "iostream"

template <class T>
class NodeAVL  
{
private:
    //El nodo AVL contiene el dato o clave del nodo, 2 punteros a los nodos que apunta y un entero que indica el balance (0, 1 o -1)
    T data;
    NodeAVL<T> *izq, *der;
    int bal;

public:
    NodeAVL(T nodo) : data(nodo), izq(NULL), der(NULL), bal(0)
    {
    }

    NodeAVL(const NodeAVL<T> &N)
    {
        data = N.data;
        izq = NULL;
        der = NULL;
        data = N.data;
    }

    T get_data(void) const
    {
        return data;
    }

    int get_bal(void) const
    {
        return bal;
    }

    void set_data(T dato)
    {
        data = dato;
    }

    void set_bal(int bal_)
    {
        bal = bal_;
    }

    void set_izq(NodeAVL<T> *&izq_)
    {
        izq = izq_;
    }

    void set_der(NodeAVL<T> *&der_)
    {
        der = der_;
    }

    NodeAVL<T> *&get_izq(void)
    {
        return izq;
    }

    NodeAVL<T> *&get_der(void)
    {
        return der;
    }

    std::ostream &write(std::ostream &os)
    {
        std::cout << data;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const NodeAVL<T> &node)
    {
        os << node.get_data();
        return os;
    }
};
