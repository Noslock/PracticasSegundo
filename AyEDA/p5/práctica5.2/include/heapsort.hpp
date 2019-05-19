#include "sort.hpp"

template <class CLAVE>
class heapsort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n, char *modo)
    {
        if (*modo != '1')
        {
            std::cout << "--- Método de ordenación por montón ---\n\n";
            heapD(A, n);
            std::cout << "--- Ordenación finalizada con éxito ---\n\n";
        }
        else
        {
            heapE(A, n);
        }
    }

    void heapD(CLAVE *A, int n)
    {
        std::cout << "\n\nInserción del montón\n\n";
        // Build heap (reAange Aay)
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            bajaD(A, n, i);
            for (int j = 0; j < n; j++)
            {
                std::cout << A[j] << " | ";
            }
            std::cout << "\n\n";
        }
        int k = 1;

        std::cout << "\n\nExtracción del montón\n\n";
        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; i--)
        {
            // Move current root to end
            int x = A[0];
            A[0] = A[i];
            A[i] = x;

            // call max heapify on the reduced heap

            bajaD(A, i, 0);
            std::cout << "\nITERACIÓN [" << k << "]:";
            std::cout << "\nParte desordenada:\n ";
            for (int j = 0; j < i; j++)
            {
                std::cout << A[j] << " | ";
            }
            std::cout << "\nParte ordenada:\n ";

            for (int j = i; j < n; j++)
            {
                std::cout << A[j] << " | ";
            }
            std::cout << "\n\n";
            k++;
        }
    }

    void bajaD(CLAVE *A, int n, int i)
    {

        int largest = i;   // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && A[l] > A[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && A[r] > A[largest])
            largest = r;

        // If largest is not root
        if (largest != i)
        {
            int x = A[i];
            A[i] = A[largest];
            A[largest] = x;

            // Recursively heapify the affected sub-tree
            bajaD(A, n, largest);
        }
    }

    void heapE(CLAVE *A, int n)
    {
        // Build heap (reAange Aay)
        for (int i = n / 2 - 1; i >= 0; i--)
            bajaE(A, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; i--)
        {
            // Move current root to end
            int x = A[0];
            A[0] = A[i];
            A[i] = x;

            // call max heapify on the reduced heap
            bajaE(A, i, 0);
        }
    }

    void bajaE(CLAVE *A, int n, int i)
    {
        Contador c1;
        int largest = i;   // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        c1++;
        // If left child is larger than root
        if (l < n && A[l] > A[largest])
        {
            largest = l;
        }

        c1++;
        // If right child is larger than largest so far
        if (r < n && A[r] > A[largest])
            largest = r;

        // If largest is not root
        if (largest != i)
        {
            c1++;
            int x = A[i];
            A[i] = A[largest];
            A[largest] = x;

            // Recursively heapify the affected sub-tree
            bajaE(A, n, largest);
        }
    }
};
