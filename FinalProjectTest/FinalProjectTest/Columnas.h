#pragma once
#include "separador.h"

class Columna
{
private:
	string tipo, nombre;
	vector<string> datos;

public:
	Columna(string tipo, string nombre, vector<string> datos);
	~Columna();

	vector<string> getvdatos() { return datos; }

	vector<string> getcoldatos(string nombre) {
		if (nombre == this->nombre) return datos; 
	}


};

Columna::Columna(string tipo, string nombre, vector<string> datos)
{
	tipo = "";
	nombre = "";
	this->datos = datos;
}

Columna::~Columna()
{
}