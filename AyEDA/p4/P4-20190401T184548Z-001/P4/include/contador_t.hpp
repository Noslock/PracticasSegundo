#pragma once

#define MAX 999999

using namespace std;

class contador_t{

    private:
        int min;
        int max;
        int medio;
        int acumulador;
        // int cuenta;

    public:
        contador_t(){
            reset();
        }
        ~contador_t(){}

        void reset(){
            min = MAX;
            max = 0;
            medio = 0;
            acumulador = 0;
            // cuenta = 0;
        }

        void start(){
            reset();
        }

        void end(){
            cout << acumulador << "," << min << "," << max << "," << medio << endl;
            if(acumulador < min) min = acumulador;
            if(acumulador > max) max = acumulador;
            medio = (min+max)/2;
            cout << acumulador << "," << min << "," << max << "," << medio << endl;

            // acumulador += cuenta;
        }

        int operator ++ (){
            return acumulador++;
        }

        void show(){
            cout << acumulador << endl;
            cout << "Mínimo: " << min << endl;
            cout << "Máximo: " << max << endl;
            cout << "Medio: " << medio << endl;
        }

};