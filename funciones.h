#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "rlutil.h"
using namespace rlutil;
/////////////////////////DEFINICION DE LAS FUNCIONES////////////////////////////////////////

int EjecutarMenu(int opcion);                   // MUESTRA EL MENU DE INICIO

void IngresoNombre1Jugador(char nombre1[]);     // INGRESA EL NOMBRE DEL JUGADOR (MODO UN JUGADOR)

void MostrarBordesTurnoJug();                   // MUESTRA LOS BORDES EN EL TURNO DEL JUGADOR (RLUTIL)

void MostrarNombre1Jug(char nombre1[]);          // MUESTRA EL NOMBRE DEL JUGADOR 1 (INTERFAZ: TURNO -- MODO UN JUGADOR)

void InterfazTurno1Jug(int i,int TotalPartida,int Buncos,int LanzamientosPorRonda,int dados[],int maximo,int TotalRonda);
                                                // MUESTRA --> INTERFAZ: TURNO DEL JUGADOR

void InterfazRonda1Jug(int i,int TotalPartida,int Buncos,int tiradaFallida,int TotalLanzamientos,char nombre1[]);
                                                // MUESTRA --> INTERFAZ: RONDA DEL JUGADOR

void InterfazFinPartida1Jug(char nombre1[],int Buncos,int tiradaFallida,int tirosRealizados,int PuntajeDelJugador);
                                                // MUESTRA --> INTERFAZ: FIN DE LA PARTIDA

void cargarAleatorio(int v[], int tam);         // CARGA NUMEROS ALEATORIOS

void mostrarVector (int v[], int tam);          // MUESTRA EL VECTOR

void ordenarVector(int v[], int tam );          // ORDENA EL VECTOR

void ponerEnCero (int *a,int *b,int *c,int *d,int *e); // PONE EN 0 VARIABLES

int PuntajeTotal(int dados[], int puntos[], int tam, int ronda); // OBTIENE EL PUNTAJE TOTAL

int puntaje21(int v[], int ronda);              // PUNTAJE 21

int puntaje5(int v[], int ronda);               // PUNTAJE 5

int puntaje3(int v[]);                          // PUNTAJE 3

int puntaje2(int v[], int tam);                 // PUNTAJE 2

int puntaje1(int v[], int tam, int ronda);      // PUNTAJE 1

int BuscarMasGrande(int puntos[]);              // BUSCA EL VALOR MAXIMO DE LOS VECTORES PARA ANOTAR EL PUNTO CORRESPONDIENTE

int NombrePuntaje(int entero);                  // NOMBRA EL PUNTAJE EN LA INTERFAZ DE LOS JUGADORES


/////////////////////////DEFINICION DE LAS FUNCIONES////////////////////////////////////////

/////////////////////////FUNCIONES DE ENTRADA////////////////////////////////////////////////

int EjecutarMenu(int opcion){
    int j;
        setBackgroundColor(CYAN);
        setColor(WHITE);
        locate(38,8);printf("%c",201);
        locate(38,17);printf("%c",200);
        locate(82,8);printf("%c",187);
        locate(82,17);printf("%c",188);

            for(j=39;j<=81;j++){
                locate(j,8);printf("%c",205);
                locate(j,17);printf("%c",205);
            }
            for(j=9;j<=16;j++){
                locate(38,j);printf("%c",186);
                locate(82,j);printf("%c",186);
            }

                locate(40,10);cout<<"1. JUEGO NUEVO PARA UN JUGADOR."<<endl;
                locate(40,11);cout<<"2. JUEGO NUEVA PARA DOS JUGADORES."<<endl;
                locate(40,12);cout<<"3. MOSTRAR PUNTUACION MAS ALTA."<<endl;
                locate(40,13);cout<<"4. MODO SIMULADO (CARGA DE DADOS MANUAL)."<<endl;
                locate(40,14);cout<<"0. SALIR."<<endl;
                locate(40,15);cout << "SU OPCION: ";cin>>opcion;
                system("cls");
                return opcion;
}

