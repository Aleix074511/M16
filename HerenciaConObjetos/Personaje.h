#pragma once
#include  <iostream>
class Personaje
{

private:
	int hp;
	std::string name;
	int attack;
	int posicionX;
	int posicionY;

public:
	//constructor
	Personaje(int pHp, std::string pName, int pAttack, int pPosicionX, int pposicionY);
	//getters
	int getHp();

	std::string getName();

	int getAttack();

	int getPosicionX();

	int getPosicionY();
	//setters

	void setHp(int php);

	void setName(std::string pname);

	void setAttack(int pattack);

	void setPosicionX(int pposicionX);

	void setPosicionY(int pposicionY);
	//metodos propios

	void printStatus();

};

