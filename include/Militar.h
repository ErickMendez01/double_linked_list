#ifndef MILITAR_H
#define MILITAR_H
#include <iostream>

using namespace std;

class Militar
{
    public:
        Militar();
       ~Militar();
        int getllave();
        void setllave(int &);
        string getNombre();
        void setNombre(string &);
        int getEdad();
        void setEdad(int &);
        string getRango();
        void setRango(string &);
        float getSueldo();
        void setSueldo(float &);

        private:
        int llave;
        string Nombre;
        int Edad;
        string Rango;
        float Sueldo;
};

#endif // MILITAR_H
