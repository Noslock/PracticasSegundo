#include <iostream>
#include <cstdlib>
#include <time.h>
#include "ABBusq.hpp"
#include "Node.hpp"
#include "ABBusq.hpp"
#include "ABBusqP.hpp"
#include "DNI.hpp"
#include "contador.hpp"

int Contador::min = MAX;
int Contador::max = -1;
int Contador::cuenta = 0;
int Contador::test = 0;
int Contador::acumulador = 0;
int Contador::media = 0;

void modoprueba(int m);

void modoestadist(int m, int b, int c, int a);

int main(int argc, char *argv[])
{
    system("clear");
    if (argc == 2 || argc == 5)
    {
        std::cout << "--- PRÁCTICA 6: ÁRBOL BINARIO DE BÚSQUEDA ---" << std::endl
                  << std::endl;
        if (argc == 2)
        {
          int m = atoi(argv[1]);
          modoprueba(m);
        }
        else if (argc == 5)
        {
          int m = atoi(argv[1]);
          int a = atoi(argv[4]);
          int b = atoi(argv[2]);
          int c = atoi(argv[3]);
          modoestadist(m, b, c, a);
        }
    }
    else
    {
        std::cout << "El número de argumentos es incorrecto. Ha de introducir el modo, y en caso de querer usar el modo estadística, el tamaño del banco, el número de pruebas y la semilla de generación.\n";
    }
}

void modoprueba(int modo)
{
    if (modo != 1)
    {
        std::cout << "Introduzca una opción para probar el funcionamiento del árbol binario de búsqueda:" << std::endl;
        ArbolBBP<int> T;
        int opcion = 8, intr;
        while (opcion != 0)
        {
            std::cout << "[0] Salir." << std::endl
                      << "[1] Introducir entero al árbol." << std::endl
                      << "[2] Eliminar entero del árbol." << std::endl
                      << "Opción: ";
            std::cin >> opcion;
            switch (opcion)
            {
            case 0:
                break;
            case 1:
                std::cout << "Introduzca el entero que quiera insertar: ";
                std::cin >> intr;
                T.insertNode(intr);
                break;
            case 2:
                std::cout << "Introduzca el entero a extraer: ";
                std::cin >> intr;
                T.deleteNode(intr);
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
            }
            if (opcion != 0)
                std::cout << T << std::endl;
        }
    }
    else
    {
        modoestadist(modo, 50, 10, 0);
    }
}

void modoestadist(int modo, int b, int c, int a)
{
    if (modo == 1)
    {

        // if (b > c)
        // {

        ArbolBB<DNI> T;

        srand(a);

        DNI banco[2 * b];

        for (int i = 0; i < b; i++)
        {
            T.insertNode(banco[i]);
        }

        Contador c1;

        std::cout << "\n--NÚMERO DE COMPARACIONES: BÚSQUEDA--\n\n";

        std::cout << "Número de elementos del arbol: " << b << "\nNúmero de elementos que se buscarán: " << c << "\n\n";

        c1.reset();


        for (int i = b; i < b + c; i++)
        {
                          c1.start();
            T.searchNode(banco[i]);
            c1.end();
        }

        std::cout << "\tMínimo\tMedia\tMáximo\tTotalComparaciones\n\n";
        c1.show();
        c1.reset();

        std::cout << "\n--NÚMERO DE COMPARACIONES: INSERCIÓN --\n\n";

        std::cout << "Número de elementos del arbol: " << b << "\nNúmero de elementos que se buscarán: " << c << "\n\n";

        for (int i = b ; i < b + c; i++)
        {
                                    c1.start();
            T.insertNode(banco[i]);
            c1.end();
        }

        std::cout << "\tMínimo\tMedia\tMáximo\tTotalComparaciones\n\n";
        c1.show();
        c1.reset();

        // else
        // {
        //     std::cout << "No se pueden "
        // }
    }
    else
    {
        modoprueba(0);
    }
}

// C.insertNode(A[0]);
// C.insertNode(A[1]);
// C.insertNode(A[2]);
// C.insertNode(A[3]);
// C.insertNode(A[4]);
// std::cout << C << std::endl;
// C.deleteNode(A[3]);
// C.deleteNode(A[2]);
// //tam = C.heightMax();
// // C.deleteNode(A);

// // C.insertNode(D);
// // C.insertNode(E);
// std::cout << C << std::endl;
// C.insertNode(A[2]);
// //int tam = C.heightMax();
// std::cout << C << std::endl;
