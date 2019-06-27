#pragma once
#include "separador.h"

class Columna
{
private:
	vector<string> data;
	string  nombre;

public:
	Columna(string nombre, vector<string> datos);
	~Columna();

	string getnombre() { return nombre; }

	vector<string> getdata() {
		return data;
	}

	void addData(string dato) {
		data.push_back(dato);
	}


};

Columna::Columna(string nombre, vector<string> data)
{
	this->nombre = nombre;
	this->data= data;
}

Columna::~Columna()
{
}