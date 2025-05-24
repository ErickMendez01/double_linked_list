#ifndef DOBLE_H
#define DOBLE_H
#include "Nodo.h"
#include "Militar.h"
#include <iostream>

using namespace std;
class Doble
{
    public:
        Doble();
       ~Doble();
       Nodo *h;
       Nodo *t;
       bool vacia();
       void insertar(Militar);
       int eliminar(string);
       int tamanio();
       int buscar(int,int);
       void mostrar();
       void shell();
};

#endif // DOBLE_H
