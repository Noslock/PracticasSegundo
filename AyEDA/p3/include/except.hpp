#pragma once
#include <iostream>
#include <exception>

class NumberException : public std::exception
{
  public:
    const char *what() const throw()
    {
        return "Error desconocido en Number. \n";
    }
};

class range_excpt : public NumberException
{
  public:
    const char *what() const throw()
    {
        return "Error de Number: El número a representar excede el rango especificado. \n";
    }
};

class memory_excpt : public NumberException
{
  public:
    const char *what() const throw()
    {
        return "Error en Number: No hay memoria suficiente. \n";
    }
};

class pointer_excpt : public NumberException
{
  public:
    const char *what() const throw()
    {
        return "Error en Number: Se está intentando borrar una zona de memoria que no pertenece a Number. \n";
    }
};

class overflow_excpt : public NumberException
{
  public:
    const char *what() const throw()
    {
        return "Error de Number: El resultado de la suma crea un overflow (No puede representarse con la base de los números sumados).\n";
    }
};

class base_excpt : public NumberException
{
  public:
    const char *what() const throw()
    {
        return "Error de Number: La base del número a representar no está permitido.\n";
    }
};

class wrong_number_excpt : public NumberException
{
  public:
    const char *what() const throw()
    {
        return "Error de Number: La base del número a representar no está permitido.\n";
    }
};