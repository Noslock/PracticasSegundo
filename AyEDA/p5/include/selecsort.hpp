#include "sort.hpp"

template <class CLAVE>
class selecsort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n)
    {

        for (int j = 0; j < n; j++)
        {
            std::cout << A[j] << " | ";
        }
        selecciona(A, n);
        std::cout << "\n\n";
    }

    void selecciona(CLAVE *A, int n)
    {
        int min;
        int x;
        for (int i = 0; i < n; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (A[j] < A[min])
                    min = j;
            }
            x = A[min];
            A[min] = A[i];
            A[i] = x;
        }
    }
};