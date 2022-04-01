#include<iostream>
using namespace std;

class Persona{
    protected:
        string DNI;
        string nombres;
    public:
        Persona(string, string);
        void mostrarDatos();
};

Persona :: Persona(string d, string n){
    DNI = d;
    nombres = n;
}

void Persona :: mostrarDatos(){
    cout<<nombres<<" tiene el DNI #"<<DNI;
}

class Estudiante : public Persona{
    private:
        string codigo;
        int notas[10];
        int nNotas;
    public:
        Estudiante(string,string,string);
        void ingresarNota(int);
        void mostrarEstudiante();
}; 

Estudiante :: Estudiante(string n, string d, string c)
    : Persona(n,d){
    codigo = c;
    nNotas = 0;
}

void Estudiante :: ingresarNota(int n){
    notas[nNotas] = n;
    nNotas++;
}

void Estudiante :: mostrarEstudiante(){
    mostrarDatos();
    cout<<", es un estudiante con codigo universitario ";
    cout<<codigo;
    if(nNotas == 0){
        cout<<" y aun no tiene notas registradas."<<endl;
    }
    else{
        int S = 0;
        cout<<" y tiene "<<nNotas<<" notas registradas: ";
        cout<<endl<<"\t";
        for(int i=0; i<nNotas; i++){
            S = S + notas[i];
            cout<<notas[i]<<"   ";
        }
        cout<<"Promedio: "<<S/nNotas<<endl;
    }
}

class Docente : public Persona{
    private:
        string especialidad;
        float sueldo;
    public:
        Docente(string,string,string,float);
        void mostrarDocente();
};

Docente :: Docente(string d, string n, string e, float s)
    : Persona(d,n){
        especialidad = e;
        sueldo = s;
}

void Docente :: mostrarDocente(){
    mostrarDatos();
    cout<<", es un docente con especialidad de ";
    cout<<especialidad<< " y tiene un salario de S/";
    cout<<sueldo;
}

int main(){
    Persona per1("12345678", "Fulatino de Tal");
    per1.mostrarDatos();
    cout<<endl;
    Estudiante est1("10203040","Jorge Perez","2021-123456");
    est1.mostrarEstudiante();
    est1.ingresarNota(16);
    est1.ingresarNota(14);
    est1.ingresarNota(13);
    cout<<"-------------------"<<endl;
    est1.mostrarEstudiante();
    cout<<"-------------------"<<endl;
    Docente doc("00102030","Pablo Mamani","Ing. Quimico",5000.00);
    doc.mostrarDocente();
    return 0;
}