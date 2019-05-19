#include "sort.hpp"

template <class CLAVE>
class heapsort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n)
    {
        // Build heap (reAange Aay)
        for (int i = n / 2 - 1; i >= 0; i--)
            baja(A, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; i--)
        {
            // Move current root to end
            int x = A[0];
            A[0] = A[i];
            A[i] = x;

            // call max heapify on the reduced heap
            baja(A, i, 0);
        }
    }

    void baja(CLAVE *A, int n, int i)
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
            baja(A, n, largest);
        }
    }
};
