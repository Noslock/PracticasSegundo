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
#define MAX 99999

int Contador::min = MAX;
int Contador::max = -1;
int Contador::cuenta = 0;
int Contador::test = 0;
int Contador::acumulador = 0;
int Contador::media = 0;

void modoprueba(char *modo, char *tamb, char *metod, char *seed);

void modoestadist(char *modo, char *tamb, char *metod, char *npruebas, char *seed);

int main(int argc, char *argv[])
{

    if (argc == 5 || argc == 6)
    {
        std::cout << "--- PRÁCTICA 5: MÉTODOS DE ORDENACIÓN ---" << std::endl
                  << std::endl;
        if (argc == 5)
        {
            modoprueba(argv[1], argv[2], argv[3], argv[4]);
        }
        else if (argc == 6)
        {
            modoestadist(argv[1], argv[2], argv[3], argv[4], argv[5]);
        }
    }
    else
    {
        std::cout << "El número de argumentos es incorrecto. Ha de introducir el modo, el tamaño del banco, el método de ordenación, el número de pruebas y la semilla de generación.\n";
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
        (*A).sorting(banco, b);
        for (int i = 0; i < b; i++)
        {
            std::cout << banco[i] << " | ";
        }
        std::cout << std::endl;
    }
    else
    {
        modoestadist(modo, tamb, metod, "5", seed);
    }
}

void modoestadist(char *modo, char *tamb, char *metod, char *npruebas, char *seed)
{
    if (*modo == '1')
    {
        int a = atoi(seed);
        srand(a);
        int b = atoi(tamb);
        int c = atoi(npruebas);
        for (int i = 0; i < c; i++)
        {
            DNI banco[b];
            DNI bancos[4][b];

            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 8; k++)
                    bancos[j][k] = banco[k];
            }

            selecsort<DNI> A;

            shakersort<DNI> B;

            heapsort<DNI> C;

            mergesort<DNI> D;

            shellsort<DNI> E;

            A.sorting(banco, b);

            B.sorting(bancos[0], b);

            C.sorting(bancos[1], b);

            D.sorting(bancos[2], b);

            E.sorting(bancos[3], b);

            for (int j = 0; j < 4; j++)
            {
                std::cout << banco[j] << " | ";
            }
            std::cout << std::endl;

            // for (int j = 0; j < 4; j++)
            // {
            //     for (int k = 0; k < b; k++)
            //     {
            //         std::cout << bancos[j] << " | ";
            //     }
            //     std::cout << std::endl;
            // }
        }
    }
    else
    {
        modoprueba(modo, tamb, metod, seed);
    }
}