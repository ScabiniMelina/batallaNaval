
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
void Gotoxy(int x, int y){
HANDLE hcon;
hcon=GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X=x;
dwPos.Y=y;
SetConsoleCursorPosition(hcon,dwPos);
}
struct participantes{
        string nombre;
        char tablero[10][10];
        int capturas;
    };
void horizontales(int hInicio,int hFinal,int vInicio, int vFinal ){
    char carac=205;
    for(int x = hInicio; x <=hFinal ; x++){                  // DOBLE LINEA SUPERIO E INFERIOR
        Gotoxy(x,vInicio);
        cout << carac;
        Gotoxy(x,vFinal);
        cout << carac;
            if(x>=2 && x<= hFinal-2){
             Gotoxy(x,vInicio+1);
            cout << carac;
            Gotoxy(x,vFinal-1);
            cout << carac;
           }
    }
}
void verticales( int hInicio,int hFinal,int vInicio, int vFinal){
    char carac=186;
    for(int x = vInicio; x <=vFinal ; x++){         //LINEAS VERTICALES INICIO FINAL
        Gotoxy(hInicio,x); cout << carac;
        Gotoxy(hFinal,x); cout << carac;
            if(x>=2 && x<= vFinal-2){
                Gotoxy(hInicio+2,x); cout << carac;
                Gotoxy(hFinal-2,x); cout << carac;
            }}
    carac=187;                                    //ESQUINAS
    Gotoxy(hFinal,vInicio); cout << carac;
    Gotoxy(hFinal-2,vInicio+1); cout << carac;
    carac=201;
    Gotoxy(hInicio,vInicio); cout << carac;
    Gotoxy(hInicio+2,vInicio+1); cout << carac;
    carac=200;
    Gotoxy(hInicio,vFinal);cout << carac;
    Gotoxy(hInicio+2,vFinal-1); cout << carac;
    carac=188;
    Gotoxy(hFinal,vFinal); cout << carac;
    Gotoxy(hFinal-2,vFinal-1); cout << carac;
}
void aux(int hInicio,int hFinal,int vInicio, int vFinal){
    char carac=205;
    for(int x = hInicio+2; x <=hFinal-2 ; x++){     //LINEA VERTICAL A 3/4 DE LA PANTALLA
        Gotoxy(x,30);  cout << carac;}
        carac=185;
        Gotoxy(hFinal-2,30);  cout << carac;
        carac=204;
        Gotoxy(hInicio+2,30); cout << carac;
        carac=186;
        for(int x = vInicio+2; x <=29 ; x++){        //LINEA VERTICAL CENTRADA
            Gotoxy(70,x);
            cout<<carac;
        }
    carac=202;
    Gotoxy(70,30); cout << carac;
    carac=203;
    Gotoxy(70,vInicio+1); cout << carac;
 }
int cambioJugador ( int jugador){
    if (jugador == 0 ){
        jugador = 1 ;
    }else {
        jugador = 0;
    }
    return jugador;}

