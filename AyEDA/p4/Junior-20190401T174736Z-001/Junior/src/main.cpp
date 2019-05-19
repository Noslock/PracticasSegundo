#include <iostream>
#include <math.h>
#include "../include/TablaHash.hpp"
#include "../include/DNI.hpp"
#include "Contador.hpp"

#define eps 10E-3

int contador_t::min = 9999999999;
int contador_t::max = -1;

int main()
{
    int nCeldas = 0, nBloques = 0, opcion_h = 0, opcion_g = 0;

    fDispersion<DNI> *hx;
    fExplorar<DNI> *gx;
    static Contador contador_insertar, contador_buscar;

    std::cout << "\nIntroduzca el nº de celdas de la tabla:\n";
    std::cin >> nCeldas;

    std::cout << "Introduzca el nº de bloques por celda:\n";
    std::cin >> nBloques;

    std::cout << "Elija una función de dispersión:\n";
    std::cout << "1 - Módulo.\n";
    std::cout << "2 - Suma.\n";
    std::cout << "3 - Aleatoria.\n";
    std::cin >> opcion_h;

    std::cout << "Elija una función de exploración:\n";
    std::cout << "1 - Lineal.\n";
    std::cout << "2 - Cuadrática.\n";
    std::cout << "3 - Dispersión doble.\n";
    std::cout << "4 - Re-Dispersión.\n";
    std::cin >> opcion_g;

    switch (opcion_h)
    {
    case 1:
        hx = new fD_modulo<DNI>(nCeldas);
        break;
    case 2:
        hx = new fD_suma<DNI>(nCeldas);
        break;
    case 3:
        hx = new fD_aleatoria<DNI>(nCeldas);
        break;
    default:
        std::cerr << "\n\nMétodo de dispersión erróneo.\n";
        return 0;
        break;
    }

    switch (opcion_g)
    {
    case 1:
        gx = new fE_lineal<DNI>(nCeldas, hx);
        break;
    case 2:
        gx = new fE_cuadratica<DNI>(nCeldas, hx);
        break;
    case 3:
        gx = new fE_doble<DNI>(nCeldas, hx);
        break;
    case 4:
        gx = new fE_redisp<DNI>(nCeldas, hx);
        break;
    default:
        std::cerr << "\n\nMétodo de exploración erróneo.\n";
        return 0;
        break;
    }

    TablaHash<DNI> *Hashing = new TablaHash<DNI>(nCeldas, nBloques, hx, gx);

    int nPruebas = 0, N = 0;
    double factor1 = 0.0, factor2 = 0.0;

    std::cout << "\nIntroduzca el factor un factor de carga entre 0 y 1:\n";
    std::cin >> factor1;
    while (factor1 < 0 || factor1 > 1)
    {
        std::cerr << "\nEl factor de carga tiene que estar entre 0 y 1.\n";
        std::cin >> factor1;
    }

    std::cout << "\nIntroduzca el nº de pruebas a realizar:\n";
    std::cin >> nPruebas;

    N = 2 * (factor1 * nCeldas * nBloques);

    srand(time(NULL));
    DNI *banco = new DNI[N];
    for (int i = 0; i < N; i++)
        banco[i] = (rand() % 1000000 + 99999999);

    int i = 0, x = 0;

    while ((Hashing->insertar(banco[i])) && (fabs(factor2 - factor1) > eps))
    {
        i++;
        factor2 = (double(i) / double(nCeldas * nBloques));
    }

    i = 0;
    while (i < nPruebas)
    {
        x = rand() % N;

        contador_buscar.start();
        if (Hashing->buscar(banco[x]))
            i++;

        contador_buscar.end();
    }

    i = 0;
    while (i < nPruebas)
    {
        x = rand() % N;

        contador_insertar.start();
        if (Hashing->insertar(banco[x]))
            i++;

        contador_insertar.end();
    }

    std::cout << "\nCeldas  Bloques\t\tDispersión\tExploración\tF.Carga\t\tPruebas\n";
    std::cout << nCeldas << "\t" << nBloques << "\t\t" << opcion_h << "\t\t" << opcion_g;
    std::cout << "\t\t" << factor1 << "\t\t" << nPruebas << "\n\n";

    std::cout << "\t\t\tMínimo\t\tMedio\t\tMáximo\n";
    std::cout << "Busquedas";
    contador_buscar.mostar();

    std::cout << "Inserción";
    contador_insertar.mostar();
}