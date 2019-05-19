#include "NumberBase.hpp"
#include "except.hpp"

NumberBase::NumberBase(int B, int N) : N_(), B_()
{
    if (B > 1 && N > 1)
    {
        N_ = N;
        B_ = B;
    }
    else
        throw wrong_number_excpt();
}

NumberBase::~NumberBase()
{
}

std::ostream &operator<<(std::ostream &os, const NumberBase *n)
{

    return (n->write(os));
}