#include<iostream>
using namespace std;

class Casa{
    private:
        string direccion;
        int cantHab;
    public:
        Casa(string,int);
        void mostrarCasa();
};

Casa :: Casa (string d, int c){
    direccion = d;
    cantHab = c;
}

void Casa :: mostrarCasa(){
    cout<<"Casa ubicada en "<<direccion<<" y tiene ";
    cout<<cantHab<<" habitaciones."<<endl;
}

class Duenio{
    private:
        string nombre;
    public:
        Duenio(string);
        void mostrarDuenio();
};

Duenio :: Duenio(string n){
    nombre = n;
}

void Duenio :: mostrarDuenio(){
    cout<<"El(la) contribuyente "<<nombre<<" esta ";
    cout<<"registrado(a) en el sistema."<<endl;
}

int main(){
    Casa c1("Av. San Martin 888", 4);
    c1.mostrarCasa();
    Duenio d1("Jorge Perez");
    d1.mostrarDuenio();
    return 0;
}