#include "sort.hpp"

template <class CLAVE>
class shellsort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n)
    {
        // Start with a big gap, then reduce the gap
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire Aay is
            // gap sorted
            for (int i = gap; i < n; i += 1)
            {
                // add a[i] to the elements that have been gap sorted
                // save a[i] in temp and make a hole at position i
                int temp = A[i];

                // shift earlier gap-sorted elements up until the correct
                // location for a[i] is found
                int j;
                for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                    A[j] = A[j - gap];

                //  put temp (the original a[i]) in its correct location
                A[j] = temp;
            }
        }
    }
};
