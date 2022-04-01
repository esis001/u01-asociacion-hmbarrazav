#include<iostream>
#include<string>
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
        Aula* secciones[10];
        int nAulas;
    public:  
        Colegio(string);
        void mostrarColegio();
        void leerAulas(int);
};

Colegio :: Colegio(string n){
    nombre = n;
    nAulas = 0;
}

void Colegio :: mostrarColegio(){
    cout<<"El colegio "<<nombre<<", ";
    if(nAulas == 0){
        cout<<"no tiene aulas. "<<endl;
    }
    else{
        cout<<"tiene "<<nAulas<<" aulas:"<<endl;
        for(int i=0; i<nAulas; i++){
            cout<<"\t-";
            secciones[i]->mostrarAula();
        }
    }
}

void Colegio :: leerAulas(int n){
    string nom;
    int nA;
    for(int i=0; i<n; i++){
        cout<<"Ingrese nombre del Aula: ";
        fflush(stdin); getline(cin,nom);
        cout<<"Ingrese aforo: "; cin>> nA;
        secciones[nAulas] = new Aula(nom,nA);
        nAulas++;
    }
}

int main(){
    //Aula a1("Primer grado",20);
    //a1.mostrarAula();
    int cA;
    Colegio c1("Santa Teresita");
    c1.mostrarColegio();
    cout<<"----------------"<<endl;
    cout<<"Ingrese cantidad de aulas: "; cin>>cA;
    c1.leerAulas(cA);
    c1.mostrarColegio();
    return 0;
}