void dibujoBarcosInicioFinal(int pantalla){
int x,y;
char tecla=92;
if(pantalla==1){
x=27;y=3;
}else{
x=27;y=28;
}
Gotoxy(x,y);cout<<"                                      ~    ~    ~               " <<endl;y++;
Gotoxy(x,y);cout<<"                                     |    |    |                "<<endl;y++;
Gotoxy(x,y);cout<<"           _~           "<<"            )_)  )_)  )_)               "<<"           _~           "<<endl;y++;
Gotoxy(x,y);cout<<"       _~ )_)_~        "<<"            )___))___))___)              "<<"       _~ )_)_~        "<<endl;y++;
Gotoxy(x,y);cout<<"      )_))_))_)        "<<"           )____)____)_____)             "<<"      )_))_))_)        "<<endl;y++;
Gotoxy(x,y);cout<<"     __!__!__!__       "<<"         _____|____|____|_____           "<<"     __!__!__!__       "<<endl;y++;
Gotoxy(x,y);cout<<"   ~~"<<tecla<<"         /~~~"<<"    ~~~~~~~~~"<<tecla<<"                   /~~~~~~~~~  "<<"   ~~"<<tecla<<"         /~~~"<<endl;y++;
Gotoxy(x,y);cout<<"      ^^^^^^^^^          "<<"  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^            "<<"    ^^^^^^^^^          "<<endl;y++;
Gotoxy(x,y);cout<<"    ^^^^      ^^^^     ^^^             ^^ "<<"         ^^^^      ^^^                     "<<endl;y++;
Gotoxy(x,y);cout<<"         ^^^^      ^^^                     "<<"    ^^^^      ^^^^     ^^^    ^^          "<<endl;y++;
}
void dibujoBarcos(int barcoAct){
char carac=219,tecla=92;;
int x,y;
HANDLE  hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
if(barcoAct==1 || barcoAct==2|| barcoAct==4||barcoAct==3 ){
    x=74;y=20;
    SetConsoleTextAttribute(hConsole, 63);
 }
if(barcoAct==0 || barcoAct==1){
    if(barcoAct==0){
         x=4,y=7;
    }
    Gotoxy(x,y);cout<<"         _~       ";y++;
    Gotoxy(x,y);cout<<"        )_)_~     ";y++;
    Gotoxy(x,y);cout<<"        )_))_)    ";y++;
    Gotoxy(x,y);cout<<" A     _!__!__  1 ";y++;
    Gotoxy(x,y);cout<<"      |      /    ";y++;
    Gotoxy(x,y);cout<<"      ^^^^^^^     " ;y++;
    Gotoxy(x,y);cout<<"                  ";y=y+1;
    Gotoxy(x,y);cout<<"        "<<carac<<carac<<carac<<"       ";y=y+1;
    Gotoxy(x,y);cout<<"         1        ";y=y+2;
}
if(barcoAct==0 || barcoAct==2){
    if(barcoAct==0){
         x=4;
    }
    Gotoxy(x,y);cout<<"           _~        ";y++;
    Gotoxy(x,y);cout<<"          )_)_~      ";y++;
    Gotoxy(x,y);cout<<"         )_))_)      ";y++;
    Gotoxy(x,y);cout<<" B     __!__!__    2 ";y++;
    Gotoxy(x,y);cout<<"      |        /     ";y++;
    Gotoxy(x,y);cout<<"      ^^^^^^^^^      ";y++;
    Gotoxy(x,y);cout<<"                     ";y++;
    Gotoxy(x,y);cout<<"       "<<carac<<carac<<carac<<"  "<<carac<<carac<<carac<<"      ";y=y+1;
    Gotoxy(x,y);cout<<"        1    2       ";y=y+2;
}
if(barcoAct==0 || barcoAct==3){
    if(barcoAct==0){
         x=36,y=y-10;
    }
    Gotoxy(x,y);cout<<"           _~       ";y++;
    Gotoxy(x,y);cout<<"       _~ )_)_~     ";y++;
    Gotoxy(x,y);cout<<"      )_))_))_)     ";y++;
    Gotoxy(x,y);cout<<" C   __!__!__!__  3 ";y++;
    Gotoxy(x,y);cout<<"     "<<tecla<<"         /";y++;
    Gotoxy(x,y);cout<<"      ---------     ";y++;
    Gotoxy(x,y);cout<<"                     ";y++;
    Gotoxy(x,y);cout<<"      "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" ";y++;
    Gotoxy(x,y);cout<<"       1   2   3     ";y=y+2;
}
if(barcoAct==0 || barcoAct==4){
    if(barcoAct==0){
        x=36; y=5;
    }else{
     y=y-2;}
    Gotoxy(x,y);cout<<"        ~    ~    ~      ";y++;
    Gotoxy(x,y);cout<<"       |    |    |       ";y++;
    Gotoxy(x,y);cout<<"      )_)  )_)  )_)      ";y++;
    Gotoxy(x,y);cout<<"     )___))___))___)     ";y++;
    Gotoxy(x,y);cout<<"    )____)____)_____)    ";y++;
    Gotoxy(x,y);cout<<" D  ___|____|____|___  4 ";y++;
    Gotoxy(x,y);cout<<"    "<<tecla<<"               /    ";y++;
    Gotoxy(x,y);cout<<"  ^^^^^^^^^^^^^^^^^^^^   ";y++;
    Gotoxy(x,y);cout<<"                         ";y++;
    Gotoxy(x,y);cout<<"     "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<"     ";y++;;
    Gotoxy(x,y);cout<<"      1   2   3   4      ";y=y+2;

    }
 SetConsoleTextAttribute(hConsole, 31);
}

