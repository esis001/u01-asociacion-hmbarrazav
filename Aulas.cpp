#include<iostream>
using namespace std;

class Aula{
    private:
        string nombre;
        int nAlumnos;
    public:
        Aula(string, int);
        void mostrarAula();
};

Aula :: Aula(string n, int nA){
    nombre = n;
    nAlumnos = nA;
}

void Aula :: mostrarAula(){
    cout<<"El aula "<<nombre<<" tiene un aforo para ";
    cout<<nAlumnos<<" alumnos."<<endl;
}

class Colegio{
    private:
        string nombre;
    public:  
        Colegio(string);
        void mostrarColegio();
};

Colegio :: Colegio(string n){
    nombre = n;
}

void Colegio :: mostrarColegio(){
    cout<<"El colegio "<<nombre<<endl;
}

int main(){
    Aula a1("Primer grado",20);
    a1.mostrarAula();
    Colegio c1("Santa Teresita");
    c1.mostrarColegio();
    return 0;
}