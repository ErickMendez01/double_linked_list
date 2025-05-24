#include <iostream>
#include "Militar.h"
#include "Doble.h"

using namespace std;

int main()
{
    Doble *Do=new Doble();
    Militar x;
    int llave;
    string nombre;
    int edad;
    string rango;
    float sueldo;

   int opcion;
   do{
        cout<<"\n-------MENU DE OPCIONES-------------"<<endl;
        cout<<"---(1).DAR DE ALTA                 ---"<<endl;
        cout<<"---(2).DAR DE BAJA                 ---"<<endl;
        cout<<"---(3).CONSULTAR                   ---"<<endl;
        cout<<"---(4).MODIFICAR                   ---"<<endl;
        cout<<"---(5).ORDENAR REGISTROS           ---"<<endl;
        cout<<"---(6).PERSONAS REGISTRADAS        ---"<<endl;
        cout<<"---(7).MOSTRAR TODOS LOS REGISTROS ---"<<endl;
        cout<<"---(8).SALIR                       ---"<<endl;
        cout<<"--------------------------------------"<<endl;
        cin>>opcion;
        system("cls");
   switch(opcion){
       case 1:cout<<"INGRESE NOMBRE : "<<endl;
              cin>>nombre;
              x.setNombre(nombre);
              cout<<"INGRESE EDAD : "<<endl;
              cin>>edad;
              x.setEdad(edad);
              cout<<"INGRESE LLAVE (CLAVE) MILITAR : "<<endl;
              cin>>llave;
              if(Do->vacia()==true){
                x.setllave(llave);
              }else{
                while(Do->buscar(llave,opcion)==1){
                cout<<"INGRESE LLAVE (CLAVE) MILITAR : "<<endl;
                cin>>llave;
               }
               x.setllave(llave);
              }
              cout<<"INGRESE RANGO : "<<endl;
              cin>>rango;
              x.setRango(rango);
              cout<<"INGRESE SUELDO : "<<endl;
              cin>>sueldo;
              x.setSueldo(sueldo);
              Do->insertar(x);
       break;
       case 2:cout<<"INGRESE NOMBRE PARA DAR DE BAJA : "<<endl;
              cin>>nombre;
              Do->eliminar(nombre);
       break;
       case 3: cout<<"INGRESA LLAVE (CLAVE) DEL REGISTRO A CONSULTAR"<<endl;
               cin>>llave;
               system("cls");
               if(Do->buscar(llave,opcion)==1){
                cout<<"REGISTRO ENCONTRADO"<<endl;
               }


       break;
       case 4: cout<<"INGRESA LLAVE (CLAVE) DEL REGISTRO A MODIFICAR"<<endl;
               cin>>llave;
               Do->buscar(llave,opcion);
       break;
       case 5:if(Do->vacia()==true){
                cout<<"REGISTRO VACIO"<<endl;
             }else{
              Do->shell();
             }
       break;
       case 6: cout<<" PERSONAS REGISTRAS"<<"["<<Do->tamanio()<<"]"<<endl;
       break;
       case 7:Do->mostrar();
       break;
       case 8: cout<<"SYSTEMA CERRADO"<<endl;
       break;
       default: cout<<"OPCION INCORRECTA";
       break;
      }
    }while(opcion!=8);

}
