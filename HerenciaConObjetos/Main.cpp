#include <iostream>
#include "Personaje.h"
#include "EnemigoFinal.h"

using namespace std;

//ARRAY
int array[10][5];


//CREAMOS PERSONAJE
Personaje Persona(300, "", 50, 0, 0);

//CREAMOS 8 ENEMIGOS NORMALES
Personaje Enemigo1(50, "Enemigo1", 50, 2, 0);
Personaje Enemigo2(50, "Enemigo2", 50, 3, 0);
Personaje Enemigo3(50, "Enemigo3", 50, 4, 0);
Personaje Enemigo4(50, "Enemigo4", 50, 5, 0);
Personaje Enemigo5(50, "Enemigo5", 50, 6, 0);
Personaje Enemigo6(50, "Enemigo6", 50, 7, 0);
Personaje Enemigo7(50, "Enemigo7", 50, 8, 0);
Personaje Enemigo8(50, "Enemigo8", 50, 9, 0);

//CREAMOS UN ENEMIGO FINAL QUE HEREDA DE ENEMIGO
EnemigoFinal kingBowser(1000, "Bowser", 100, 0, 0, 50, 45);



void gameStart() {
	cout << "El enemigo " << Persona.getName() << " ha aparecido\n";
	cout << "Como se llama el heroe?\n";
	cin >> Persona.getName();
	cout << "El nombre del Personaje es " << Persona.getName() << "\n";
}

void enemigoencontrado() {
	cout << "Te has topado con un enemigo te toca pelear\n";
	cout << "Tienes  " << Persona.getName() << " puntos de vida\n";
}

int main() {


	//PROBAMOS LOS MÉTODOS PROPIOS
	kingBowser.printAllStats();
	Persona.getName();
	
	return 0;
}