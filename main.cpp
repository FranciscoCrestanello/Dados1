#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<windows.h>
using namespace std;

#include "funciones.h"
#include "rlutil.h"

using namespace rlutil;

int main(){
    const int tam=3;
    int opcion,x,i,j;
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

        switch(opcion){
            case 1:
                    locate(39,13);printf("%c",201);locate(39,15);printf("%c",200);
                    locate(70,13);printf("%c",187);locate(70,15);printf("%c",188);
                    locate(40,14);cout<<"INGRESE SU NOMBRE: ";cin>>nombre1;
                    system("cls");

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

            locate(30,8);cout<<"TURNO DE: " <<nombre1<< " | " << "RONDA NUMERO: " << i << " | " << "PUNTAJE ACUMULADO: " << TotalPartida << endl;
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


////////////////////////////TERMINA: INTERFAZ DURANTE EL TURNO DEL JUGADOR///////////////////////////
                            }
////////////////////////////EMPIEZA: INTERFAZ ENTRE RONDA Y RONDA////////////////////////////////////

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
                        locate(35,10);cout<< "\t\t" << "PUNTAJE " <<nombre1 <<": " << TotalPartida << endl;
                        locate(35,11);cout<< "\t\t" << "BUNCOS: " << Buncos << endl;
                        locate(35,12);cout<< "\t\t" << "TIRADAS FALLIDAS: "<< tiradaFallida <<endl;
                        locate(35,13);cout<< "\t\t" << "LANZAMIENTOS: " << TotalLanzamientos << endl;
                        locate(35,14);cout << "\t----------------------------------" <<endl;
                                anykey();
                                system("cls");
/////////////////////////////////TERMINA: INTERFAZ ENTRE RONDA Y RONDA/////////////////////////////////
                    }
                                PuntajeDelJugador=TotalPartida-(tiradaFallida*2);
///////////////////////////////////EMPIEZA: INTERFAZ FIN DE LA PARTIDA//////////////////////////////////////////
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
                                break;
//////////////////////////////////TERMINA: INTERFAZ DE LA PARTIDA////////////////////////////////////////////

            case 2: cout<<"INGRESE EL NOMBRE DEL PRIMER JUGADOR: ";cin>>nombre1;
                    cout<<"INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: ";cin>>nombre2;

                    ponerEnCero(&TotalLanzamientos1,&tirosRealizados1,&tiradaFallida1,&Buncos1,&TotalPartida1);
                    ponerEnCero(&TotalLanzamientos2,&tirosRealizados2,&tiradaFallida2,&Buncos2,&TotalPartida2);

                    for(i=1;i<=6;i++){
                        LanzamientosPorRonda1=0;
                        TotalRonda1=0;
                        LanzamientosPorRonda2=0;
                        TotalRonda2=0;
                            while(TotalRonda1<21&&TotalRonda2<21){ //jugador 1

                                    while(TotalRonda1<21&&control==true){

                                    for(x=0;x<=2;x++){                              // CON ESTE FOR INGRESO LOS NUMEROS->
                                    cout<<"INGRESE EL DADO N_"<<x+1<<":";       // ->PARA PROBAR SI FUNCIONA EL PROGRAMA
                                    cin>>dados[x];
                                    }

                                        //cargarAleatorio(dados,tam);
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
                                            system("pause");
                                            system("cls");
                        ////////////////////////TERMINA: INTERFAZ ENTRE RONDA Y RONDA ////////////////////////
                                    control=true;

                                        while(TotalRonda2<21&&control==true){ // jugador 2

                                        for(x=0;x<=2;x++){                              // CON ESTE FOR INGRESO LOS NUMEROS->
                                        cout<<"INGRESE EL DADO N_"<<x+1<<":";       // ->PARA PROBAR SI FUNCIONA EL PROGRAMA
                                        cin>>dados[x];
                                        }

                                            //cargarAleatorio(dados,tam);
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
        ///mostrarVector(dados);
        cout<< "PUNTAJE OBTENIDO: ";
        NombrePuntaje(maximo);
        cout<< "PUNTAJE DE LA RONDA: "<<TotalRonda2<<endl;

            system("pause");
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
                                            system("pause");
                                            system("cls");

                                control=true;
                            }

                                system("pause");
                                system("cls");

                    }

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
