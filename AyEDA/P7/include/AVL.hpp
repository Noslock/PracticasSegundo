
#pragma once

#include "NodeAVL.hpp"
#include "ArbBin.hpp"
#include "contador.hpp"

template <class T>
class AVLP : public AB<T>
{
public:
    void insertNode(const T &N)
    {
        if (!searchNode(N))
        {
            bool grow = false;
            insert_bal(N, (*this).get_root(), grow);
        }
    }

    bool searchNode(const T &N)
    {
        return searchBranch(N, (*this).get_root());
    }

    void deleteNode(T &N)
    {
        if (!(*this).empty())
        {
            if (searchNode(N))
            {
                bool shorten = false;
                delete_bal(N, (*this).get_root(), shorten);
            }
        }
    }

private:
    void insert_bal(const T &clave, NodeAVL<T> *&NP, bool &grow)
    {
        if (NP == NULL)
        {
            NP = new NodeAVL<T>(clave);
            grow = true;
        }
        else if (clave < (*NP).get_data())
        {
            insert_bal(clave, (*NP).get_izq(), grow);
            if (grow)
                insert_re_balancea_izq(NP, grow);
        }
        else
        {
            insert_bal(clave, (*NP).get_der(), grow);
            if (grow)
                insert_re_balancea_der(NP, grow);
        }
    }
    void insert_re_balancea_izq(NodeAVL<T> *&nodo, bool &grow)
    {
        switch (nodo->get_bal())
        {
        case -1:
            nodo->set_bal(0);
            grow = false;
            break;
        case 0:
            nodo->set_bal(1);
            break;
        case 1:
            NodeAVL<T> *nodo1 = nodo->get_izq();
            if (nodo1->get_bal() == 1)
                rotacion_II(nodo);
            else
                rotacion_ID(nodo);
            grow = false;
        }
    }

    void insert_re_balancea_der(NodeAVL<T> *&nodo, bool &grow)
    {
        switch (nodo->get_bal())
        {
        case 1:
            nodo->set_bal(0);
            grow = false;
            break;
        case 0:
            nodo->set_bal(-1);
            break;
        case -1:
            NodeAVL<T> *nodo1 = nodo->get_der();
            if (nodo1->get_bal() == -1)
                rotacion_DD(nodo);
            else
                rotacion_DI(nodo);
            grow = false;
        }
    }

    bool searchBranch(const T &N, NodeAVL<T> *&NP)
    {
        if (NP == NULL)
        {
            return false;
        }

        if (N == (*NP).get_data())
        {

            //std::cout << N;
            return true;
        }
        if (N < (*NP).get_data())
            return searchBranch(N, (*NP).get_izq());
        return searchBranch(N, (*NP).get_der());
    }

    void delete_bal(T &N, NodeAVL<T> *&NP, bool &shorten)
    {

        if (N < (*NP).get_data())
        {
            delete_bal(N, (*NP).get_izq(), shorten);
            if (shorten)
                delete_re_balancea_izq(NP, shorten);
        }
        else if (N > (*NP).get_data())
        {
            delete_bal(N, (*NP).get_der(), shorten);
            if (shorten)
                delete_re_balancea_der(NP, shorten);
        }
        else
        {
            //clave_dada == nodo- > clave
            NodeAVL<T> *Eliminado = NP;
            if ((*NP).get_der() == NULL)
            {
                NP = (*NP).get_izq();
                shorten = true;
            }
            else if ((*NP).get_izq() == NULL)
            {
                NP = (*NP).get_der();
                shorten = true;
            }
            else
            {
                substitute(Eliminado, (*NP).get_izq(), shorten);
                if (shorten)
                    delete_re_balancea_izq(NP, shorten);
            }
            delete Eliminado;
        }
    }