void IngresoNombre1Jugador(char nombre1[]){
    locate(39,13);printf("%c",201);locate(39,15);printf("%c",200);
    locate(70,13);printf("%c",187);locate(70,15);printf("%c",188);
    locate(40,14);cout<<"INGRESE SU NOMBRE: ";cin>>nombre1;
    system("cls");
}

void cargarAleatorio(int v[], int tam){
    int i;
    srand(time(NULL));
        for(i=0;i<=tam;i++){
            v[i]=rand()%(6)+1;
        }
}
void mostrarVector (int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}
void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

void ponerEnCero (int *a,int *b,int *c,int *d,int *e){
    *a=*b=*c=*d=*e=0;
}

/////////////////////////FUNCIONES DE ENTADA////////////////////////////////////////////////


/////////////////////////SIMPLIFICACION DEL MODO 1 JUGADOR//////////////////////////////////

void MostrarBordesTurnoJug(){
        int j;
        locate(25,6);printf("%c",201);
        locate(25,20);printf("%c",200);
        locate(92,6);printf("%c",187);
        locate(92,20);printf("%c",188);
            for(j=26;j<=91;j++){
                locate(j,6);printf("%c",205);
                locate(j,20);printf("%c",205);
            }
            for(j=7;j<=19;j++){
                locate(92,j);printf("%c",186);
                locate(25,j);printf("%c",186);
            }
}

void MostrarNombre1Jug(char nombre1[]){
    locate(30,8);cout<<"TURNO DE: " <<nombre1;
}

void InterfazTurno1Jug(int i,int TotalPartida,int Buncos,int LanzamientosPorRonda,int dados[],int maximo,int TotalRonda){
            cout<< " | " << "RONDA NUMERO: " << i << " | " << "PUNTAJE ACUMULADO: " << TotalPartida << endl;
            locate(30,9);cout << "-----------------------------------------------------------" << endl;
            locate(30,10);cout << "VECES QUE OBTUVO BUNCO: " << Buncos << endl;
            locate(30,11);cout << "-----------------------------------------------------------" <<endl;
            locate(30,12);cout << "LANZAMIENTO NUMERO: " << LanzamientosPorRonda << endl;
            locate(30,13);cout << "-----------------------------------------------------------" << endl << endl;

            locate(30,16);cout << dados[0] << " " << dados[1] << " " << dados[2] << "    ";
            cout<< "PUNTAJE OBTENIDO: ";NombrePuntaje(maximo);
            locate(30,18);cout<< "PUNTAJE DE LA RONDA: "<<TotalRonda<<endl;
                anykey();
                system("cls");
}

void InterfazRonda1Jug(int i,int TotalPartida,int Buncos,int tiradaFallida,int TotalLanzamientos,char nombre1[]){
    int j;
    locate(40,7);printf("%c",201);
    locate(40,15);printf("%c",200);
    locate(75,7);printf("%c",187);
    locate(75,15);printf("%c",188);
        for(j=41;j<=74;j++){
        locate(j,7);printf("%c",205);
        locate(j,15);printf("%c",205);
        }
        for(j=8;j<=14;j++){
        locate(40,j);printf("%c",186);
        locate(75,j);printf("%c",186);
        }

                        locate(35,8);cout<< "\t\t" << "RONDA NUMERO: " << i << endl;
                        locate(35,9);cout << "\t----------------------------------" <<endl;
                        locate(35,10);cout<< "\t\t" << "PUNTAJE ";cout << nombre1;cout <<": " << TotalPartida << endl;
                        locate(35,11);cout<< "\t\t" << "BUNCOS: " << Buncos << endl;
                        locate(35,12);cout<< "\t\t" << "TIRADAS FALLIDAS: "<< tiradaFallida <<endl;
                        locate(35,13);cout<< "\t\t" << "LANZAMIENTOS: " << TotalLanzamientos << endl;
                        locate(35,14);cout << "\t----------------------------------" <<endl;
                                anykey();
                                system("cls");

}

