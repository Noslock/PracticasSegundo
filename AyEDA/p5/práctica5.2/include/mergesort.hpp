#include "sort.hpp"

template <class CLAVE>
class mergesort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n, char *modo)
    {
        if (*modo != '1')
        {
            std::cout << "--- Método de ordenación por mezcla ---\n\n";
            MsortD(A, 0, n);
            std::cout << "--- Ordenación finalizada con éxito ---\n\n";
        }
        else
        {
            MsortE(A, 0, n);
        }
    }

    void MsortD(CLAVE *A, int ini, int fin)
    {
        if (ini < fin)
        {
            std::cout << "Parte desordenada:\n";
            for (int j = ini; j < fin; j++)
            {
                std::cout << A[j] << " | ";
            }
            std::cout << "\n";
            std::cout << std::endl;
            int cen = ini + (fin - ini) / 2;
            MsortD(A, ini, cen);
            MsortD(A, cen + 1, fin);
            Mezcla(A, ini, cen, fin);
            std::cout << "Parte ordenada:\n";
            for (int j = ini; j < fin; j++)
            {
                std::cout << A[j] << " | ";
            }
            std::cout << "\n\n";
        }
    }

    void MsortE(CLAVE *A, int ini, int fin)
    {
        if (ini < fin)
        {
            int cen = ini + (fin - ini) / 2;
            MsortE(A, ini, cen);
            MsortE(A, cen + 1, fin);
            Mezcla(A, ini, cen, fin);
        }
    }

    void Mezcla(CLAVE *A, int l, int m, int r)
    {
        Contador c1;
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        /* create temp arrays */
        DNI L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
        {
            c1++;
            L[i] = A[l + i];
        }
        for (j = 0; j < n2; j++)
        {
            c1++;
            R[j] = A[m + 1 + j];
        }

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            c1++;
            if (L[i] <= R[j])
            {
                A[k] = L[i];
                i++;
            }
            else
            {
                A[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there 
       are any */
        while (i < n1)
        {
            c1++;
            A[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there 
       are any */
        while (j < n2)
        {
            c1++;
            A[k] = R[j];
            j++;
            k++;
        }
    }
};
