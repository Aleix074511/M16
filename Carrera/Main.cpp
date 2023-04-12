#include <iostream>
#include "lancha.h"
#include <io.h>
#include <Windows.h>
using namespace std;

int turnos = 5;
int dado = 0;
int dadonitro;
int nitro;
int desempatar;
string jugar;

Lancha Lancha1(0, "Lancha1", 1, 0);
Lancha Lancha2(0, "Lancha2", 1, 0);

void distancia(Lancha& lancha) {
	cout << "La distancia de la " <<lancha.getName() << " es de " << lancha.getDistancia() << endl;
	cout << "" << endl;
}
void turnosrestantes() {
	turnos = turnos - 1;
	cout << "Quedan " << turnos <<" turnos" << endl;
	cout << "------------------------------------------------------------" << endl;
}

void tirardado() {
	dado = 1 + rand() % 6;
}

void tirardadonitro() {
	dadonitro = 1 + rand() % (2 - 1);
}

void turnojugador(Lancha& lancha) {

	cout << "Turno de  " << lancha.getName() << endl;
	tirardado();
	lancha.setVelocidad(lancha.getVelocidad() + dado);
	lancha.setDistancia(lancha.getDistancia() + lancha.getVelocidad() * 100);
	cout << "En el dado a salido un  " << dado << endl;
	cout << "Ahora tu velocidad es de " << lancha.getVelocidad() << endl;

	if (lancha.getNitro() == 1) {
		cout << "Quieres usar el nitro?  " << endl;
		cout << "[1] - Si  " << endl;
		cout << "[2] - NO  " << endl;
		cin >> nitro;

		if (nitro == 1) {
			tirardadonitro();
			cout << "En el dado del NITRO a salido un  " << dadonitro << endl;
			lancha.setNitro(0);
			if (dadonitro == 1) {
				cout << " Has tenido suerte tu velocidad se multiplica por 2" << endl;
				lancha.setVelocidad(lancha.getVelocidad() * 2);
				lancha.setDistancia(lancha.getDistancia() + lancha.getVelocidad() * 100);
				cout << "Ahora tu velocidad aumentado a " << lancha.getVelocidad() << " de velocidad" << endl;
			}
			else {
				cout << " No has tenido suerte tu velocidad se dividirse por la mitad " << endl;
				lancha.setVelocidad(lancha.getVelocidad() / 2);
				lancha.setDistancia(lancha.getDistancia() + lancha.getVelocidad() * 100);
				cout << "Ahora tu velocidad aumentado a " << lancha.getVelocidad() << " de velocidad" << endl;
			}

		}

	}

	if (Lancha1.getVelocidad() > Lancha2.getVelocidad()) {
		cout << "La Lancha " << Lancha1.getName() << " Va en primero posicion" << endl;
		cout << "------------------------------------------------------------" << endl;
	}
	else if (Lancha2.getVelocidad() > Lancha1.getVelocidad()) {
		cout << "La Lancha " << Lancha2.getName() << " Va en primero posicion" << endl;
		cout << "------------------------------------------------------------" << endl;
	}
	else {
		cout << "Ninguna lancha va ganando vais empate" << endl;
		cout << "------------------------------------------------------------" << endl;
	}

}

void ganador() {
	if (Lancha1.getDistancia() > Lancha2.getDistancia()) {
		cout << "EL GANADOR DE LA PARTIDA A SIDO  " << Lancha1.getName() << endl;
	}
	else if (Lancha2.getDistancia() > Lancha1.getDistancia()) {
		cout << "EL GANADOR DE LA PARTIDA A SIDO  " << Lancha2.getName() << endl;
	}
	else {
		cout << " EMPATE "  << endl;
		cout << " Queries desempatar? " << endl;
		cout << "[1] - Si  " << endl;
		cout << "[2] - NO  " << endl;
		cin >> desempatar;
		if (desempatar == 1) {
			turnojugador(Lancha1);
			turnojugador(Lancha2);
			distancia(Lancha1);
			distancia(Lancha2);
			ganador();
		}
	}
}

void seguirjugando() {
	cout << "Si quieres seguir pulsa una TECLA y luego INTRO" << endl;
	cin >> jugar;
}



int main() {
	
	//SRAND
	srand(time(NULL));
	//WHILE QUE CONTROLE LOS TURNOS
	while (turnos > 0)
	{
		turnojugador(Lancha1);
		turnojugador(Lancha2);
		turnosrestantes();
		if (turnos > 1) {
			seguirjugando();
		}
		else {
			cout << "Pulsa una TECLA y luego INTRO para saber el GANADOR" << endl;
			cin >> jugar;
		}
	}
	//TERMINA EL WHILE
	distancia(Lancha1);
	distancia(Lancha2);
	ganador();
	return 0;
}