#include "EnemigoFinal.h"
#include "Personaje.h"
//CONSTRUCTOR
//TIENE COMO PARÁMETROS DE ENTRADA LOS ATRIBUTOS PROPIOS
//Y LOS ATRIBUTOS DE LA CLASE QUE HEREDA
//LOS PARÁMETROS DE LA CLASE QUE HEREDA SE PASAN COMO PARÁMETROS DE ENTRADA
//AL CONSTRUCTOR HEREDADO
EnemigoFinal::EnemigoFinal(int pHp,
						   std::string pName,
						   int pAttack,
						   int pPosicionX,
						   int pPosicionY,
						   int pFireAttack,
						   int pFrozenAttack) : Personaje(pHp,
														pName,
														pAttack,
														pPosicionX,
														pPosicionY) {fireAttack = pFireAttack;
																  frozenAttack = pFrozenAttack;
						}


//GETTERS AND SETTERS
int EnemigoFinal::getFireAttack() {
	return fireAttack;
}
int EnemigoFinal::getFrozenAttack() {
	return frozenAttack;
}

void EnemigoFinal::setFireAttack(int pFireAttack) {
	fireAttack = pFireAttack;
}
void EnemigoFinal::setFrozenAttack(int pFrozenAttack) {
	frozenAttack = pFrozenAttack;
}

//METODOS PROPIOS
void EnemigoFinal::printAllStats() {
	cout << "El nombre del enemigo final es " << getName() << endl;
	cout << "La vida del enemigo final es " << getHp() << endl;
	cout << "El ataque normal del enemigo final es " << getAttack() << endl;
	cout << "X: " << getPosicionX() << endl;
	cout << "Y: " << getPosicionY() << endl;
	cout << "El ataque de fuego del enemigo final es " << getFireAttack() << endl;
	cout << "El ataque de hielo del enemigo final es " << getFrozenAttack() << endl;
}