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
        Docente *docente; //atributo de asociación
    public:
        Estudiante(string,string,string);
        void mostrarEstudiante();
        void asignarDocente(Docente *);
        void ingresarNota(int);
        string getCodigo(); //getters
        string getNombres();
        int getNNotas();
        int* getNotas();
}; 

string Estudiante :: getCodigo(){
    return codigo;
}

string Estudiante :: getNombres(){
    return nombres;
}

int Estudiante :: getNNotas(){
    return nNotas;
}

int* Estudiante :: getNotas(){
    return notas;
}

void Estudiante :: ingresarNota(int n){
    if(nNotas < 10){
        notas[nNotas] = n;
        nNotas++;
    }
    else{
        cout<<"No se pudo insertar la nota"<<endl;
    }
}

Estudiante :: Estudiante(string n, string d, string c)
    : Persona(n,d){
    codigo = c;
    nNotas = 0;
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
        Estudiante* listaEstudiantes[30]; //atributo de asociación
        int nEstudiantes; //atributo de asociación
    public:
        Docente(string,string,string,float);
        void mostrarDocente();
        void asignarEstudiante(Estudiante*);
        void ingresarNotaEst(int, int);
};

void Docente :: ingresarNotaEst(int nota, int nE){
    listaEstudiantes[nE] -> ingresarNota(nota);
}

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
        pE->asignarDocente(this); //asigna el docente actual
                                  //al estudiante del parámetro
                                  //de entrada
        nEstudiantes++;
    }
    else
        cout<<"No se puedo agregar al estudiante"<<endl;
}

int main(){
    //Persona per1("12345678", "Fulatino de Tal");
    //per1.mostrarDatos();
    //cout<<endl;
    Estudiante est1("10203040","Jorge Perez","2021-123456");
    est1.mostrarEstudiante();
    est1.ingresarNota(16);
    est1.ingresarNota(14);
    est1.ingresarNota(13);
    cout<<"-------------------"<<endl;
    est1.mostrarEstudiante();
    cout<<"-------------------"<<endl;
    /*Docente doc("00102030","Pablo Mamani","Ing. Quimico",5000.00);
    doc.mostrarDocente();
    Estudiante est2("10203041","Andrez Gomez","2021-123457");
    doc.asignarEstudiante(&est1);
    doc.asignarEstudiante(&est2);
    cout<<"-------------------"<<endl;
    doc.mostrarDocente();*/
    cout<<"Codigo: "<<est1.getCodigo()<<endl;
    cout<<"Nombres: "<<est1.getNombres()<<endl;
    cout<<"Cantidad de notas: "<<est1.getNNotas()<<endl;
    //cout<<"Notas: "<<*est1.getNotas()<<endl;
    //cout<<"Notas: "<<*(est1.getNotas()+1)<<endl;
    for(int i=0; i<est1.getNNotas();i++){
        cout<<"Nota #"<<i+1<<": "<<*(est1.getNotas()+i)<<endl;
    }
    return 0;
}