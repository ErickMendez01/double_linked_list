#include "Militar.h"

using namespace std;
int Militar::getllave(){
    return llave;
}
void Militar::setllave(int &ll){
   llave=ll;
}

string Militar::getNombre(){
  return Nombre;
}
void Militar::setNombre(string &nom){
   Nombre=nom;
}

int Militar::getEdad(){
     return Edad;
}
void Militar::setEdad(int &ed){
        Edad=ed;
}

string Militar::getRango(){
    return Rango;
}
void Militar::setRango(string &ra){
        Rango=ra;
}

float Militar::getSueldo(){
     return Sueldo;
}
void Militar::setSueldo(float &su){
       Sueldo=su;
}

Militar::Militar()
{
    llave=0;
    Nombre="";
    Edad=0;
    Rango="";
    Sueldo=0;
}

Militar::~Militar()
{
    //dtor
}
