#include <iostream>
#include <cstdlib>
#include <time.h>
#include "tablahash.hpp"
#include "contador.hpp"
#include "DNI.hpp"
#define MAX 99999


int Contador::min = MAX;
int Contador::max = -1;
int Contador::cuenta = 0;
int Contador::test = 0;
int Contador::acumulador = 0;
int Contador::media = 0 ;

int main()
{
    static Contador A, B;
    std::cout << "--- PRÁCTICA 4: TABLA HASH ---" << std::endl
              << std::endl;

    int celdas, bloques, N, opcd, opcf, npruebas;
    float factor;

    std::cout << "Introduzca el número de celdas de su tabla: ";
    std::cin >> celdas;
    std::cout << "Introduzca el número de bloques de cada celda: ";
    std::cin >> bloques;
    std::cout << "Introduzca el factor de carga de la tabla (Valor flotante entre 0 y 1): ";
    std::cin >> factor;
    N = factor * celdas * bloques;
    std::cout << "Introduzca el valor correspondiente a la función de dispersión que quiera usar:\n1)Suma(Por defecto).\n2)Aleatoria.\n3)Módulo.\n\nFunción: ";
    std::cin >> opcd;
    std::cout << "Introduzca el valor correspondiente a la función de exploración que quiera usar:\n1)Lineal(Por defecto).";
    std::cout << "\n2)Cuadrática.\n3)Disp.Doble.\n4)Redispersión.\n\nFunción: ";
    std::cin >> opcf;
    std::cout << "Introduzca el número de pruebas a realizar: ";
    std::cin >> npruebas;
    DNI banco[2 * N];
    srand(time(NULL));
    for (int i = 0; i < 2 * N; i++)
        banco[i] = DNI();
    TablaHash_t<DNI> T(celdas, bloques, opcd, opcf);

    for (int i = 0; i < N; i++)
    {
        A.start();
        T.insertk(banco[i]);
        A.end();
    }
    for (int i = N; i < 2 * N; i++)
    {
        B.start();
        T.search(banco[i]);
        B.end();
    }
}
