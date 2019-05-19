#include "contador.hpp"
#include <iostream>

Contador::Contador()
{
}

Contador::~Contador() {}

void Contador::reset()
{
    min = MAX;
    max = -1;
    media = 0;
    acumulador = 0;
    test = 0;
    cuenta = 0;
}

void Contador::start()
{
    cuenta = 0;
}

void Contador::end()
{
    if (cuenta < min)
        min = cuenta;
    if (cuenta > max)
        max = cuenta;
    acumulador += cuenta;
    test++;
}

void Contador::show()
{
    media = acumulador / test;
    // std::cout << "Acumulador: " << acumulador << std::endl;
    // std::cout << "Mínimo: " << min << std::endl;
    // std::cout << "Máximo: " << max << std::endl;
    // std::cout << "Media: " << media << std::endl;
    // std::cout << "Test: " << test << std::endl;
    std::cout << "\t" << min << "\t" << media << "\t" << max << "\t\t" << acumulador << "\n";
}

Contador Contador::operator++(int)
{
    cuenta++;
    return (*this);
}
