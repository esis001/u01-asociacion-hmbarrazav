#include<iostream>
#include<iomanip> //Manipuladores de entrada y salida
using namespace std;

class Persona{
    protected:
        string DNI;
        string nombres;
        string tipo;
    public:
        Persona(string, string);
        virtual void mostrarDatos();
        string getTipo();
        string getDNI();
};

string Persona :: getDNI(){
    return DNI;
}

string Persona :: getTipo(){
    return tipo;
}

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
        void mostrarDatos();
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
    tipo = "Estudiante";
}

void Estudiante :: mostrarDatos(){
    Persona :: mostrarDatos();
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
        void mostrarDatos();
        void asignarEstudiante(Estudiante*);
        void ingresarNotaEst(int, int);
        void visualizarRegistro();
};

void Docente :: visualizarRegistro(){
    cout<<left<<setw(14)<<"Codigo";
    cout<<setw(30)<<"Nombres";
    cout<<setw(50)<<"Notas";
    cout<<endl;
    for(int i=0; i<nEstudiantes;i++){
        cout<<setw(14)<<listaEstudiantes[i]->getCodigo();
        cout<<setw(30)<<listaEstudiantes[i]->getNombres();
        int *ptr = listaEstudiantes[i]->getNotas();
        for(int j=0; j<listaEstudiantes[i]->getNNotas();j++)
            cout<<setw(5)<<ptr[j];
        cout<<endl;
    }
}

void Docente :: ingresarNotaEst(int nota, int nE){
    listaEstudiantes[nE] -> ingresarNota(nota);
}

Docente :: Docente(string d, string n, string e, float s)
    : Persona(d,n){
        especialidad = e;
        sueldo = s;
        nEstudiantes = 0;
        tipo = "Docente";
}

void Docente :: mostrarDatos(){
    Persona :: mostrarDatos();
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
            listaEstudiantes[i]->mostrarDatos();
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
    /*Persona per1("12345678", "Fulatino de Tal");
    per1.mostrarDatos();
    cout<<endl;
    Estudiante est1("10203040","Jorge Perez Aro","2021-123456");
    est1.mostrarEstudiante();
    est1.ingresarNota(16);
    est1.ingresarNota(14);
    est1.ingresarNota(13);
    cout<<"-------------------"<<endl;
    Docente doc("00102030","Pablo Mamani","Ing. Quimico",5000.00);
    Estudiante est2("10203041","Andrez Gomez Quispe","2021-123457");
    Estudiante est3("10203042","Pedro Esqueche Gamarra","2021-123458");
    Estudiante est4("10203043","Miriam Valdez Ticona","2021-123459");
    doc.asignarEstudiante(&est1);
    doc.asignarEstudiante(&est2);
    doc.asignarEstudiante(&est3);
    doc.asignarEstudiante(&est4);
    cout<<"-------------------"<<endl;
    doc.mostrarDocente();
    doc.ingresarNotaEst(20,1);
    doc.ingresarNotaEst(02,1);
    doc.ingresarNotaEst(17,2);
    doc.ingresarNotaEst(18,3);
    cout<<"-------------------"<<endl;
    doc.visualizarRegistro();*/
    int i=0;
    int cen = 0;
    int op = 0;
    int iP;
    string tP;
    Persona* listaPersonas[10];
    Docente doc("00102030","Pablo Mamani","Ing. Quimico",5000.00);
    Estudiante est1("10203040","Jorge Perez Aro","2021-123456");
    Estudiante est2("10203041","Andrez Gomez Quispe","2021-123457");
    Estudiante est3("10203042","Pedro Esqueche Gamarra","2021-123458");
    Estudiante est4("10203043","Miriam Valdez Ticona","2021-123459");
    listaPersonas[0] = &doc;
    listaPersonas[1] = &est1;
    listaPersonas[2] = &est2;
    listaPersonas[3] = &est3;
    listaPersonas[4] = &est4;
    string dni;
    system("cls");
    cout<<"AUTENTICACION-------"<<endl<<endl;
    cout<<"Ingrese su DNI: "; cin>>dni;
    
    while(i<5 && cen == 0){
        if(listaPersonas[i]->getDNI() == dni){
            cen = 1;
            iP = i;
            tP = listaPersonas[i]->getTipo();
        }
        i++;
    }
    if(cen == 0)
        cout<<"No existe el DNI!!!"<<endl;
    else
        do{
            system("cls");
            cout<<"MENU DE OPCIONES----------"<<endl;
            cout<<"1. Mostrar datos del "<<tP<<endl;
            cout<<"2. Crear estudiante"<<endl;
            cout<<"3. Aniadir nota a estudiante"<<endl;
            cout<<"4. Visualizar registro de notas"<<endl;
            cout<<"0. Salir"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>op;
            cout<<endl;
            switch(op){
                case 1:
                    if(tP == "Docente"){
                        listaPersonas[iP]->mostrarDatos();
                        cout<<endl;
                    }
                    else{
                        listaPersonas[iP]->mostrarDatos();
                        cout<<endl;
                    }
                break;
            }
            system("pause");
        }while(op != 0);
    return 0;
}