#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/////////////////////////DEFINICION DE LAS FUNCIONES////////////////////////////////////////

void cargarAleatorio(int v[], int tam);         // CARGA NUMEROS ALEATORIOS

void mostrarVector (int v[], int tam);          // MUESTRA EL VECTOR

void ordenarVector(int v[], int tam );          // ORDENA EL VECTOR

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


/////////////////////////FUNCIONES DE ENTADA////////////////////////////////////////////////

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