void inicio(int hInicio,int hFinal,int vInicio, int vFinal){
dibujoBarcosInicioFinal(0);
horizontales(hInicio,hFinal,vInicio,vFinal);
verticales(hInicio, hFinal, vInicio, vFinal);

char carac;
int x=32, y=4;

Gotoxy(x,y);cout << "888888b.         d8888 88888888888     d8888 888      888             d8888 "<<endl;y++;
Gotoxy(x,y);cout << "888   88b       d88888     888        d88888 888      888            d88888 "<<endl;y++;
Gotoxy(x,y);cout << "888  .88P      d88P888     888       d88P888 888      888           d88P888 "<<endl;y++;
Gotoxy(x,y);cout << "8888888K.     d88P 888     888      d88P 888 888      888          d88P 888 "<<endl;y++;
Gotoxy(x,y);cout << "888   Y88b   d88P  888     888     d88P  888 888      888         d88P  888 "<<endl;y++;
Gotoxy(x,y);cout << "888    888  d88P   888     888    d88P   888 888      888        d88P   888 "<<endl;y++;
Gotoxy(x,y);cout << "888   d88P d8888888888     888   d8888888888 888      888       d8888888888 "<<endl;y++;
Gotoxy(x,y);cout << "8888888P  d88P     888     888  d88P     888 88888888 88888888 d88P     888 "<<endl;y++;

x=43, y=14;
Gotoxy(x,y);cout << "888b    888        d8888 888     888     d8888 888      "<<endl;y++;
Gotoxy(x,y);cout << "8888b   888       d88888 888     888    d88888 888      "<<endl;y++;
Gotoxy(x,y);cout << "88888b  888      d88P888 888     888   d88P888 888      "<<endl;y++;
Gotoxy(x,y);cout << "888Y88b 888     d88P 888 Y88b   d88P  d88P 888 888      "<<endl;y++;
Gotoxy(x,y);cout << "888 Y88b888    d88P  888  Y88b d88P  d88P  888 888      "<<endl;y++;
Gotoxy(x,y);cout << "888  Y88888   d88P   888   Y88o88P  d88P   888 888      "<<endl;y++;
Gotoxy(x,y);cout << "888   Y8888  d8888888888    Y888P  d8888888888 888      "<<endl;y++;
Gotoxy(x,y);cout << "888    Y888 d88P     888     Y8P  d88P     888 88888888 "<<endl;y++;
carac=175;
Gotoxy((140-40)/2,24); cout << carac << " Presione cualquier tecla para continuar";
Gotoxy((140-10)/2,26); cout << carac << " x. Salir" <<endl;
}
void reglas(int hInicio,int hFinal,int vInicio, int vFinal ){

    horizontales(hInicio,hFinal,vInicio,vFinal);
    verticales(hInicio, hFinal, vInicio, vFinal);
    aux(hInicio, hFinal, vInicio, vFinal);

    char carac=175;

    Gotoxy((140-40)/2,33); cout << carac << " Presione cualquier tecla para continuar";      //INSTRUCCIONES PRINCIPALES
    Gotoxy( (140-10)/2,36); cout << carac << " x. Salir" << endl;
                                                                                            //REGLAS Y COMO JUGAR
    Gotoxy(30,3);cout << "BARCOS Y TAMAÑOS";
    Gotoxy(95,3);cout << "OBJETIVO DEL JUEGO";
    Gotoxy(98,9);cout << "COMO JUGAR";
    Gotoxy(88,22);cout<<"RESULTADOS POSIBLES DEL ESTADO:";

    Gotoxy(74,5);cout<<"Hundir los 4 barcos de tu oponente antes que el"<<endl;
    Gotoxy(74,6);cout<<"acabe con los tuyos ,Cada jugador ";
    Gotoxy(74,7);cout<<"tiene 1 tablero compuesto por 10 filas y 10 columnas." ;
    Gotoxy(74,11);cout<<"1. En el tablero distribuirás tu flota (Barcos)";
    Gotoxy(74,12);cout<<"antes de comenzar la partida."<<endl;
    Gotoxy(74,13);cout<<"usando las teclas (A-D) elegi el sentido y con (Q) lo";
    Gotoxy(74,14);cout<<"seleccionas,luego escoge el casillero inicial donde se";
    Gotoxy(74,15);cout<<"colocara (numeros del 0 al 9)";
    Gotoxy(74,17);cout<<"2. Seleccionar un casillero al cual disparar en el tablero ";
    Gotoxy(74,18);cout<<"del oponente en busca de atacar sus barcos";
    Gotoxy(74,19);cout<<"usando  las teclas (A-W-S-D) para moverte  y con (Q) lo ";
     Gotoxy(74,20);cout<<"seleccionas";
    Gotoxy(74,24);cout<<"Agua: cuando disparas sobre una casilla donde no esta colocado";
    Gotoxy(74,25);cout<<"ningún barco enemigo,se vera un cuadrado azul en el casillero.";
    Gotoxy(74,27);cout<<"Barco: si disparas en una casilla en la que ";
    Gotoxy(74,28);cout<<"está un casilla de un barco enemigo";
    dibujoBarcos(0);
}

