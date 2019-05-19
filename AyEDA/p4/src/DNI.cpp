#include "DNI.hpp"

DNI::DNI()
{
    unsigned long int x;

    x = rand();

    for (int i = 0; i < 8; i++)
    {
        DNI_[i] = x % 10;
        x = x / 10;
    }
}

DNI::operator int long() const
{
    unsigned int long result = 0;
    unsigned int long number = 1;

    for (int i = 7; i <= 0; i--)
    {
        result += DNI_[i] * number;
        number = number * 10;
    }

    return result;
}

bool DNI::operator==(DNI D)
{
    unsigned long int n1, n2;
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
bool DNI::operator<(DNI D)
{
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

std::ostream &operator<<(std::ostream &os, const DNI d)
{
    for (int i = 0; i < 8; i++)
    {
        os << d.get_dig(i);
    }
    os << std::endl;
    return os;
}