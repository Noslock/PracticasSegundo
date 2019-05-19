#include "sort.hpp"

template <class CLAVE>
class selecsort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n, char *modo)
    {
        if (*modo != '1')
        {
            std::cout << "--- Método de ordenación por selección ---\n\n";
            seleccionaD(A, n);
            std::cout << "--- Ordenación finalizada con éxito ---\n\n";
        }
        else
        {
            seleccionaE(A, n);
        }
    }

    void seleccionaD(CLAVE *A, int n)
    {
        int min;
        int x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << A[j] << " | ";
            }
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (A[j] < A[min])
                    min = j;
            }
            x = A[min];
            A[min] = A[i];
            A[i] = x;
            if (i != min)
            {
                std::cout << std::endl;
                std::cout << "Iteración[" << i + 1 << "]: Cambiamos las posiciones " << i + 1 << " y " << min + 1 << ".";
                std::cout << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "Iteración[" << i + 1 << "]: Se mantiene la posición: " << i + 1 << ".";
                std::cout << std::endl;
                std::cout << std::endl;
            }
        }
    }

    void seleccionaE(CLAVE *A, int n)
    {
        Contador c1;
        int min;
        int x;
        for (int i = 0; i < n; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                c1++;
                if (A[j] < A[min])
                {
                    c1++;
                    min = j;
                }
            }
            x = A[min];
            A[min] = A[i];
            A[i] = x;
        }
    }
};