void mostrarBarcosJugador(  struct participantes  jugador[2],int jugadorAct){
    int a=21,b=7, c=a;
    for(int x=0;x<=9;x++){
        Gotoxy(a,b);
        for(int y=0;y<=9;y++){
            cout << " " << jugador[jugadorAct].tablero[x][y]<< jugador[jugadorAct].tablero[x][y] ;
        }
    b=b+2;
 }
  a=21,b=7;
 for(int x=0;x<=9;x++){
        Gotoxy(a-1,b);
        cout<<x;
        Gotoxy(c+1,a-16);
        cout<<x;
        c=c+3;
        b=b+2;
 }
 Sleep (1);
}
void batalla(int hInicio,int hFinal,int vInicio, int vFinal){

horizontales(hInicio,hFinal,vInicio,vFinal);
verticales(hInicio, hFinal, vInicio, vFinal);

char carac=205;
for(int x = hInicio+2; x <=hFinal-2 ; x++){
    Gotoxy(x,30); cout << carac;}
    carac=185;
    Gotoxy(hFinal-2,30); cout << carac;
    carac=204;
    Gotoxy(hInicio+2,30); cout << carac;
    carac=186;
    for(int x = vInicio+2; x <=29 ; x++){
            Gotoxy(70,x); cout << carac;
           }
carac=202;
Gotoxy(70,30); cout << carac;
carac=203;
Gotoxy(70,vInicio+1); cout << carac;
}
void posicionarBarcos(int hInicio,int hFinal,int vInicio, int vFinal, struct participantes jugador[2],int jugadorAct){
    mostrarBarcosJugador( jugador , jugadorAct);
    batalla( hInicio, hFinal, vInicio, vFinal);
    Gotoxy(30,3);cout  << "POSICIONAR LOS BARCOS";
    Gotoxy(84,3);cout  << "CASILLERO INICIAL DONDE SE COLOCA EL BARCO";
    Gotoxy(74,13);cout << "FILA:";
    Gotoxy(74,15);cout << "COLUMNA:";
    Gotoxy(74,11);cout << "SENTIDO:";
    Gotoxy(74,9);cout << "LARGO DEL BARCO: ";
    Gotoxy(93,11);cout << "Horizontal (a)  "<<"  Vertical(d)";
int x=45,y=34;
char carac= 219;
Gotoxy(x,y);cout<<"A "<<carac<<carac<<carac<<"   B "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<"   C "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<"   D "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" "<<carac<<carac<<carac<<" " ;y=y+2;
Gotoxy(x,y);cout<<"   1       1  2        1   2   3       1   2   3   4   ";y=y+2;
}
int casilleroInicial( char sentido, char fOc, int largo){
       int valor;
        if ((sentido == 'h'&& fOc=='c' )|| (sentido == 'v' && fOc=='f' )  ){
            do{
                cin >> valor;
            }while(valor<0 || valor+largo-1>9);
        }else{
            do{
                cin >> valor;
            }while(valor<0 || valor>9);
        }
        return valor;
 }
