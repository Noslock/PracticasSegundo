#include "Contador.hpp"

Contador::Contador()
{
    reset();
}

Contador::~Contador()
{
}

void Contador::reset()
{
    minimo = MAX;
    media = 0;
    maximo = 0;
    acumulador = 0;
}

void Contador::start()
{
}

void Contador::end()
{
}

void Contador::mostar()
{
}

int Contador::operator++()
{
    return acumulador++;
}