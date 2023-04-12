#pragma once
#include "lancha.h"
#include  <iostream>
//constructor
Lancha::Lancha(int pVelocidad, std::string pName, int pNitro, int pDistancia) {
	velocidad = pVelocidad;
	name = pName;
	nitro = pNitro;
	distancia = pDistancia;
}

//getters
int Lancha::getVelocidad() {
	return velocidad;
}

std::string Lancha::getName() {
	return name;
}

int Lancha::getNitro() {
	return nitro;
}

int Lancha::getDistancia() {
	return distancia;
}


//setters

void Lancha::setVelocidad(int pvelocidad) {
	velocidad = pvelocidad;
}

void Lancha::setName(std::string pname) {
	name = pname;
}

void Lancha::setNitro(int pnitro) {
	nitro = pnitro;
}

void Lancha::setDistancia(int pdistancia) {
	distancia = pdistancia;
}


//Metodos propios

void Lancha::printStatus() {
	std::cout << "El nombre del enemigo es " << getVelocidad() << " y tiene una vida de  " << getName() << std::endl;
}
