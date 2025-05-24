#ifndef NODO_H
#define NODO_H
#include "Militar.h"

using namespace std;

class Nodo
{
    public:
        Nodo();
        ~Nodo();
        Militar dato;
        Nodo *sig;
        Nodo *ant;
};

#endif // NODO_H
