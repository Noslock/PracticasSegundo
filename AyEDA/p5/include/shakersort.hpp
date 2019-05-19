#include "sort.hpp"

template <class CLAVE>
class shakersort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n)
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
                    x = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = x;
                    cam = j;
                }
            ini = cam + 1;
            for (int j = ini; j <= fin; j++)
                if (A[j] < A[j - 1])
                {
                    x = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = x;
                    cam = j;
                }
            fin = cam - 1;
        }
    }
};