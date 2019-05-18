#pragma once

#include <queue>
#include "Node.hpp"
#include "NodeAVL.hpp"

template <class T>
class AB
{
private:
  NodeAVL<T> *root;

public:
  AB() : root(NULL)
  {
  }

  ~AB()
  {
    trim(root);
  }

  bool isLeaf(const NodeAVL<T> *&nodo)
  {
    return (((*nodo).get_izq() == NULL) && (((*nodo).get_der() == NULL)));
  }

  bool empty()
  {
    if (root == NULL)
      return true;
    else
      return false;
  }

  void set_root(const T &N)
  {
    root = new NodeAVL<T>(N);
  }

  int sizeBranch(const NodeAVL<T> *&nodo) const
  {
    if (nodo == NULL)
      return 0;
    return (1 + sizeBranch((*nodo).get_izq()) + sizeBranch((*nodo).get_der()));
  }

  int sizeTree() const
  {
    return sizeBranch(root);
  }

  int heightMax() 
  {
    return height(get_root());
  }

  int height(NodeAVL<T> *&nodo)
  {
    if (nodo == NULL)
      return 0;
    int alt_i = height((*nodo).get_izq());

    int alt_d = height((*nodo).get_der());

    if (alt_d > alt_i)
      return ++alt_d;
    else
      return ++alt_i;
  }

  virtual void insertNode(const T &N) = 0;

  virtual bool searchNode(const T &N) = 0;

  virtual void deleteNode(T &N) = 0;

  // void inorden(const NodeAVL<T> *nodo)
  // {
  //   if (nodo == NULL)
  //     return;
  //   inorden(nodo->get_izq());
  //   //procesa(nodo->get_data());
  //   inorden(nodo->get_der());
  // }

  NodeAVL<T> *&get_root(void) 
  {
    return root;
  }

  void recorreN(NodeAVL<T> *&N, std::ostream &os)
  {
    std::queue<std::pair<NodeAVL<T> *, int>> Q;
    NodeAVL<T> *aux;
    std::pair<NodeAVL<T> *, int> par;
    int level, current_level = 0;
    par.first = N;
    par.second = 0;
    Q.push(par);
    std::cout << current_level << ": ";
    while (!Q.empty())
    {
      par = Q.front();
      Q.pop();
      aux = par.first;
      level = par.second;
      if (level > current_level)
      {
        current_level = level;
        std::cout << std::endl;
        std::cout << current_level << ": ";
      } //Incremento de nivel
      if (aux != NULL)
      {
        os << "[ " << (*aux) << " ]\t";
        par.first = aux->get_izq();
        par.second = level + 1;
        Q.push(par);
        par.first = aux->get_der();
        Q.push(par);
      }
      else
      { //Subarbol vacío}
        os << "[.]";
      }
    }
    std::cout << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, AB<T> &arbol)
  {
    // os << node.get_data();
    // return os;
    arbol.recorreN(arbol.get_root(), os);
    return os;
  }

private:
  void trim(NodeAVL<T> *&nodo)
  {
    if (nodo == NULL)
      return;
    trim((*nodo).get_izq()); // Podar subarbol izquierdo
    trim((*nodo).get_der()); // Podar subarbol derecho
    delete nodo;             // Eliminar nodo
    nodo = NULL;
  }
};
