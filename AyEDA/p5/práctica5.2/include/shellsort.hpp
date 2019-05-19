#include "sort.hpp"

template <class CLAVE>
class shellsort : public sort<CLAVE>
{
  public:
    void sorting(CLAVE *A, int n, char *modo)
    {
        if (*modo != '1')
        {
            std::cout << "--- Método de ordenación por montón ---\n\n";
            shellD(A, n);
            std::cout << "--- Ordenación finalizada con éxito ---\n\n";
        }
        else
        {
            shellE(A, n);
        }
    }

    void shellD(CLAVE *A, int n)
    {
        float alf;
        while (!(alf > 0 && alf < 1))
        {
            std::cout << "\nIntroduzca un valor para alfa (entre 0 y 1): ";
            std::cin >> alf;
        }
        std::cout << "Vector original:\n\n";
        for (int K = 0; K < n; K++)
        {
            std::cout << A[K] << " | ";
        }
        std::cout << "\n\n";
        // Start with a big gap, then reduce the gap
        for (int gap = n * alf; gap > 0; gap *= alf)
        {
            std::cout << "Ordenación con saltos de tamaño " << gap << ":\n\n";
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire Aay is
            // gap sorted

            for (int i = gap; i < n; i++)
            {

                // add a[i] to the elements that have been gap sorted
                // save a[i] in temp and make a hole at position i
                int temp = A[i];

                // shift earlier gap-sorted elements up until the correct
                // location for a[i] is found
                int j;

                for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                {
                    //y = 0;
                    std::cout << "Cambian las posiciones " << j + 1 << " y " << j - gap + 1 << "(" << A[j] << " y " << A[j - gap] << ").\n";
                    //A[j - gap];
                    A[j] = A[j - gap];
                    for (int K = 0; K < n; K++)
                    {
                        if (K == j - gap)
                            std::cout << temp << " | ";
                        else
                            std::cout << A[K] << " | ";
                    }

                    std::cout << "\n\n";
                }

                //  put temp (the original a[i]) in its correct location
                A[j] = temp;
            }
        }
    }

    void shellE(CLAVE *A, int n)
    {
        Contador c1;
        float alf = 0.4545;

        // Start with a big gap, then reduce the gap
        for (int gap = n * alf; gap > 0; gap *= alf)
        {
            c1++;
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire Aay is
            // gap sorted
            for (int i = gap; i < n; i += 1)
            {
                c1++;
                // add a[i] to the elements that have been gap sorted
                // save a[i] in temp and make a hole at position i
                int temp = A[i];

                // shift earlier gap-sorted elements up until the correct
                // location for a[i] is found
                int j;
                for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                {
                    c1++;
                    A[j] = A[j - gap];
                }

                //  put temp (the original a[i]) in its correct location
                A[j] = temp;
            }
        }
    }
};
