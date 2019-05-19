#pragma once

#define MAX 99999

class Contador
{
  private:
    int minimo;
    int media;
    int maximo;
    int acumulador;

  public:
    Contador();
    ~Contador();

    void reset();
    void start();
    void end();
    void mostar();

    int operator++();
};