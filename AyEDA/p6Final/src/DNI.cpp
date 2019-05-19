#include "DNI.hpp"
#include "contador.hpp"

DNI::DNI()
{
    long int x;

    x = rand();

    for (int i = 0; i < 8; i++)
    {
        DNI_[i] = x % 10;
        x = x / 10;
    }
}

DNI::DNI(long int x)
{
    for (int i = 7; i >= 0; i--)
    {
        DNI_[i] = x % 10;
        x = x / 10;
    }
}

DNI::operator int long() const
{
    int long result = 0;
    int long number = 1;

    for (int i = 7; i >= 0; i--)
    {
        result += DNI_[i] * number;
        number = number * 10;
    }

    return result;
}

bool DNI::operator==(DNI D) const
{
    Contador c1;
    c1++;
    long int n1, n2;
    n1 = (*this);
    n2 = D;
    if (n1 == n2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DNI::operator=(DNI D)
{
    Contador c1;
    c1++;
    for (int i = 0; i < 8; i++)
    {
        (*this).DNI_[i] = D.DNI_[i];
    }
}

bool DNI::operator<(DNI D) const
{
    Contador c1;
    c1++;
    unsigned long int n1, n2;
    n1 = (*this);
    n2 = D;
    if (n1 < n2)
        return true;
    else
        return false;
}

int DNI::get_dig(int i) const
{
    return DNI_[i];
}

// int DNI::operator[](int n)
// {
//     return get_dig(n);
// }

std::ostream &operator<<(std::ostream &os, const DNI d)
{
    for (int i = 0; i < 8; i++)
    {
        os << d.get_dig(i);
    }
    return os;
}