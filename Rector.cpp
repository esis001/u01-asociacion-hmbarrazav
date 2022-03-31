#include<iostream>
using namespace std;

class Rector{
    private:
        string nombres;
    public:
        Rector(string);
        void mostrarRector();
};

Rector :: Rector(string n){
    nombres = n;
}

void Rector :: mostrarRector(){
    cout<<"Dr. "<<nombres;
}

class Universidad{
    private:
        string denominacion;
        string ciudad;
        Rector *r;
    public:
        Universidad(string,string);
        void mostrarDatos();
        void asignarRector(Rector*);
};

Universidad :: Universidad(string d, string c){
    denominacion = d;
    ciudad = c;
    r = NULL;
}

void Universidad :: mostrarDatos(){
    cout<<"La Universidad "<<denominacion<<" esta ubicada ";
    cout<<"en la ciudad de "<<ciudad;
    if (r == NULL)
        cout<<" aun no tiene rector asignado";
    else{
        cout<<" y tiene como rector al "; 
        r->mostrarRector();
    }
}

void Universidad :: asignarRector(Rector *pR){
    r = pR;
}

int main(){
    Rector r1("Javier Lozano");
    r1.mostrarRector();
    cout<<endl;
    Universidad u1("Jorge Basadre Grohmann","Tacna");
    u1.mostrarDatos();
    u1.asignarRector(&r1);
    cout<<endl;
    u1.mostrarDatos();
    return 0;
}