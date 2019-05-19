#pragma once

#include <iostream>
#include <iomanip>

#include "contador_t.hpp"
static contador_t contador;
// static contador_t contador_i;
// static contador_t contador_b;

class DNI_t{ // esta clase la vamos a utilizar como CLAVE
    private:
        int numdni;
        
    public:
        inline DNI_t(): numdni(0) {}
        inline DNI_t(unsigned value): numdni(value) {}
        inline DNI_t(DNI_t& n): numdni(n.numdni) {}
        inline ~DNI_t() { numdni = 0; }

        int get_numdni() const{
            return numdni;
        }

        operator unsigned long() const{
            return numdni;
        }


        bool operator == (DNI_t& otrodni){ // devolver si son iguales o no lo son
            ++contador;
            return (numdni == otrodni.numdni);
        } 

        // bool operator == (int otrodni){ 
        //   return (numdni == otrodni) ? true : false;
        // }

        unsigned operator % (int n){ 
            return numdni%n; 
        }

        bool operator > (DNI_t& otrodni){ 
            return (numdni > otrodni.numdni);
        }

        

        // bool operator <= (int otrodni){ 
        //   return (numdni <= otrodni) ? true : false;
        // }

        //operator unsigned int ()
    //  static contador;  // se ha de incrementar cn cada búsqeda
};