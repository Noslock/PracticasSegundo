#include "sort.hpp"

template <class CLAVE>
class shakersort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n, char *modo)
    {
        if (*modo != '1')
        {
            std::cout << "--- Método de ordenación por sacudida---\n\n";
            sD(A, n);
            std::cout << "\n\n--- Ordenación finalizada con éxito ---\n\n";
        }
        else
        {
            sE(A, n);
        }
    }

    void sD(CLAVE *A, int n)
    {
        int ini = 1;
        int fin = n - 1;
        int cam = n;
        int x;
        while (ini < fin)
        {
            for (int j = fin; j >= ini; j--)
                if (A[j] < A[j - 1])
                {
                    std::cout << "La burbuja actual es: " << A[j] << "(Posición " << j + 1 << ")" << std::endl;
                    for (int i = 0; i < n; i++)
                    {
                        std::cout << A[i] << " | ";
                    }
                    std::cout << std::endl;
                    std::cout << std::endl;
                    x = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = x;
                    cam = j;
                }
            ini = cam + 1;
            for (int j = ini; j <= fin; j++)
                if (A[j] < A[j - 1])
                {
                    std::cout << "La piedra actual es: " << A[j - 1] << "(Posición " << j << ")" << std::endl;
                    for (int i = 0; i < n; i++)
                    {
                        std::cout << A[i] << " | ";
                    }
                    std::cout << std::endl;
                    std::cout << std::endl;
                    x = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = x;
                    cam = j;
                }
            fin = cam - 1;
        }
    }

    void sE(CLAVE *A, int n)
    {
        Contador c1;
        int ini = 1;
        int fin = n - 1;
        int cam = n;
        int x;
        while (ini < fin)
        {
            for (int j = fin; j >= ini; j--)
            {
                c1++;
                if (A[j] < A[j - 1])
                {
                    c1++;
                    x = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = x;
                    cam = j;
                }
            }
            ini = cam + 1;
            for (int j = ini; j <= fin; j++)
            {
                c1++;
                if (A[j] < A[j - 1])
                {
                    c1++;
                    x = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = x;
                    cam = j;
                }
            }
            fin = cam - 1;
        }
    }
};