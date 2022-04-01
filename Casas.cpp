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

int main(){
    Casa c1("Av. San Martin 888", 4);
    c1.mostrarCasa();
    return 0;
}