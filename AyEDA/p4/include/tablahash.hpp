#pragma once
#include <iostream>
#include "celda.hpp"
#include "fD_aleatoria.hpp"
#include "fD_modulo.hpp"
#include "fD_suma.hpp"
#include "fdispersion.hpp"
#include "fE_cuadratica.hpp"
#include "fE_lineal.hpp"
#include "fE_redisp.hpp"
#include "fE_dobledisp.hpp"
#include "contador.hpp"

template <class CLAVE>

class TablaHash_t
{
  private:
    int nCeldas_;
    int nBlock_;
    Celda_t<CLAVE> **Celda;
    fDispersion<CLAVE> *h;
    fExploracion<CLAVE> *g;

  public:
    TablaHash_t(int c, int b, int d, int e) : nCeldas_(c), nBlock_(b)
    {
        Celda = new Celda_t<CLAVE>*[nCeldas_];
        for (int i = 0; i < nCeldas_; i++)
        {
            Celda[i] = new Celda_t<CLAVE>(nBlock_);
        }
        switch (d)
        {
        case 1:
            h = new fD_suma<CLAVE>(c);
            break;
        case 2:
            h = new fD_aleatoria<CLAVE>(c);
            break;
        case 3:
            h = new fD_modulo<CLAVE>(c);
            break;
        default:
            h = new fD_suma<CLAVE>(c);
        }

        switch (e)
        {
        case 1:
            g = new fE_lineal<CLAVE>(c, h);
            break;
        case 2:
            g = new fE_cuadratica<CLAVE>(c, h);
            break;
        case 3:
            g = new fE_doble<CLAVE>(c, h);
            break;
        case 4:
            g = new fE_redisp<CLAVE>(c, h);
            break;
        default:
            g = new fE_lineal<CLAVE>(c, h);
        }
    }

    ~TablaHash_t()
    {
        if (Celda != NULL)
        {
            delete[] Celda;
            Celda = NULL;
        }
    }

    bool search(CLAVE k) const
    {
        bool found = false;
        int pos = h->dispersion(k);

        if (!Celda[pos]->search(k))
        {
            int i = 1;
            while (!found && i < nCeldas_)
            {
                pos = (*g).exploracion(k, i);
                found = Celda[pos]->search(k);
                i++;
            }
            return found;
        }
        else
        {
            return true;
        }
    }

    bool insertk(CLAVE k)
    {

        bool found = false;
        int pos = (*h).dispersion(k);

        if (Celda[pos]->insertk(k))
        {
            int i = 1;
            while (!found && i < nCeldas_)
            {
                pos = g->exploracion(k, i);
                found = Celda[pos]->insertk(k);
                i++;
            }
            return found;
        }

        else
        {
            return true;
        }
    }

    std::ostream &operator<<(std::ostream &os)
    {
        for (int i = 0; i < nCeldas_; i++)
        {
            os << Celda[i] << std::endl;
        }
        return os;
    }
};
