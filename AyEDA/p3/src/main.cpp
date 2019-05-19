#include <iostream>
#include "MyNumbers.hpp"
#include "except.hpp"

void TestNumber()
{

    NumberBase *p1, *p2, *r;
    int opc, v1, v2;
    std::cout << "Introduzca la base en la que quiera trabajar (2, 8, 16 o 10 por defecto): ";
    std::cin >> opc;
    std::cout << "Introduzca el valor del primer número: ";
    std::cin >> v1;
    std::cout << "Introduzca el valor del segundo número: ";
    std::cin >> v2;
    switch (opc)
    {
    case 2:
        p1 = new BinaryNumber(v1);
        p2 = new BinaryNumber(v2);
        break;
    case 8:
        p1 = new OctalNumber(v1);
        p2 = new OctalNumber(v2);
        break;
    case 16:
        p1 = new HexadecimalNumber(v1);
        p2 = new HexadecimalNumber(v2);
        break;
    default:
        p1 = new DecimalNumber(v1);
        p2 = new DecimalNumber(v2);
        break;
    }

    std::cout << "El primer número representado en base " << opc << "es: " << std::endl
              << p1;
    std::cout << "El segundo número representado en base " << opc << "es: " << std::endl
              << p2;

    r = (*p1) + p2;

    std::cout << "La suma es igual a : " << std::endl
              << r;

    r = (*p1) - p2;

    std::cout << "La suma es igual a : " << std::endl
              << r;

    delete p1;
    delete p2;
    delete r;

}

int main()
{
    int continuar;
    try
    {

        do
        {

            TestNumber();
            std::cout << std::endl << "Introduzca 0 si no quiere volver a ejecutar el programa, introduzca cualquier otro en caso de querer continuar usándolo: ";
            std::cin >> continuar;

        } while (continuar != 0);
    }
    catch (NumberException &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
