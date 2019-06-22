#pragma once
#include "separador.h"

class Columna
{
private:
	string  nombre;
	int indice;

public:
	Columna(string nombre, int indice);
	~Columna();

	string getnombre() { return nombre; }

	int getindice() { return indice; }

};

Columna::Columna(string nombre, int indice)
{
	this->nombre = nombre;
	this->indice = indice;
}

Columna::~Columna()
{
}