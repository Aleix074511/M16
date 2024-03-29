// Ejercicio1.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include <iostream>
#include <io.h>
#include <Windows.h>
using namespace std;

//Variables de uso
int picas[12];
int diamantes[12];
int corazones[12];
int treboles[12];
bool gameOver = false;

//Variables Jugador 1
string player1;
int pointsPlayer1 = 0;
bool surrender1 = false;
bool winnerP1 = false;
bool loserP1 = false;

//Variables Jugador 2
string player2 = "Croupiere";
int pointsPlayer2 = 0;
bool surrender2 = false;
bool winnerP2 = false;
bool loserP2 = false;

void bienvenida() {				//El "dise�o" del juego
    cout << "===========================================================================" << endl;
    cout << "=                                BLACK JACK (21)                          =" << endl;
    cout << "=                                Bienvenido                               =" << endl;
    cout << "===========================================================================" << endl;
    cout << "Como te quieres llamar:" << endl;
    cin >> player1;
}
//Funciones

//Inicializa cualquier array con sus 12 posiciones a 1
//de esta forma, indicamos que todas las cartas est�n disponibles
//si una posici�n est� a 0, esa carta ya est� repartida y no se repite
void inicializaArray(int(&pArray)[12]) {
    for (int i = 0; i < 12; i++) {
        pArray[i] = 1;
    }
}

//Comprueba aleatoriamente si ha de dar picas o diamantes
//y busca una carta al azar. Hasta que no encuentre una posici�n
// a 1, no asigna esa carta, cuyo valor es el indiceCarta + 1
void chooseCards(int& totalPoints, string player) {
    bool choosed = false;
    int indiceCarta = 0;
    string tipoPalo;
    while (!choosed) {
        //Elije una carta del 1 al 12
        indiceCarta = rand() % 12;
        //Comprueba las Copas
        if ((rand() % 4) == 0) {
            if (picas[indiceCarta] == 1) {
                //devuelve la carta
                picas[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "copas";
            }
        }
        else if ((rand() % 4) == 1) {
            if (corazones[indiceCarta] == 1) {
                //devuelve la carta
                corazones[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "corazones";
            }
        }
        else if ((rand() % 4) == 2) {
            if (treboles[indiceCarta] == 1) {
                //devuelve la carta
                treboles[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "treboles";
            }
        }
        else {
            if (diamantes[indiceCarta] == 1) {
                //devuelve la tarjeta
                diamantes[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "diamantes";
            }
        }
    }



    //SI TOCA UN AS, PREGUNTAR SI QUIERES QUE SEA UN 1 O UN 11 (SOLO AL JUGADOR)
    if (indiceCarta == 0 && player == player1) {
        int eleccion = 0;
        //ELIGE SI ES QUERE QUE SEA UN 1 O UN 11
        do {
            cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y de momento tiene un total de " << totalPoints << endl;
            cout << "Quieres que cuente como un 1 o como un 11?" << endl;
            //ASEGURAMOS QUE LA OPCION INTROZUCIDA SEA VALIDA, s
            cin >> eleccion;
            if (eleccion == 1) {
                totalPoints += 0;
            }
            else if (eleccion == 11) {
                totalPoints += 10;
            }
        } while (eleccion !=1 && eleccion !=11);
        
    }
    //ELECION Croupiere SI SALE UN AS S
    else if (indiceCarta == 0 && player == player2) {
        //ELIGE AUTOMATICAMENTE 

        if (totalPoints < 9) {
            totalPoints += 10;
        }
        else {
            totalPoints += 0;
        }
    }

    //SI ES UNA FIGURA(INDICE>9) LA CARTA VALE 10 SIEMPRE
    if (indiceCarta > 9) {
        totalPoints += 10;
    }
    //SI LA CARTA ES MAYOR QUE 1 y MENOR QUE 10
    else {
        totalPoints += indiceCarta + 1;
    }
    cout << "El jugador " << player << " ha sacado un " << indiceCarta + 1 << " de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
}

bool checkPoints(int& points, bool& winner, bool& loser) {
    if (points == 21) {
        winner = true;
        return true;
    }
    else if (points > 21) {
        loser = true;
        return true;
    }
    return false;
}

bool checkWhoWins(int points1, int points2, bool& winner2) {
    if (points2 > points1) {
        winner2 = true;
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    bienvenida();
    inicializaArray(picas);
    inicializaArray(diamantes);
    inicializaArray(corazones);
    inicializaArray(treboles);
    srand(time(NULL));
    //primer reparto de cartas
    chooseCards(pointsPlayer1, player1);
    Sleep(10);
    chooseCards(pointsPlayer1, player1);
    Sleep(10);
    //Puede pasar que ganemos o perdamos nada m�s comenzar
    surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
    Sleep(10);
    chooseCards(pointsPlayer2, player2);
    Sleep(10);
    while (!surrender1) {
        int choice = 0;
        //Comienza el juego con el jugador 1
        while (choice != 1 && choice != 2) {
            cout << "Tienes " << pointsPlayer1 << ".Quieres pedir carta?" << endl;
            cout << "1.- Si" << endl;
            cout << "2.- No" << endl;
            cin >> choice;
            if (choice != 1 && choice != 2) {
                cout << "Por favor, elije una opci�n v�lida." << endl;
            }
        }
        if (choice == 1) {
            chooseCards(pointsPlayer1, player1);
            surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
            //comprueba si se ha pasado o ha ganado la partida
        }
        else {
            //Si no quiere carta, es turno de la banca
            surrender1 = true;
        }
    }
    //Termina el turno del jugador 1. Hay que comprobar si ha ganado (winnerP1) o perdido ya (loserP1), o si la banca tiene que tirar

    if (winnerP1) {
        cout << "El jugador " << player1 << " gana y la banca pierde" << endl;
    }
    else if (loserP1) {
        cout << "El jugador " << player1 << " pierde y la banca gana" << endl;
    }
    else {
        //turno de la banca
        while (!surrender2) {
            chooseCards(pointsPlayer2, player2);
            Sleep(10);
            surrender2 = checkPoints(pointsPlayer2, winnerP2, loserP2);
            if (!surrender2) {
                //Comprueba si la banca ya gana por puntos
                surrender2 = checkWhoWins(pointsPlayer1, pointsPlayer2, winnerP2);
            }
        }
        if (winnerP2) {
            cout << "La banca gana y el jugador " << player1 << " pierde" << endl;
        }
        else if (loserP2) {
            cout << "La banca pierde y el jugador " << player1 << " gana" << endl;
        }
    }

}