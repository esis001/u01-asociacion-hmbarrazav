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

int main(){
    Rector r1("Javier Lozano");
    r1.mostrarRector();
    return 0;
}