#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <conio.h>
using namespace std;
void menu();
void baner();
void db();
void gen();
void gencp();
void pausa();
int main(){
    char so;
    do{
    baner();
    menu();
    cout<<"Deseas Otra Operacion s/n ";
    cin>>so;
    }while(so=='s');
    pausa();
    return 0;
}

void baner(){
    cout<<"\n###############################################################################\n";
    cout<<"#                                                                             #\n";
    cout<<"#                         Infinitum Movil Generador                           #\n";
    cout<<"#                                                                             #\n";
    cout<<"#                                 By DR460                                    #\n";
    cout<<"#                                                                             #\n";
    cout<<"###############################################################################\n";
}

void menu(){
    int op;
    cout<<"Ingresa Una Opcion \n";
    cout<<"1. Abrir Base De Datos\n";
    cout<<"2. Generar Numeros Telefonicos\n";
    cout<<"3. Generar Codigo Postal\n";
    cout<<"4. Salir\n";
    cout<<">";
    cin>>op;
    switch(op){
        case 1:db();
        break;
        case 2:gen();
        break;
        case 3:gencp();
        break;
        case 4:exit(1);
        break;
        default:cout<<"opcion Incorrecta\n";
    }
    }

void gen(){
    int nr, tb, i;
    char ss;
    do{
    cout<<"Cuantos Numeros Quiere Generar ";
    cin>>nr;
    cout<<"Ingresa El Numero Telefonico A 7 Digitos ";
    cin>>tb;
            srand(time(NULL));
            for(i=0; i<nr; i++){
            cout<<tb<<rand()% 1000<<endl;
            }
        cout<<"Desea Segir Generando s/n ";
        cin>>ss;
    }while(ss=='s');
}

void gencp(){
    int cp, cq, i;
    char si;
    do{
    cout<<"Ingresa El Codigo Postal A 3 Digitos ";
    cin>>cp;
    srand(time(NULL));
    cout<<cp<<rand()%100<<endl;
    cout<<"Desea Segir Gereando s/n ";
    cin>>si;
    }while(si=='s');
}

void db(){
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"CP\t\tCiudad\t\tTelefono\t\t\n";
    cout<<"-------------------------------------------------------------------------------\n";
    ifstream archivo;
    string texto;
    archivo.open("db.txt",ios::in);
    if(archivo.fail()){
        cout<<"No Se Pudo Abrir El Archivo";
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}
void pausa(){

    cout<<"\nPreciona Una Tecla Para Continuar ...";
    getch();

}