bool valido(int fila, int columna,int largo,struct participantes jugador[2],int jugadorAct,char sentido){
    bool validar=true;
    for(int y=1;y<=largo;y++){
       if((jugador[jugadorAct].tablero[fila][columna]== 'A'|| jugador[jugadorAct].tablero[fila][columna]== 'B')||(jugador[jugadorAct].tablero[fila][columna]== 'C'|| jugador[jugadorAct].tablero[fila][columna]== 'D')){
        validar=false;
       }
        if(sentido == 'h'){
        columna=columna+1;
         }else{
            fila=fila+1;
          }
    }
    Gotoxy(0,1);
    cout<<validar;
    return validar;}
void coordenasBarco(int jugadorAct, struct participantes jugador[2]){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int columna,fila, x,y;
    char sentido,carac=219,tecla;
    string palabra[2];
    palabra[0]="Horizontal";palabra[1]="Vertical";

    for(int largo=1;largo<=4;largo++){
        Gotoxy(93,9);cout << largo << endl;
        dibujoBarcos(largo);
        SetConsoleTextAttribute(hConsole, 31);
             do{
                tecla = getch();

                switch(tecla){
                    case 'a':
                        sentido='h';
                        x=93,y=11;
                        SetConsoleTextAttribute(hConsole, 12);
                        Gotoxy(x,y); cout << palabra[0];
                        x=111,y=11;
                        SetConsoleTextAttribute(hConsole, 31);
                        Gotoxy(x,y); cout<<palabra[1];
                        break;
                    case 'd':
                        sentido='v';
                        x=111,y=11;
                        SetConsoleTextAttribute(hConsole, 12);
                        Gotoxy(x,y); cout << palabra[1];
                        x=93,y=11;
                        SetConsoleTextAttribute(hConsole, 31);
                        Gotoxy(x,y); cout << palabra[0];
                        break;}
            }while(tecla!='q');
    do{
    Gotoxy(93,13);  fila = casilleroInicial(sentido,'f',largo);
    Gotoxy(93,15);columna = casilleroInicial(sentido,'c',largo);
    }while(valido( fila, columna,largo,jugador, jugadorAct, sentido)== false);
    for(int y=1;y<=largo;y++){
        jugador[jugadorAct].tablero[fila][columna]= 64+largo ;
        if(sentido == 'h'){
            columna=columna+1;
         }else{
            fila=fila+1;
          }
         Sleep (3);
         mostrarBarcosJugador(jugador,jugadorAct);
        }}}
