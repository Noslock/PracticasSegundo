#include <iostream>
#include "except.hpp"
#include <cmath>
#include "NumberBase.hpp"

template <size_t N, size_t B, class T = char>
class Number : public NumberBase
{
  private:
    T *digito;
    int signo;

  public:
    Number(int n = 0);

    Number(const Number &n2);

    ~Number();

    std::ostream &write(std::ostream &os) const;

    void operator=(const Number &n2);

    Number operator+(const Number &n2) const;

    NumberBase *operator+(const NumberBase *n) const;

    Number operator-(const Number &n2) const;

    NumberBase *operator-(const NumberBase *n) const;

    void operator++(void);

    bool operator==(const Number &n2) const;

    bool operator!=(const Number &n2) const;

    bool operator<(const Number &n2) const;

    bool operator>(const Number &n2) const;

    void set_digito(int i, T a) const;

    // operator Number<N + 1, B, T>() const;

    NumberBase *duplicate() const;

  private:
    void to_base(int n);

    Number suma(const Number &n2) const;

    Number resta(const Number &n2) const;

    bool absmayor(const Number &n2) const;

    bool absmenor(const Number &n2) const;

    char reVal(int num) const;

    int val(char c) const;
};

//Crear constructor de copia

template <size_t N, size_t B, class T>
Number<N, B, T>::Number(int n) : NumberBase(N, B), digito(0), signo(0)
{
    if (0 < B && B <= 16)
    {
        digito = new (std::nothrow) T[N];
        if (digito == nullptr)
        {
            throw memory_excpt();
        }
        signo = (n < 0) ? -1 : 1;
        n *= signo;
        to_base(n);
    }
    else
    {
        throw base_excpt();
    }
}

template <size_t N, size_t B, class T>
Number<N, B, T>::Number(const Number<N, B, T> &n2) : NumberBase(N, B), digito(0), signo(0)
{
    digito = new (std::nothrow) T[N];
    if (digito == nullptr)
    {
        throw memory_excpt();
    }
    (*this) = n2;
}

template <size_t N, size_t B, class T>
Number<N, B, T>::~Number()
{
    if (digito != NULL)
    {
        delete[] digito;
    }
    /*else
        throw pointer_excpt();*/
}

template <size_t N, size_t B, class T>
void Number<N, B, T>::to_base(int n)
{
    int resto;
    T a;
    for (unsigned i = 0; i < N; ++i)
    {
        resto = n % B;

        n = n / B;

        a = reVal(resto);

        digito[i] = a;
    }
    if (n > 0)
    {
        throw range_excpt();
    }
}

template <size_t N, size_t B, class T>
std::ostream &Number<N, B, T>::write(std::ostream &os) const
{
    os << ((signo < 0) ? '-' : '+') << " ";

    for (int i = N - 1; i >= 0; i--)
    {
        os << digito[i] << " ";
    }
    os << std::endl;
    return os;
}

//Adaptar las operaciones para el signo
template <size_t N, size_t B, class T>
void Number<N, B, T>::operator=(const Number<N, B, T> &n2)
{
    signo = n2.signo;
    for (unsigned i = 0; i < N; i++)
    {
        digito[i] = n2.digito[i];
    }
}

template <size_t N, size_t B, class T>
Number<N, B, T> Number<N, B, T>::operator+(const Number<N, B, T> &n2) const
{
    Number<N, B, T> nr;
    if (signo == n2.signo)
    {
        nr = (*this).suma(n2);
        nr.signo = signo;
    }
    else
    {
        if ((*this).absmayor(n2))
        {
            nr = (*this).resta(n2);
            nr.signo = signo;
        }
        else
        {
            nr = n2.resta((*this));
            nr.signo = n2.signo;
        }
    }
    return nr;
}
template <size_t N, size_t B, class T>
NumberBase *Number<N, B, T>::operator+(const NumberBase *n) const
{
    const Number<N, B, T> *S = dynamic_cast<const Number<N, B, T> *>(n);
    Number<N, B, T> *r = dynamic_cast<Number<N,B,T>*>(duplicate());
    (*r) = (*this) + (*S);
    return r;
}