    void substitute(NodeAVL<T> *&eliminado, NodeAVL<T> *&sust, bool &shorten)
    {
        if ((*sust).get_der() != NULL)
        {
            substitute(eliminado, (*sust).get_der(), shorten);
            if (shorten)
                delete_re_balancea_der(sust, shorten);
        }
        else
        {
            (*eliminado).set_data((*sust).get_data());
            eliminado = sust;
            sust = (*sust).get_izq();
            shorten = true;
        }
    }

    void delete_re_balancea_izq(NodeAVL<T> *&nodo, bool &shorten)
    {
        switch (nodo->get_bal())
        {
        case 1:
            nodo->set_bal(0);
            break;
        case 0:
            nodo->set_bal(-1);
            shorten = false;
            break;
        case -1:
            NodeAVL<T> *nodo1 = nodo->get_der();
            if (nodo1->get_bal() > 0)
                rotacion_DI(nodo);
            else
            {
                if (nodo1->get_bal() == 0)
                    shorten = false;
                rotacion_DD(nodo);
            }
        }
    }

    void delete_re_balancea_der(NodeAVL<T> *&nodo, bool &shorten)
    {
        switch (nodo->get_bal())
        {
        case 1:
        {
            NodeAVL<T> *nodo1 = nodo->get_izq();
            if (nodo1->get_bal() < 0)
                rotacion_ID(nodo);
            else
            {
                if (nodo1->get_bal() == 0)
                    shorten = false;
                rotacion_II(nodo);
            }
            break;
        }
        case 0:
            nodo->set_bal(1);
            shorten = false;
            break;
        case -1:
            nodo->set_bal(0);
        }
    }

    void rotacion_II(NodeAVL<T> *&nodo)
    {
        NodeAVL<T> *nodo1 = nodo->get_izq();
        nodo->set_izq(nodo1->get_der());
        nodo1->set_der(nodo);
        if (nodo1->get_bal() == 1)
        {
            nodo->set_bal(0);
            nodo1->set_bal(0);
        }
        else
        {
            nodo->set_bal(1);
            nodo1->set_bal(-1);
        }
        nodo = nodo1;
    }

    void rotacion_ID(NodeAVL<T> *&nodo)
    {
        NodeAVL<T> *nodo1 = nodo->get_izq();
        NodeAVL<T> *nodo2 = nodo1->get_der();
        nodo->set_izq(nodo2->get_der());
        nodo2->set_der(nodo);
        nodo1->set_der(nodo2->get_izq());
        nodo2->set_izq(nodo1);
        if (nodo2->get_bal() == -1)
            nodo1->set_bal(1);
        else
            nodo1->set_bal(0);
        if (nodo2->get_bal() == 1)
            nodo->set_bal(-1);
        else
            nodo->set_bal(0);
        nodo2->set_bal(0);
        nodo = nodo2;
    }

    void rotacion_DD(NodeAVL<T> *&nodo)
    {
        NodeAVL<T> *nodo1 = nodo->get_der();
        nodo->set_der(nodo1->get_izq());
        nodo1->set_izq(nodo);
        if (nodo1->get_bal() == -1)
        {
            nodo->set_bal(0);
            nodo1->set_bal(0);
        }
        else
        {
            nodo->set_bal(-1);
            nodo1->set_bal(1);
        }
        nodo = nodo1;
    }

    void rotacion_DI(NodeAVL<T> *&nodo)
    {
        NodeAVL<T> *nodo1 = nodo->get_der();
        NodeAVL<T> *nodo2 = nodo1->get_izq();
        nodo->set_der(nodo2->get_izq());
        nodo2->set_izq(nodo);
        nodo1->set_izq(nodo2->get_der());
        nodo2->set_der(nodo1);
        if (nodo2->get_bal() == 1)
            nodo1->set_bal(-1);
        else
            nodo1->set_bal(0);
        if (nodo2->get_bal() == -1)
            nodo->set_bal(1);
        else
            nodo->set_bal(0);
        nodo2->set_bal(0);
        nodo = nodo2;
    }
};
