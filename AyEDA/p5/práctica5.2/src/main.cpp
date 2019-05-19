#include <iostream>
#include <cstdlib>
#include <time.h>
#include "DNI.hpp"
#include "contador.hpp"
#include "selecsort.hpp"
#include "sort.hpp"
#include "shakersort.hpp"
#include "heapsort.hpp"
#include "mergesort.hpp"
#include "shellsort.hpp"

int Contador::min = MAX;
int Contador::max = -1;
int Contador::cuenta = 0;
int Contador::test = 0;
int Contador::acumulador = 0;
int Contador::media = 0;

void modoprueba(char *modo, char *tamb, char *metod, char *seed);

void modoestadist(char *modo, char *tamb, char *npruebas, char *seed);

int main(int argc, char *argv[])
{
    system("clear");
    if (argc == 5)
    {
        std::cout << "--- PRÁCTICA 5: MÉTODOS DE ORDENACIÓN ---" << std::endl
                  << std::endl;
        if (argc == 5)
        {
            modoprueba(argv[1], argv[2], argv[3], argv[4]);
        }
        else if (argc == 6)
        {
            modoestadist(argv[1], argv[2], argv[3], argv[4]);
        }
    }
    else
    {
        std::cout << "El número de argumentos es incorrecto. Ha de introducir el modo, el tamaño del banco, el método de ordenación (modo demostración) o el número de pruebas(modo estadísitca) y la semilla de generación.\n";
    }
}

void modoprueba(char *modo, char *tamb, char *metod, char *seed)
{
    if (*modo != '1')
    {
        int a = atoi(seed);
        srand(a);
        int b = atoi(tamb);
        DNI banco[b];
        sort<DNI> *A;
        switch (*metod)
        {
        case '1':
            A = new selecsort<DNI>;
            break;
        case '2':
            A = new shakersort<DNI>;
            break;
        case '3':
            A = new heapsort<DNI>;
            break;
        case '4':
            A = new mergesort<DNI>;
            break;
        case '5':
            A = new shellsort<DNI>;
            break;
        default:
            A = new selecsort<DNI>;
            break;
        }
        (*A).sorting(banco, b, modo);
    }
    else
    {
        modoestadist(modo, tamb, metod, seed);
    }
}

void modoestadist(char *modo, char *tamb, char *npruebas, char *seed)
{
    if (*modo == '1')
    {
        static Contador c1;
        int a = atoi(seed);
        int b = atoi(tamb);
        int c = atoi(npruebas);

        sort<DNI> *A[5];

        A[0] = new selecsort<DNI>;

        A[1] = new shakersort<DNI>;

        A[2] = new heapsort<DNI>;

        A[3] = new mergesort<DNI>;

        A[4] = new shellsort<DNI>;

        std::string tipo;

        std::cout << "\n--NÚMERO DE COMPARACIONES--\n\n";

        std::cout << "Número de elementos por banco: " << tamb << "\nNúmero de bancos creados: " << npruebas << "\n\n";
        
        std::cout << "TipoSort\tMínimo\tMedia\tMáximo\tTotalComparaciones\n\n";

        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                tipo = "Selec";
                break;
            case 1:
                tipo = "Shaker";
                break;
            case 2:
                tipo = "Heap";
                break;
            case 3:
                tipo = "Merge";
                break;
            case 4:
                tipo = "Shell";
                break;
            }
            std::cout << "\n" << tipo << ":\t";
            for (int j = 0; j < c; j++)
            {
                c1.start();
                srand(a + j);
                DNI banco[b];
                (*A[i]).sorting(banco, b, modo);
                c1.end();
            }
            c1.show();
            c1.reset();
        }
    }
    else
    {
        modoprueba(modo, tamb, npruebas, seed);
    }
}