void tableroSinBarcos(struct participantes  jugador[2],int jugadorAct){
    jugadorAct=cambioJugador(jugadorAct);
    char hundido='x',agua='O',carac=219;
    int a=21,b=7, c=a;
    for(int x=0;x<=9;x++){
        Gotoxy(a,b);
        for(int y=0;y<=9;y++){
            if (jugador[jugadorAct].tablero[x][y] == hundido||jugador[jugadorAct].tablero[x][y]  == agua||jugador[jugadorAct].tablero[x][y]  == carac){
                cout << " " << jugador[jugadorAct].tablero[x][y]<< jugador[jugadorAct].tablero[x][y] ;
            }else{
                cout << " "<<carac<<carac;
            }}
        b=b+2;
    }
    a=21,b=7;
    for(int x=0;x<=9;x++){
        Gotoxy(a-1,b); cout << x;
        Gotoxy(c+1,a-16); cout << x;
        c=c+3;
        b=b+2;
    }
}
void dispararAlOponente(int hInicio,int hFinal,int vInicio, int vFinal, struct participantes jugador[2],int jugadorAct){
    tableroSinBarcos( jugador , jugadorAct);
    Gotoxy(30,3);cout << "TABLERO DEL OPONENTE";
    Gotoxy(84,3);cout << "LUGAR A DISPARAR";
    Gotoxy(74,13);cout << "ESTADO: ";
    Gotoxy(74,7);cout<< "JUGADOR: ";
    Gotoxy(74,11);cout<< "COLUMNA: ";
    Gotoxy(74,9);cout<< "FILA: ";
    Gotoxy(74,15);cout<<"CASILLEROS CAPTURADOS: ";
    cambioJugador(jugadorAct);
    Gotoxy(97,15);cout<< jugador[jugadorAct].capturas;
}
void ganador(int hInicio,int hFinal,int vInicio, int vFinal, struct participantes jugador[2],int jugadorAct){
horizontales(hInicio,hFinal,vInicio,vFinal);
verticales(hInicio,hFinal,vInicio,vFinal);

int x=27,y=15;


Gotoxy(x,y);cout<<"   od8888bo         d8888 888b    888        d8888 8888888bo   od88888bo  8888888bo  "<<endl;y++;
Gotoxy(x,y);cout<<"  d88P  Y88b       d88888 8888b   888       d88888 888    88b d88P   Y88b 888   Y88b "<<endl;y++;
Gotoxy(x,y);cout<<"  888    888      d88P888 88888b  888      d88P888 888    888 888     888 888    888 "<<endl;y++;
Gotoxy(x,y);cout<<"  888            d88P 888 888Y88b 888     d88P 888 888    888 888     888 888   d88P "<<endl;y++;
Gotoxy(x,y);cout<<"  888  88888    d88P  888 888 Y88b888    d88P  888 888    888 888     888 8888888P   "<<endl;y++;
Gotoxy(x,y);cout<<"  888    888   d88P   888 888  Y88888   d88P   888 888    888 888     888 888 T88b   "<<endl;y++;
Gotoxy(x,y);cout<<"  Y88b  d88P  d8888888888 888   Y8888  d8888888888 888  .d88P Y88b. .d88P 888  T88b  "<<endl;y++;
Gotoxy(x,y);cout<<"   7Y8888P88 d88P     888 888    Y888 d88P     888 8888888P*   *Y88888PT  888   T88b "<<endl;y++;

dibujoBarcosInicioFinal(1);
dibujoBarcosInicioFinal(0);

x=55,y=25;

Gotoxy((140-11)/2,y);cout<<"JUGADOR : "<<jugadorAct;y++;
Gotoxy((140-jugador[jugadorAct].nombre.length())/2,y);cout<<jugador[jugadorAct].nombre;

}

