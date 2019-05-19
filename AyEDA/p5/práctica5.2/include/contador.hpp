#pragma once

#define MAX 999999999

class Contador
{
  private:
    static int cuenta;
    static int min;
    static int media;
    static int max;
    static int acumulador;
    static int test;

  public:
    Contador();
    ~Contador();

    void reset();
    void start();
    void end();
    void show();

    Contador operator++(int);
/*
        Contador result;
        cuenta++;
        return result;

    }*/
};
