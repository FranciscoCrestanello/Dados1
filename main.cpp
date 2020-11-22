#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
//#include<windows.h>
using namespace std;

#include "funciones.h"
#include "rlutil.h"

using namespace rlutil;

int main(){
    const int tam=3;
    int opcion,i,j;
    int dados[3],puntos[5],maximo;
    int tiradaFallida;
    int TotalPartida, TotalRonda,PuntajeDelJugador;
    int Buncos,tirosRealizados,TotalLanzamientos,LanzamientosPorRonda;
    char nombre1[10],nombre2[10];

    int TotalLanzamientos1,tirosRealizados1,tiradaFallida1,Buncos1,TotalPartida1;
    int LanzamientosPorRonda1,TotalRonda1;
    bool control=true;
    int TotalLanzamientos2,tirosRealizados2,tiradaFallida2,Buncos2,TotalPartida2;
    int LanzamientosPorRonda2,TotalRonda2;

    while(opcion!=0){
        opcion=EjecutarMenu(opcion);
        switch(opcion){
            case 1: IngresoNombre1Jugador(nombre1);
                    ponerEnCero(&TotalLanzamientos,&tirosRealizados,&tiradaFallida,&Buncos,&TotalPartida);
                    for(i=1;i<=6;i++){
                        LanzamientosPorRonda=0;
                        TotalRonda=0;
                            while(TotalRonda<21){
                                cargarAleatorio(dados,tam);
                                TotalLanzamientos++;
                                LanzamientosPorRonda++;
                                maximo=PuntajeTotal(dados,puntos,tam,i);
                                        if(maximo==0){
                                            tiradaFallida++;
                                        }
                                        if(maximo==21){
                                            Buncos++;
                                        }

                                        tirosRealizados++;
                                        TotalRonda+=maximo;
                                        TotalPartida+=maximo;

        ///EMPIEZA: INTERFAZ DURANTE EL TURNO DEL JUGADOR///
            MostrarBordesTurnoJug();
            MostrarNombre1Jug(nombre1);
            InterfazTurno1Jug(i,TotalPartida,Buncos,LanzamientosPorRonda,dados,maximo,TotalRonda);

////////////////////////////TERMINA: INTERFAZ DURANTE EL TURNO DEL JUGADOR///////////////////////////
                            }
////////////////////////////EMPIEZA: INTERFAZ ENTRE RONDA Y RONDA////////////////////////////////////

                        InterfazRonda1Jug(i,TotalPartida,Buncos,tiradaFallida,TotalLanzamientos,nombre1);

/////////////////////////////////TERMINA: INTERFAZ ENTRE RONDA Y RONDA/////////////////////////////////
                    }
                                PuntajeDelJugador=TotalPartida-(tiradaFallida*2);
///////////////////////////////////EMPIEZA: INTERFAZ FIN DE LA PARTIDA//////////////////////////////////////////
        InterfazFinPartida1Jug(nombre1,Buncos,tiradaFallida,tirosRealizados,PuntajeDelJugador);

                                break;
//////////////////////////////////TERMINA: INTERFAZ DE LA PARTIDA////////////////////////////////////////////

            case 2: cout<<"INGRESE EL NOMBRE DEL PRIMER JUGADOR: ";cin>>nombre1;
                    cout<<"INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: ";cin>>nombre2;
                    system("cls");
                    ponerEnCero(&TotalLanzamientos1,&tirosRealizados1,&tiradaFallida1,&Buncos1,&TotalPartida1);
                    ponerEnCero(&TotalLanzamientos2,&tirosRealizados2,&tiradaFallida2,&Buncos2,&TotalPartida2);

                    for(i=1;i<=6;i++){
                        LanzamientosPorRonda1=0;
                        TotalRonda1=0;
                        LanzamientosPorRonda2=0;
                        TotalRonda2=0;
                            while(TotalRonda1<21&&TotalRonda2<21){ //jugador 1

                                    while(TotalRonda1<21&&control==true){

                                    /*for(x=0;x<=2;x++){                              // CON ESTE FOR INGRESO LOS NUMEROS->
                                    cout<<"INGRESE EL DADO N_"<<x+1<<":";       // ->PARA PROBAR SI FUNCIONA EL PROGRAMA
                                    cin>>dados[x];
                                    }*/

                                        cargarAleatorio(dados,tam);
                                        TotalLanzamientos1++;
                                        LanzamientosPorRonda1++;
                                        maximo=PuntajeTotal(dados,puntos,tam,i);

                                        if(maximo==0){
                                            tiradaFallida1++;
                                            control=false;
                                        }
                                        if(maximo==21){
                                            Buncos1++;
                                        }
                                        tirosRealizados1++;
                                        TotalRonda1+=maximo;
                                        TotalPartida1+=maximo;

//////////////////////EMPIEZA: INTERFAZ DURANTE EL TURNO DEL PRIMER JUGADOR////////////////////////////

    //mostrarNombre(nombre1);
    //InterfazTurnoJugador(i,TotalPartida1,Buncos1,LanzamientosPorRonda1,dados,maximo,TotalRonda1);
    cout << "TURNO DE: " << nombre1 << " | " << "RONDA NUMERO: " << i << " | " << "PUNTAJE ACUMULADO: " << TotalPartida1 << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "VECES QUE OBTUVO BUNCO: " << Buncos1 << endl;
    cout << "-----------------------------------------------------------" <<endl;
    cout << "LANZAMIENTO NUMERO: " << LanzamientosPorRonda1 << endl;
    cout << "-----------------------------------------------------------" << endl << endl;

        cout << dados[0] << " " << dados[1] << " " << dados[2] << "    ";
        cout<< "PUNTAJE OBTENIDO: ";
        NombrePuntaje(maximo);
        cout<< "PUNTAJE DE LA RONDA: "<<TotalRonda1<<endl;

            anykey();
            system("cls");

////////////////////////////TERMINA: INTERFAZ DURANTE EL TURNO DEL PRIMER JUGADOR///////////////////////////

                                    }
                        ////////////////////////EMPIEZA: INTERFAZ ENTRE RONDA Y RONDA ////////////////////////

                                            cout << "RONDA NUMERO: " << i << endl;
                                            cout << "PROXIMO TURNO: " << nombre2<< endl;
                                            cout << "---------------------------------------" << endl;
                                            cout << "PUNTAJE " << nombre1 <<": "<< TotalPartida1 << " PUNTOS" << endl;
                                            cout << "CANTIDAD DE BUNCOS: "<< Buncos1 <<endl;
                                            cout << "---------------------------------------" << endl;
                                            cout << "PUNTAJE "<<nombre2<<": " << TotalPartida2 << " PUNTOS" << endl;
                                            cout << "CANTIDAD DE BUNCOS: "<< Buncos2 <<endl;
                                            anykey();
                                            system("cls");
                        ////////////////////////TERMINA: INTERFAZ ENTRE RONDA Y RONDA ////////////////////////
                                    control=true;

                                        while(TotalRonda2<21&&control==true){ // jugador 2

                                        /*for(x=0;x<=2;x++){                              // CON ESTE FOR INGRESO LOS NUMEROS->
                                        cout<<"INGRESE EL DADO N_"<<x+1<<":";       // ->PARA PROBAR SI FUNCIONA EL PROGRAMA
                                        cin>>dados[x];
                                        }*/

                                            cargarAleatorio(dados,tam);
                                            TotalLanzamientos2++;
                                            LanzamientosPorRonda2++;
                                            maximo=PuntajeTotal(dados,puntos,tam,i);
                                            NombrePuntaje(maximo);

                                            if(maximo==0){
                                                tiradaFallida2++;
                                                control=false;
                                            }
                                            if(maximo==21){
                                                Buncos2++;
                                            }
                                            tirosRealizados2++;
                                            TotalRonda2+=maximo;
                                            TotalPartida2+=maximo;

//////////////////////EMPIEZA: INTERFAZ DURANTE EL TURNO DEL SEGUNDO JUGADOR////////////////////////////

    //mostrarNombre(nombre2);
    //InterfazTurnoJugador(i,TotalPartida2,Buncos2,LanzamientosPorRonda2,dados,maximo,TotalRonda2);
    cout << "TURNO DE: " << nombre2 << " | " << "RONDA NUMERO: " << i << " | " << "PUNTAJE ACUMULADO: " << TotalPartida2 << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "VECES QUE OBTUVO BUNCO: " << Buncos2 << endl;
    cout << "-----------------------------------------------------------" <<endl;
    cout << "LANZAMIENTO NUMERO: " << LanzamientosPorRonda2 << endl;
    cout << "-----------------------------------------------------------" << endl << endl;

        cout << dados[0] << " " << dados[1] << " " << dados[2] << "    ";
        cout<< "PUNTAJE OBTENIDO: ";
        NombrePuntaje(maximo);
        cout<< "PUNTAJE DE LA RONDA: "<<TotalRonda2<<endl;

            anykey();
            system("cls");
////////////////////////////TERMINA: INTERFAZ DURANTE EL TURNO DEL SEGUNDO JUGADOR///////////////////////////

                                        }
                                            cout << "RONDA NUMERO: " << i << endl;
                                            cout << "PROXIMO TURNO: " << nombre1<< endl;
                                            cout << "---------------------------------------" << endl;
                                            cout << "PUNTAJE " << nombre2 <<": "<< TotalPartida2 << " PUNTOS" << endl;
                                            cout << "CANTIDAD DE BUNCOS: "<< Buncos2 <<endl;
                                            cout << "---------------------------------------" << endl;
                                            cout << "PUNTAJE "<<nombre1<<": " << TotalPartida1 << " PUNTOS" << endl;
                                            cout << "CANTIDAD DE BUNCOS: "<< Buncos1 <<endl;
                                            anykey();
                                            system("cls");

                                control=true;
                            }


                    }
                    ///FIN DE LA PARTIDA///////////
                        if(TotalPartida1>TotalPartida2){
                            cout<<"FINAL DE LA PARTIDA"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"GANADOR: "<<nombre1<<endl;
                            cout<<"CANTIDAD DE BUNCOS: "<< Buncos1<<endl;
                            cout<<"PUNTAJE TOTAL ACUMULADO: "<<TotalPartida1<<endl;
                        }
                        if(TotalPartida2>TotalPartida1){
                            cout<<"FINAL DE LA PARTIDA"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"GANADOR: "<<nombre2<<endl;
                            cout<<"CANTIDAD DE BUNCOS: "<< Buncos2<<endl;
                            cout<<"PUNTAJE TOTAL ACUMULADO: "<<TotalPartida2<<endl;
                        }
                        if(TotalPartida2==TotalPartida1){
                            if(Buncos1>Buncos2){
                                cout<<"FINAL DE LA PARTIDA"<<endl;
                                cout<<"------------------------------------"<<endl;
                                cout<<"GANADOR: "<<nombre1<<endl;
                                cout<<"CANTIDAD DE BUNCOS: "<< Buncos1<<endl;
                                cout<<"PUNTAJE TOTAL ACUMULADO: "<<TotalPartida1<<endl;
                            }
                            else{
                                if(Buncos2>Buncos1){
                                    cout<<"FINAL DE LA PARTIDA"<<endl;
                                    cout<<"------------------------------------"<<endl;
                                    cout<<"GANADOR: "<<nombre2<<endl;
                                    cout<<"CANTIDAD DE BUNCOS: "<< Buncos2<<endl;
                                    cout<<"PUNTAJE TOTAL ACUMULADO: "<<TotalPartida2<<endl;
                                }
                            }
                        }
                        if(TotalPartida2==TotalPartida1&&Buncos1==Buncos2){
                            cout<<"FINAL DE LA PARTIDA"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"EMPATE"<<endl;
                            cout<<"AMBOS JUGADORES TIENEN LA MISMA"<<endl;
                            cout<<"CANTIDAD DE PUNTOS Y BUNCOS"<<endl;
                        }
                            anykey();
                            system("cls");
                    break;

            case 0: cout << "FIN DEL JUEGO" <<endl;
                    return 0;
                    break;

            default: locate(30,10);
                    cout<<"ERROR DE NUMERO. INTENTE DE NUEVO."<<endl;
                    anykey();
                    system("cls");
                    break;
        }


    }

    return 0;
}
