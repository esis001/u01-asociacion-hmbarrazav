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
        Casa* propiedades[10];
        int nCasas;
    public:
        Duenio(string);
        void mostrarDuenio();
        void asignarCasa(Casa *);
};

Duenio :: Duenio(string n){
    nombre = n;
    nCasas = 0;
}

void Duenio :: mostrarDuenio(){
    cout<<"El(la) contribuyente "<<nombre<<" esta ";
    cout<<"registrado(a) en el sistema,";
    if(nCasas == 0){
        cout<<" y no tiene propiedades asignadas.";
        cout<<endl;
    }
    else{
        cout<<" y tiene "<<nCasas<<" propiedades:"<<endl;
        for(int i=0; i<nCasas; i++){
            cout<<"\t- ";
            propiedades[i]->mostrarCasa();
        }
    }
}

void Duenio :: asignarCasa(Casa *pC){
    propiedades[nCasas] = pC;
    nCasas++;
}

int main(){
    Casa c1("Av. San Martin 888", 4);
    c1.mostrarCasa();
    Casa c2("Av. Leguia 1243", 2);
    c2.mostrarCasa();
    Duenio d1("Jorge Perez");
    d1.mostrarDuenio();
    d1.asignarCasa(&c1);
    d1.asignarCasa(&c2);
    cout<<"---------------------------"<<endl;
    d1.mostrarDuenio();
    return 0;
}