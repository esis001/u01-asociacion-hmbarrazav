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

class Docente;

class Estudiante : public Persona{
    private:
        string codigo;
        int notas[10];
        int nNotas;
        Docente *docente;
    public:
        Estudiante(string,string,string);
        void ingresarNota(int);
        void mostrarEstudiante();
        void asignarDocente(Docente *);
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

void Estudiante :: asignarDocente(Docente *pD){
    docente = pD;
}

class Docente : public Persona{
    private:
        string especialidad;
        float sueldo;
        Estudiante* listaEstudiantes[30];
        int nEstudiantes;
    public:
        Docente(string,string,string,float);
        void mostrarDocente();
        void asignarEstudiante(Estudiante*);
};

Docente :: Docente(string d, string n, string e, float s)
    : Persona(d,n){
        especialidad = e;
        sueldo = s;
        nEstudiantes = 0;
}

void Docente :: mostrarDocente(){
    mostrarDatos();
    cout<<", es un docente con especialidad de ";
    cout<<especialidad<< ", tiene un salario de S/";
    cout<<sueldo;
    if(nEstudiantes == 0){
        cout<<" y no tiene estudiantes asignados.";
        cout<<endl;
    }
    else{
        cout<<" y tiene "<<nEstudiantes<<" estudiantes: ";
        cout<<endl;
        for(int i=0; i<nEstudiantes; i++){
            cout<<i+1<<"-> ";
            listaEstudiantes[i]->mostrarEstudiante();
        }
    }
}

void Docente :: asignarEstudiante(Estudiante *pE){
    if(nEstudiantes <= 30){
        listaEstudiantes[nEstudiantes] = pE;
        pE->asignarDocente(this);
        nEstudiantes++;
    }
    else
        cout<<"No se puedo agregar al estudiante"<<endl;
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
    Estudiante est2("10203041","Andrez Gomez","2021-123457");
    doc.asignarEstudiante(&est1);
    doc.asignarEstudiante(&est2);
    cout<<"-------------------"<<endl;
    doc.mostrarDocente();
    return 0;
}