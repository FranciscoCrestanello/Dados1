#ifndef FUNCIONESRESUMENJUG1_H_INCLUDED
#define FUNCIONESRESUMENJUG1_H_INCLUDED

/////////////////////////RESUMEN DE FUNCIONES/////////////////////////////////
void mostrarNombre(char nombre[]);

void InterfazTurnoJugador1(int i, int TotalPartida, int Buncos, int LanzamientosPorRonda, int dados[], int maximo, int TotalRonda);

void ponerEnCero (int *a,int *b,int *c,int *d,int *e);


/////////////////////////RESUMEN DE FUNCIONES/////////////////////////////////

void ponerEnCero (int *a,int *b,int *c,int *d,int *e){
    *a=*b=*c=*d=*e=0;
}



void mostrarNombre(char nombre[]){
    cout<<"TURNO DE: " <<nombre;
}

void InterfazTurnoJugador(int i, int TotalPartida, int Buncos, int LanzamientosPorRonda, int dados[], int maximo, int TotalRonda){

    cout << " | " << "RONDA NUMERO: " << i << " | " << "PUNTAJE ACUMULADO: " << TotalPartida << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "VECES QUE OBTUVO BUNCO: " << Buncos << endl;
    cout << "-----------------------------------------------------------" <<endl;
    cout << "LANZAMIENTO NUMERO: " << LanzamientosPorRonda << endl;
    cout << "-----------------------------------------------------------" << endl << endl;

        cout << dados[0] << " " << dados[1] << " " << dados[2] << "    ";
        cout<< "PUNTAJE OBTENIDO: ";
        NombrePuntaje(maximo);
        cout<< "PUNTAJE DE LA RONDA: "<<TotalRonda<<endl;
            system("pause");
            system("cls");

}

void RondaParte1(int i){
                                cout<< "RONDA NUMERO: " << i << endl;
        cout << "-----------------------------------------------------------" <<endl;

}
void RondaParte2 (char nombre1[]){
    cout<< "PUNTAJE " <<nombre1;
}

void RondaParte3(int TotalPartida, int Buncos, int tiradaFallida, int TotalLanzamientos){
        cout<<": " << TotalPartida << endl;
        cout<< "BUNCOS: " << Buncos << endl;
        cout<< "TIRADAS FALLIDAS: "<< tiradaFallida <<endl;
        cout<< "LANZAMIENTOS: " << TotalLanzamientos << endl;
        cout << "-----------------------------------------------------------" <<endl;
                system("pause");
                system("cls");
}

void FIN_PARTIDA(int Buncos, int tiradaFallida, int tirosRealizados, int PuntajeDelJugador){
        cout<<"CANTIDAD DE BUNCOS REALIZADOS: "<< Buncos <<endl;
        cout<<"CANTIDAD DE TIRADAS FALLIDAS: "<< tiradaFallida<<endl;
        cout<<"CANTIDAD DE TIROS NECESARIOS PARA COMPLETAR LAS 6 RONDAS: "<<tirosRealizados<<endl;
        cout<<"PUNTAJE TOTAL ACUMULADO: "<<PuntajeDelJugador<<endl;
                system("pause");
                system("cls");
}







#endif // FUNCIONESRESUMENJUG1_H_INCLUDED
