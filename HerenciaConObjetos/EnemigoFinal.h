#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int fireAttack;
	int frozenAttack;

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	EnemigoFinal(int pHp,
				 std::string pName,
				 int pAttack,
				 int pPosicionX,
				 int pPosicionY,
				 int pFireAttack,
				 int pFrozenAttack);

	//GETTERS AND SETTERS
	int getFireAttack();
	int getFrozenAttack();

	void setFireAttack(int pFireAttack);
	void setFrozenAttack(int pFrozenAttack);

	//METODOS PROPIOS
	void printAllStats();


};

