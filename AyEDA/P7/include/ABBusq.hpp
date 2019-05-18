#pragma once

#include "Node.hpp"
#include "ArbBin.hpp"
#include "contador.hpp"

template <class T>
class ArbolBB : public AB<T>
{
public:
  void insertNode(const T &N)
  {
    if (!searchNode(N))
    insertBranch(N, (*this).get_root());
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
        deleteBranch(N, (*this).get_root());
      }
  }

private:
  bool insertBranch(const T &clave, NodeB<T> *&NP)
  {
    if (NP == NULL)
    {
      NP = new NodeB<T>(clave);
      return true;
    }
    else if (clave < (*NP).get_data())
    {
      clave == NP->get_data();
      return insertBranch(clave, (*NP).get_izq());
    }
    else
    {
      clave == NP->get_data();
      return insertBranch(clave, (*NP).get_der());
    }
  }

  bool searchBranch(const T &N, NodeB<T> *&NP)
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

  void deleteBranch(T &N, NodeB<T> *&NP)
  {

    if (N < (*NP).get_data())
      return deleteBranch(N, (*NP).get_izq());
    else if (N > (*NP).get_data())
      return deleteBranch(N, (*NP).get_der());
    else
    {
      //clave_dada == nodo- > clave
      NodeB<T> *Eliminado = NP;
      if ((*NP).get_der() == NULL)
        NP = (*NP).get_izq();
      else if ((*NP).get_izq() == NULL)
        NP = (*NP).get_der();
      else
        substitute(Eliminado, (*NP).get_izq());
      delete Eliminado;
    }
  }

  void substitute(NodeB<T> *&eliminado, NodeB<T> *&sust)
  {
    if ((*sust).get_der() != NULL)
      substitute(eliminado, (*sust).get_der());
    else
    {
      (*eliminado).set_data((*sust).get_data());
      eliminado = sust;
      sust = (*sust).get_izq();
    }
  }
};