template <size_t N, size_t B, class T>
Number<N, B, T> Number<N, B, T>::operator-(const Number<N, B, T> &n2) const
{
    Number<N, B, T> nr(0);
    if (signo == n2.signo)
    {
        if ((*this) > n2 || (*this) == n2)
        {
            nr = (*this).resta(n2);
            nr.signo = signo;
        }
        else
        {
            nr = n2.resta((*this));
            nr.signo = -1 * n2.signo;
        }
    }
    else if (signo == -1)
    {
        if ((*this).absmayor(n2))
        {
            nr = (*this).suma(n2);
            nr.signo = signo;
        }
        else
        {
            nr = n2.suma((*this));
            nr.signo = signo;
        }
    }
    else
    {
        if ((*this).absmayor(n2))
        {
            nr = (*this).suma(n2);
            nr.signo = signo;
        }
        else
        {
            nr = n2.suma((*this));
            nr.signo = signo;
        }
    }
    return nr;
}

template <size_t N, size_t B, class T>
NumberBase *Number<N, B, T>::operator-(const NumberBase *n) const
{
    const Number<N, B, T> *S = dynamic_cast<const Number<N, B, T> *>(n);
    Number<N, B, T> *r = dynamic_cast<Number<N,B,T>*>(duplicate());
    (*r) = (*this) - (*S);
    return r;
}

template <size_t N, size_t B, class T>
NumberBase *Number<N, B, T>::duplicate() const
{
    return (new Number<N, B, T>);
}

template <size_t N, size_t B, class T>
Number<N, B, T> Number<N, B, T>::suma(const Number<N, B, T> &n2) const
{
    Number<N, B, T> nr;
    int carry = 0;
    int suma, modul;
    char a;

    for (unsigned i = 0; i < N; i++)
    {
        suma = val(digito[i]) + val(n2.digito[i]) + carry;
        modul = suma % B;
        carry = suma / B;
        a = reVal(modul);
        nr.digito[i] = a;
    }
    if (carry)
    {
        /*  Number<N+1, B, T> n1;
        Number<N+1, B, T> n1, n3, n4;
        n1 = (Number<N+1, B, T>) (*this);
        n3 = (Number<N+1, B, T>) n2;
        n4.digito[N] = 1;
        n4 = n1 + n3;
        n4.write(std::cout);
        throw overflow_excpt();
        for (unsigned i = 0; i < N; i++)
        {
          n1.set_digito(i, nr.digito[i]);
        }
        n1.set_digito(N, '1');
        n1.write(std::cout);*/
        throw overflow_excpt();
    }

    return nr;
}

/*template <size_t N, size_t B, class T>
Number<N, B, T>::operator Number<N+1, B, T>() const
{
  Number<N+1, B, T> n1;
  for (unsigned i = N-1; i >= 0; i--)
  {
    n1.digito[i] = digito[i];
  }
  n1.digito[0] = 0;
  return n1;
}*/

template <size_t N, size_t B, class T>
Number<N, B, T> Number<N, B, T>::resta(const Number<N, B, T> &n2) const
{
    Number<N, B, T> nr;
    int carry = 0;
    int parc;
    char a;

    for (unsigned i = 0; i < N; i++)
    {
        if (val(digito[i]) < val(n2.digito[i]) + carry)
        {
            parc = val(digito[i]) + B - val(n2.digito[i]) - carry;
            carry = 1;
        }
        else
        {
            parc = val(digito[i]) - carry - val(n2.digito[i]);
            carry = 0;
        }
        a = reVal(parc);
        nr.digito[i] = a;
    }
    if (carry)
    {
        throw overflow_excpt();
    }

    return nr;
}

template <size_t N, size_t B, class T>
void Number<N, B, T>::set_digito(int i, T a) const
{
    digito[i] = a;
}

template <size_t N, size_t B, class T>
void Number<N, B, T>::operator++(void)
{
    Number<N, B, T> dummy(1);
    (*this) = (*this) + dummy;
}

template <size_t N, size_t B, class T>
bool Number<N, B, T>::operator==(const Number<N, B, T> &n2) const
{
    if (signo != n2.signo)
        return false;

    bool iguales = true;
    for (unsigned i = 0; i < N; i++)
    {
        if (digito[i] != n2.digito[i])
        {
            iguales = false;
        }
    }
    return iguales;
}

template <size_t N, size_t B, class T>
bool Number<N, B, T>::operator!=(const Number<N, B, T> &n2) const
{
    if (signo != n2.signo)
        return true;

    bool distintos = false;

    for (unsigned i = 0; i < N; i++)
    {
        if (digito[i] != n2.digito[i])
        {
            distintos = true;
        }
    }
    return distintos;
}

