#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;

#include "funciones.h"
#include "rlutil.h"

using namespace rlutil;

int main(){
    const int tam=3;
    int opcion=-1,selec,i;
    int dados[3],puntos[5],maximo;
    int tiradaFallida,TotalPartida,TotalRonda,PuntajeDelJugador;
    int Buncos,tirosRealizados,TotalLanzamientos,LanzamientosPorRonda;
    char nombre1[10],nombre2[10];
    int TotalLanzamientos1,tirosRealizados1,tiradaFallida1,Buncos1,TotalPartida1,LanzamientosPorRonda1,TotalRonda1;
    int TotalLanzamientos2,tirosRealizados2,tiradaFallida2,Buncos2,TotalPartida2,LanzamientosPorRonda2,TotalRonda2;
    bool control,controlPrimerTiro;

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
                                DibujarDados(dados,tam);
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

        //////EMPIEZA: INTERFAZ DURANTE EL TURNO DEL JUGADOR///
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

            case 2: IngresoNombre2Jugadores(nombre1,nombre2);

                    ponerEnCero(&TotalLanzamientos1,&tirosRealizados1,&tiradaFallida1,&Buncos1,&TotalPartida1);
                    ponerEnCero(&TotalLanzamientos2,&tirosRealizados2,&tiradaFallida2,&Buncos2,&TotalPartida2);
                    control=true;

                    for(i=1;i<=6;i++){
                        LanzamientosPorRonda1=0;
                        TotalRonda1=0;
                        LanzamientosPorRonda2=0;
                        TotalRonda2=0;
                        controlPrimerTiro=false;
                            while(TotalRonda1<21&&TotalRonda2<21){

                                    while(TotalRonda1<21&&control==true){ //jugador 1

                                        cargarDados(dados,tam);
                                        //cargarAleatorio(dados,tam);
                                        DibujarDados(dados,tam);
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

    MostrarBordesTurnoJug();
    MostrarNombre1Jug(nombre1);
    InterfazTurno1Jug(i,TotalPartida1,Buncos1,LanzamientosPorRonda1,dados,maximo,TotalRonda1);

////////////////////////////TERMINA: INTERFAZ DURANTE EL TURNO DEL PRIMER JUGADOR///////////////////////////

                                    }
                        ////////////////////////EMPIEZA: INTERFAZ ENTRE RONDA Y RONDA ////////////////////////
                                    InterfazRonda2Jug_N1(i,nombre2,nombre1,Buncos1,Buncos2,TotalPartida1,TotalPartida2);

                        ////////////////////////TERMINA: INTERFAZ ENTRE RONDA Y RONDA ////////////////////////
                                    control=true;
                                    if(TotalRonda1<21||controlPrimerTiro==false){

                                        while(TotalRonda2<21&&control==true){ // jugador 2

                                            cargarDados(dados,tam);
                                            //cargarAleatorio(dados,tam);
                                            DibujarDados(dados,tam);
                                            TotalLanzamientos2++;
                                            LanzamientosPorRonda2++;
                                            maximo=PuntajeTotal(dados,puntos,tam,i);

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

    MostrarBordesTurnoJug();
    MostrarNombre1Jug(nombre2);
    InterfazTurno1Jug(i,TotalPartida2,Buncos2,LanzamientosPorRonda2,dados,maximo,TotalRonda2);

////////////////////////////TERMINA: INTERFAZ DURANTE EL TURNO DEL SEGUNDO JUGADOR///////////////////////////

                                        }
                                    }
                    InterfazRonda2Jug_N2(i,nombre2,nombre1,Buncos1,Buncos2,TotalPartida1,TotalPartida2);

                                control=true;
                            }
                    }
                    ///FIN DE LA PARTIDA///////////
                    Fin_Partida(nombre1,nombre2,TotalPartida1,TotalPartida2,Buncos1,Buncos2);
                    break;
            case 3: PuntuacionMaxima(selec,nombre1,nombre2,Buncos,Buncos1,Buncos2,TotalPartida,TotalPartida1,TotalPartida2);
                break;

            case 4: IngresoNombre1Jugador(nombre1);
                    ponerEnCero(&TotalLanzamientos,&tirosRealizados,&tiradaFallida,&Buncos,&TotalPartida);
                    for(i=1;i<=6;i++){
                        LanzamientosPorRonda=0;
                        TotalRonda=0;
                            while(TotalRonda<21){
                                cargarDados(dados,tam);
                                DibujarDados(dados,tam);
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

        //////EMPIEZA: INTERFAZ DURANTE EL TURNO DEL JUGADOR///
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

                break;

            case 0: cout << "FIN DEL JUEGO" << endl;
                    return 0;
                    break;

            default: locate(30,10);cout<<"ERROR DE NUMERO. INTENTE DE NUEVO."<<endl;
                    anykey();
                    system("cls");
                    break;
        }


    }

    return 0;
}
