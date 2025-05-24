#include "Doble.h"
#include "Nodo.h"
#include "Militar.h"

using namespace std;

bool Doble::vacia(){
  if(h==nullptr and t==nullptr){
    return true;
  }else{
   return false;
  }
}

void Doble::insertar(Militar mi){
    Nodo *tmp=new Nodo;
    tmp->dato=mi;

    if(h==nullptr and t==nullptr)
        {
          h=tmp;
          t=tmp;
        }
        else
        {
            tmp->sig=h;
            h->ant=tmp;
            h=tmp;

        }
}

int Doble::eliminar(string d){
  Nodo *aux;
  Nodo *aux2;
  Nodo *aux3;
  int band;
  if(h){
      aux=h;
      while((aux!=nullptr)&& (aux->dato.getNombre()!=d))
              aux=aux->sig;
      if(aux==nullptr)
        band=0;
      else
      {
       if(h==t)
        {
            h=nullptr;
            t=nullptr;
        }
       else
       if( aux==h)
        {
            h=aux->sig;
            h->ant=nullptr;
        }
        else
         if(aux==t)
        {
            t=aux->ant;
            t->sig=nullptr;
        }
        else
        {
            aux2=aux->ant;
            aux3=aux->sig;
            aux2->sig=aux3;
            aux3->ant=aux2;
        }
        delete(aux);

      }
 }
 else
    band=-1;
 return band;
}

int Doble::buscar(int d,int c){
 int f=0;
 char op;
 string aux;
 int aux2;
 float aux3;
    Nodo *tmp;
    tmp=h;
    if(vacia()==true){
        cout<<"REGISTRO VACIO"<<endl;
    }else{
    while(tmp!=nullptr){
        if(tmp->dato.getllave()==d){
           if(c==3){
               cout<<"--------------------------------"<<endl;
               cout<<"NOMBRE: "<<tmp->dato.getNombre()<<endl;
               cout<<"EDAD: "<<tmp->dato.getEdad()<<endl;
               cout<<"LLAVE: "<<tmp->dato.getllave()<<endl;
               cout<<"RANGO: "<<tmp->dato.getRango()<<endl;
               cout<<"SUELDO: $"<<tmp->dato.getSueldo()<<endl;
               cout<<"--------------------------------"<<endl;
               f=1;
           }else if(c==4){
            cout<<"¿CUAL DE LAS OPCIONES DISPONIBLES DESEA MODIFICAR?"<<endl;
             cout<<"A) EDAD, B) RANGO, C) SUELDO."<<endl;
             cin>>op;
             system("cls");
             if(op=='a'|| op=='A')
             {
               cout<<"INGRESE EDAD: "<<endl;
               cin>>aux2;
               system("cls");
               tmp->dato.setEdad(aux2);
                f=2;
             }else if(op=='b'||op=='B')
             {
               cout<<"INGRESE RANGO: "<<endl;
               cin>>aux;
               system("cls");
               tmp->dato.setRango(aux);
               f=2;
             }else if(op=='c'||op=='C')
             {
               cout<<"INGRESE SUELDO"<<endl;
               cin>>aux3;
               system("cls");
               tmp->dato.setSueldo(aux3);
               f=2;
             }

           }else if(c==1){
                cout<<"ESTA CLAVE YA ESTA EN USO"<<endl;
                 f=1;
           }
        }
        tmp=tmp->sig;
    }
    if(f==1){
       return f;
    }else if(f==0){
        if(c==1){
           return f;
        }else{
        cout<<"REGISTRO INEXISTENTE"<<endl;
        return f;
        }
    }else if(f==2){
        cout<<"MODIFICACION TERMINADA"<<endl;
        return f;
    }
  }
  return f;
}

int Doble::tamanio(){
      int cont=0;
      Nodo *aux=h;
      while(aux!=nullptr){
        cont++;
        aux=aux->sig;
      }
      return cont;
}

void Doble::mostrar(){
     Nodo *aux;
     if(vacia()==true){
        cout<<"REGISTRO VACIO"<<endl;
     }else{
      aux=h;
      while(aux!=nullptr){
        cout<<"--------------------------------"<<endl;
        cout<<"NOMBRE: "<<aux->dato.getNombre()<<endl;
        cout<<"EDAD: "<<aux->dato.getEdad()<<endl;
        cout<<"LLAVE: "<<aux->dato.getllave()<<endl;
        cout<<"RANGO: "<<aux->dato.getRango()<<endl;
        cout<<"SUELDO: $"<<aux->dato.getSueldo()<<endl;
        cout<<"--------------------------------"<<endl;
        aux=aux->sig;
       }
     }

}

void Doble::shell(){
Nodo *tmp=h;
    Nodo *aux=h;
    Nodo *inicio=h;
    bool step=false;
    bool step2=false;
    bool step3=false;
    Militar u;
    int contador=0,brecha=0;
    brecha=(tamanio())/2;
    while(brecha>0){
        for(int i=brecha;i<tamanio();i++){
            contador=i;
            if(step==false || step3==true){
                tmp=inicio;
                for(int j(0);j<i;++j){
                    tmp=tmp->sig;
                }
            }
            else{
            tmp=tmp->sig;
            }
            if(step==false || step3==true){
                aux=inicio;
                for(int l(0); l<contador-brecha;++l){
                    aux=aux->sig;
                }
            }
            else{
                aux=aux->sig;
                step=true;
            }
            while((contador >= brecha) && (aux->dato.getllave()>tmp->dato.getllave())){
                u=tmp->dato;
                tmp->dato = aux->dato;
                contador = contador-brecha;
                step2=true;
                step3=true;
                while((contador >= brecha) && (step2==true)){
                    tmp=inicio;
                    aux=inicio;
                    for(int j(0);j<contador;++j){
                        tmp=tmp->sig;
                    }
                    tmp->dato=u;
                    for(int k(0);k<contador-brecha;++k){
                        aux=aux->sig;
                    }
                    step2 = false;
                    step3 = true;
                }
            }
            if(contador < brecha){
                aux->dato = u;
            }
            step=true;
        }
        brecha=brecha/2;
        tmp=inicio;
        aux=inicio;
        step=false;
    }
}

Doble::Doble()
{
    h=nullptr;
    t=nullptr;
}

Doble::~Doble()
{
    //dtor
}
