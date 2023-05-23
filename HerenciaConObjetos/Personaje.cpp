#pragma once
#include "Personaje.h"
#include  <iostream>
	//constructor
Personaje::Personaje(int pHp, std::string pName, int pAttack, int pPosicionX, int pPosicionY) {
	hp = pHp;
	name = pName;
	attack = pAttack;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
	}

	//getters
	int Personaje::getHp() {
		return hp;
	}

	std::string Personaje::getName() {
		return name;
	}

	int Personaje::getAttack() {
		return attack;
	}

	int Personaje::getPosicionX() {
		return posicionX;
	}

	int Personaje::getPosicionY() {
		return posicionY;
	}


	//setters

	void Personaje::setHp(int php) {
		hp = php;
	}

	void Personaje::setName(std::string pname) {
		name = pname;
	}

	void Personaje::setAttack(int pattack) {
		attack = pattack;
	}

	void Personaje::setPosicionX( int pposicionX) {
		posicionX = pposicionX;
	}

	void Personaje::setPosicionY(int pposicionY) {
		posicionY = pposicionY;
	}

	//Metodos propios

	void Personaje::printStatus() {
		std::cout << "El nombre del enemigo es " << getName() << " y tiene una vida de  " << getHp() << std::endl;
 	}