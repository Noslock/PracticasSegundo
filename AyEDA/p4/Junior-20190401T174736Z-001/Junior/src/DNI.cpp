#include "../include/DNI.hpp"

DNI::DNI() : numero(0)
{
}

DNI::DNI(int num) : numero(num)
{
}

DNI::DNI(DNI &dni) : numero(dni.numero)
{
}

DNI::~DNI()
{
}

bool DNI::operator==(const DNI &dni)
{
    return (numero == dni.numero);
}

int DNI::operator%(int n)
{
    return numero % n;
}

bool DNI::operator>(DNI& dni)
{
    return (numero > dni.numero);
}