void InterfazFinPartida1Jug(char nombre1[],int Buncos,int tiradaFallida,int tirosRealizados,int PuntajeDelJugador){
    int j;
        locate(30,6);printf("%c",201);
        locate(30,15);printf("%c",200);
        locate(100,6);printf("%c",187);
        locate(100,15);printf("%c",188);
            for(j=31;j<=99;j++){
                locate(j,6);printf("%c",205);
                locate(j,15);printf("%c",205);
            }
            for(j=7;j<=14;j++){
                locate(30,j);printf("%c",186);
                locate(100,j);printf("%c",186);
            }

                locate(35,8);cout<<"FINAL DE LA PARTIDA."<<endl;
                locate(35,9);cout<<"JUGADOR: "<<nombre1<<endl;
                locate(35,10);cout<<"CANTIDAD DE BUNCOS REALIZADOS: "<< Buncos <<endl;
                locate(35,11);cout<<"CANTIDAD DE TIRADAS FALLIDAS: "<< tiradaFallida<<endl;
                locate(35,12);cout<<"CANTIDAD DE TIROS NECESARIOS PARA COMPLETAR LAS 6 RONDAS: "<<tirosRealizados<<endl;
                locate(35,13);cout<<"PUNTAJE TOTAL ACUMULADO: "<<PuntajeDelJugador<<endl;
                    anykey();
                    system("cls");

}


/////////////////////////SIMPLIFICACION DEL MODO 1 JUGADOR//////////////////////////////////


///////////////////PUNTAJES/////////////////////////////////////////////////////////////////

int puntaje21(int v[], int ronda){
    int a,b,c;
        a=v[0];
        b=v[1];
        c=v[2];
            if(a==b&&b==c){
                if(ronda==a){
                    return 21;
                }
            }
    return 0;
}

int puntaje5(int v[], int ronda){
    int a,b,c;
        a=v[0];
        b=v[1];
        c=v[2];
            if(a==b&&b==c){
                if(ronda!=a){
                    return 5;
                }
            }
    return 0;
}

int puntaje3(int v[]){
    int a,b,c,suma;
        a=v[0];
        b=v[1];
        c=v[2];
        suma=a+b+c;
        if(suma%5==0){
            return 3;
        }
    return 0;
}

int puntaje2(int v[], int tam){
    int a,b,c;
    ordenarVector(v, tam);
    a=v[0];
    b=v[1];
    c=v[2];

    if(a+1==b&&b+1==c){
        return 2;
    }
    return 0;
}
int puntaje1(int v[], int tam, int ronda){
    int puntos=0,i;
        for(i=0;i<tam;i++){
            if(v[i]==ronda){
                puntos++;
            }
        }
    return puntos;
}


int BuscarMasGrande(int puntos[]){
    int i,maximo;
        maximo=puntos[0];
        for(i=1;i<=4;i++){
            if(puntos[i]>maximo){
                maximo=puntos[i];
            }
        }
    return maximo;
}

int NombrePuntaje(int entero){

    switch(entero){
        case 21: cout << "BUNCO" << endl;
                return 0;
                break;
        case 5:  cout << "CINCO PUNTOS" << endl;
                return 0;
                break;
        case 3:  cout << "TRES PUNTOS" << endl;
                return 0;
                break;
        case 2:  cout << "DOS PUNTOS" << endl;
                return 0;
                break;
        case 1:  cout << "UN PUNTO" << endl;
                return 0;
                break;
        default: cout<<"TIRADA FALLIDA" <<endl;
            return 0;
            break;
    }

}

int PuntajeTotal(int dados[], int puntos[], int tam, int ronda){
    int i,maximo;
    for (i=0;i<5;i++){
        puntos[i]=0;
    }
    puntos[0]=puntaje21(dados,ronda);
    puntos[1]=puntaje5(dados,ronda);
    puntos[2]=puntaje3(dados);
    puntos[3]=puntaje2(dados,tam);
    puntos[4]=puntaje1(dados,tam,ronda);
    maximo=BuscarMasGrande(puntos);

    return maximo;
}




///////////////////PUNTAJES////////////////////////////////////////////////////////////


#endif // FUNCIONES_H_INCLUDED