int main()
{
HANDLE  hConsole;                               //COLOR
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
system ("color 1F");

char  tecla,hundido='x',agua='O',carac=219;                          //VARIABLES
int hFinal=140, hInicio=0,vInicio=0, vFinal=40, jugadorAct = 1,fila,columna;
inicio( hInicio, hFinal, vInicio,  vFinal);     //PANTALLA INICIO

    tecla = getch();
    switch(tecla){
        case 'x':                            //SALIR
            Gotoxy(0,42);
            return 0;
                break;}
    system("cls");
    participantes jugador[2];

    for(int x=0;x<=9;x++){               //INICIALIZACION
        for(int y=0;y<=9;y++){
            jugador[0].tablero[x][y]= 219 ;
            jugador[1].tablero[x][y]= 219 ;
         }
     }

    reglas(hInicio, hFinal, vInicio, vFinal);      // PANTALLA REGLAS
    tecla = getch();
    switch(tecla){                                   //SALIR
            case 'x':
                Gotoxy(0,42);
                return 0;
            break;}
    for(int x=0;x<=1;x++){                           //PANTALLA POSICIONAR LOS BARCOS
        jugador[x].capturas=0;
        system("cls");
        posicionarBarcos( hInicio, hFinal, vInicio, vFinal,jugador , jugadorAct);
        Gotoxy(74,7);cout << "JUGADOR " << x <<" :        ";cin>>jugador[x].nombre;
        coordenasBarco(x, jugador);
    }
    do{                                    //PANTALLA CAPTURAR
        system("cls");
        system ("color 1F");
        Sleep(30);
        jugadorAct=cambioJugador(jugadorAct);
        Gotoxy(85,7);cout  << jugadorAct <<"   "<<jugador[jugadorAct].nombre;
        batalla( hInicio, hFinal, vInicio, vFinal);
        dispararAlOponente( hInicio,hFinal, vInicio, vFinal, jugador, jugadorAct);
        int x=22,y=7;
        fila=0;columna=0;
        do{
            if (tecla=='a'&& x>=25 ){
                x=x-3;
                columna=columna-1;
            }
            if (tecla=='d'&& x<=48 ){
                x=x+3;
                columna=columna+1;
            }
            if (tecla=='w'&& y>=9 ){
                y=y-2;
                fila=fila-1;
            }
            if (tecla=='s'&& y<=24 ){
                y=y+2;
                fila=fila+1;
            }
            SetConsoleTextAttribute(hConsole, 12);
            Gotoxy(x,y);
            cout<<carac;
            Gotoxy(x+1,y); cout << carac;
            Gotoxy(84,9); cout << fila;
            Gotoxy(84,11); cout << columna;
            tecla=getch();
            SetConsoleTextAttribute(hConsole, 31);
            tableroSinBarcos(jugador,jugadorAct);
            Sleep(60);
        }while(tecla!='q');

        jugadorAct=cambioJugador(jugadorAct); //tablero del oponente si hay  un caracrer a b c d
        if (jugador[jugadorAct].tablero[fila][columna]!= carac&&jugador[jugadorAct].tablero[fila][columna]!= agua){
            Gotoxy(85,13);cout << "HUNDIDO"<<endl;
        if (jugador[jugadorAct].tablero[fila][columna]!=hundido){       // si el casillero no se marco como undido en las rondas anteriores
            jugadorAct=cambioJugador(jugadorAct);                           //jugador act le asigno  capturas mas uni
            jugador[jugadorAct].capturas=jugador[jugadorAct].capturas+1;
            jugadorAct=cambioJugador(jugadorAct);       }
            jugador[jugadorAct].tablero[fila][columna]=hundido;
        }else{
            if ( jugador[jugadorAct].tablero[fila][columna]== carac){
                Gotoxy(85,13);cout << "AGUA"<<endl;
                jugador[jugadorAct].tablero[fila][columna]=agua;
            }}
        jugadorAct=cambioJugador(jugadorAct);
        Gotoxy(97,15);cout<< jugador[jugadorAct].capturas;
        jugadorAct=cambioJugador(jugadorAct);
        if(jugador[jugadorAct].capturas<10){
            jugadorAct=cambioJugador(jugadorAct);
            tableroSinBarcos(jugador,jugadorAct);
        }
        Sleep(50);
    }while(jugador[jugadorAct].capturas<10);
    system("cls");
    ganador(hInicio, hFinal, vInicio,vFinal , jugador,jugadorAct);
    Gotoxy(0,42);
    return 0;
}

