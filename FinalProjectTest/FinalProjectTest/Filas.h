#pragma once
#include "separador.h"

class Fila
{
private:

	vector<string> datos;

public:
	Fila(vector<string> datos);
	~Fila();

	vector<string> getdatos() {
		return datos;
	}


};

Fila::Fila(vector<string> datos)
{
	this->datos = datos;
}

Fila::~Fila()
{
}