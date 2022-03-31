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
    public:
        Universidad(string,string);
        void mostrarDatos();
};

Universidad :: Universidad(string d, string c){
    denominacion = d;
    ciudad = c;
}

void Universidad :: mostrarDatos(){
    cout<<"La Universidad "<<denominacion<<" esta ubicada ";
    cout<<"en la ciudad de "<<ciudad;
}

int main(){
    Rector r1("Javier Lozano");
    r1.mostrarRector();
    cout<<endl;
    Universidad u1("Jorge Basadre Grohmann","Tacna");
    u1.mostrarDatos();
    return 0;
}