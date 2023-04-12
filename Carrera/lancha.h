#pragma once
#include  <iostream>
class Lancha
{

private:
	int velocidad;
	std::string name;
	int nitro;
	int distancia;

public:
	//constructor
	Lancha(int pVelocidad, std::string pName, int pNitro, int pDistancia);
	//getters
	int getVelocidad();

	std::string getName();

	int getNitro();

	int getDistancia();

	//setters

	void setVelocidad(int pvelocidad);

	void setName(std::string pname);

	void setNitro(int pnitro);

	void setDistancia(int pdistancia);

	//metodos propios

	void printStatus();


};