template <size_t N, size_t B, class T>
bool Number<N, B, T>::absmenor(const Number<N, B, T> &n2) const
{
    if ((*this) != n2)
    {
        int i = 0;
        while (digito[N - 1 - i] == n2.digito[N - 1 - i])
        {
            i++;
        }
        if (digito[N - 1 - i] < n2.digito[N - 1 - i])
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

template <size_t N, size_t B, class T>
bool Number<N, B, T>::absmayor(const Number<N, B, T> &n2) const
{
    if ((*this) != n2)
    {
        int i = 0;
        while (digito[N - 1 - i] == n2.digito[N - 1 - i])
        {
            i++;
        }
        if (digito[N - 1 - i] > n2.digito[N - 1 - i])
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

template <size_t N, size_t B, class T>
bool Number<N, B, T>::operator<(const Number<N, B, T> &n2) const
{
    if (signo == n2.signo)
    {
        if ((*this) != n2)
        {
            int i = 0;
            while (digito[N - 1 - i] == n2.digito[N - 1 - i])
            {
                i++;
            }
            if (digito[N - 1 - i] < n2.digito[N - 1 - i])
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    else if (signo > n2.signo)
        return false;
    else
        return true;
}

template <size_t N, size_t B, class T>
bool Number<N, B, T>::operator>(const Number<N, B, T> &n2) const
{
    if (signo == n2.signo)
    {
        if ((*this) != n2)
        {
            int i = 0;
            while (digito[N - 1 - i] == n2.digito[N - 1 - i])
            {
                i++;
            }
            if (digito[N - 1 - i] > n2.digito[N - 1 - i])
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    else if (signo > n2.signo)
        return true;
    else
        return false;
}

template <size_t N, size_t B, class T>
int Number<N, B, T>::val(char c) const
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

template <size_t N, size_t B, class T>
char Number<N, B, T>::reVal(int num) const
{
    if (num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

template <size_t N, class T>
class Number<N, 2, T>: public NumberBase
{
  public:
    T *digito;

  public:
    Number(int n = 0);

    Number(const Number &n2);

    ~Number();

    std::ostream &write(std::ostream &os) const;

    void operator=(const Number &n2);

    Number operator+(const Number &n2) const;

    NumberBase *operator+(const NumberBase *n) const;

    Number operator-(const Number &n2) const;

    NumberBase *operator-(const NumberBase *n) const;

    Number operator++(void);

    bool operator==(const Number &n2) const;

    bool operator!=(const Number &n2) const;

    bool operator<(const Number &n2) const;

    bool operator>(const Number &n2) const;

    void set_digito(int i, T a) const;

    void c2(void);

    void c1(void);

  private:
    void to_base(int n);

    Number suma(const Number<N, 2, T> &n2) const;

    Number resta(const Number<N, 2, T> &n2) const;

    char reVal(int num) const;

    int val(char c) const;

    NumberBase *duplicate() const;
};

//Crear constructor de copia

template <size_t N, class T>
Number<N, 2, T>::Number(int n) : NumberBase(N, 2), digito(0)
{
    digito = new (std::nothrow) T[N];
    if (digito == nullptr)
    {
        throw memory_excpt();
    }
    to_base(n);
    if (n < 0)
        c2();
}

template <size_t N, class T>
Number<N, 2, T>::Number(const Number<N, 2, T> &n2) : NumberBase(N, 2), digito(0)
{
    digito = new (std::nothrow) T[N];
    if (digito == nullptr)
    {
        throw memory_excpt();
    }
    (*this) = n2;
}

template <size_t N, class T>
Number<N, 2, T>::~Number()
{
    if (digito != NULL)
    {
        delete[] digito;
    }
    /*else
        throw pointer_excpt();*/
}

template <size_t N, class T>
void Number<N, 2, T>::to_base(int n)
{
    int resto;
    T a;
    for (unsigned i = 0; i < N; ++i)
    {
        resto = n % 2;

        n = n / 2;

        a = reVal(resto);

        digito[i] = a;
    }
    if (n > 0)
    {
        throw range_excpt();
    }
}

template <size_t N, class T>
void Number<N, 2, T>::c2()
{
    /*c1();
    (*this)++;*/
    int i = 0;

    c1();

    while (digito[i] != 1)
        i++;

    i++;

    while (i != N)
    {
        digito[i] = 1 - digito[i];
        i++;
    }
}

template <size_t N, class T>
void Number<N, 2, T>::c1()
{
    for (int i = N - 1; i >= 0; i--)
    {
        if (digito[i] == '0')
            digito[i] = 1;
        else
            digito[i] = 0;
    }
}

template <size_t N, class T>
std::ostream &Number<N, 2, T>::write(std::ostream &os) const
{
    //ESCRIBIR EL SIGNO
    for (int i = N - 1; i >= 0; i--)
    {
        os << digito[i] << " ";
    }
    os << std::endl;
    return os;
}

//Adaptar las operaciones para el signo
template <size_t N, class T>
void Number<N, 2, T>::operator=(const Number<N, 2, T> &n2)
{
    for (unsigned i = 0; i < N; i++)
    {
        digito[i] = n2.digito[i];
    }
}

template <size_t N, class T>
Number<N, 2, T> Number<N, 2, T>::operator++(void)
{
    Number<N, 2, T> dummy(1);
    (*this) = (*this) + dummy;
    return (*this);
}

template <size_t N, class T>
Number<N, 2, T> Number<N, 2, T>::operator+(const Number<N, 2, T> &n2) const
{
    Number<N, 2, T> nr;
    int carry = 0;
    int suma, modul;
    char a;

    for (unsigned i = 0; i < N; i++)
    {
        suma = val(digito[i]) + val(n2.digito[i]) + carry;
        modul = suma % 2;
        carry = suma / 2;
        a = reVal(modul);
        nr.digito[i] = a;
    }
    if (carry)
    {
        /*for (unsigned i = 0; i < N; i++)
        {
            n1.set_digito(i, nr.digito[i]);
        }
        n1.set_digito(N, '1');
        n1.write(std::cout);*/
        throw overflow_excpt();
    }

    return nr;
}

template <size_t N, class T>
NumberBase *Number<N, 2, T>::operator+(const NumberBase *n) const
{
    const Number<N, 2, T> *S = dynamic_cast<const Number<N, 2, T> *>(n);
    Number<N, 2, T> *r = dynamic_cast<Number<N, 2, T> *>(duplicate());
    (*r) = (*this) + (*S);
    return r;
}

template <size_t N, class T>
void Number<N, 2, T>::set_digito(int i, T a) const
{
    digito[i] = a;
}

template <size_t N, class T>
Number<N, 2, T> Number<N, 2, T>::operator-( const Number<N, 2, T> &n2) const
{
    Number<N, 2, T> nr;
    nr = n2;
    nr.c2();
    nr = (*this) + nr;

    return nr;
}

template <size_t N, class T>
NumberBase *Number<N, 2, T>::operator-(const NumberBase *n) const
{
    const Number<N, 2, T> *S = dynamic_cast<const Number<N, 2, T> *>(n);
    Number<N, 2, T> *r = dynamic_cast<Number<N, 2, T> *>(duplicate());
    (*r) = (*this) - (*S);
    return r;
}

template <size_t N, class T>
NumberBase *Number<N, 2, T>::duplicate() const
{
    return new Number<N, 2, T>;
}

template <size_t N, class T>
bool Number<N, 2, T>::operator==(const Number<N, 2, T> &n2) const
{

    bool iguales = true;
    for (unsigned i = 0; i < N; i++)
    {
        if (digito[i] != n2.digito[i])
        {
            iguales = false;
        }
    }
    return iguales;
}

template <size_t N, class T>
bool Number<N, 2, T>::operator!=(const Number<N, 2, T> &n2) const
{

    bool distintos = false;

    for (unsigned i = 0; i < N; i++)
    {
        if (digito[i] != n2.digito[i])
        {
            distintos = true;
        }
    }
    return distintos;
}

template <size_t N, class T>
bool Number<N, 2, T>::operator<(const Number<N, 2, T> &n2) const
{
    if (digito[N - 1] != n2.digito[N - 1])
    {
        if (digito[N - 1] == 1)
            return true;
    }
    else if (digito[N - 1] == 0)
    {
        int i = N - 2;
        while (digito[i] == n2.digito[i])
        {
            i--;
        }
        if (n2.digito[i] == 1)
            return true;
    }
    else
    {
        int i = N - 2;
        while (digito[i] == n2.digito[i])
        {
            i--;
        }
        if (n2.digito[i] == 0)
            return true;
    }
    return false;
}

template <size_t N, class T>
bool Number<N, 2, T>::operator>(const Number<N, 2, T> &n2) const
{
    if (digito[0] != n2.digito[0])
    {
        if (digito[0] == 0)
            return true;
    }
    else if (digito[0] == 1)
    {
        int i = 1;
        while (digito[i] == n2.digito[i])
        {
            i++;
        }
        if (n2.digito[i] == 1)
            return true;
    }
    else
    {
        int i = 1;
        while (digito[i] == n2.digito[i])
        {
            i++;
        }
        if (n2.digito[i] == 0)
            return true;
    }
    return false;
}

template <size_t N, class T>
int Number<N, 2, T>::val(char c) const
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

template <size_t N, class T>
char Number<N, 2, T>::reVal(int num) const
{
    if (num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
