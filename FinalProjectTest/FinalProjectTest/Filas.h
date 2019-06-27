#pragma once
#include "separador.h"
#include "Columnas.h"



typedef map<string, Columna*> colmap;
map<string, Columna*>::iterator it;

class Fila
{
private:
	int idx;
	colmap* cols;
public:
	Fila(colmap* cols) : cols(cols) {};
	Fila() {};
	Fila(int idx) : idx(idx) {};
	~Fila();


	string getdata(string name) {
		return (*cols)[name]->getdata()[idx];
	}

	void setcolmap(colmap* cols) {
		this->cols = cols;
	}

};


Fila::~Fila()
{
}