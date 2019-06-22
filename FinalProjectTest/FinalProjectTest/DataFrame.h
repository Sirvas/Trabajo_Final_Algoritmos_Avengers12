#pragma once
#include "separador.h"
#include "Columnas.h"
#include "Filas.h"

class Dataframe
{
private:
	vector<Columna*> pcol;
	vector<Fila*> pfil;

public:
	Dataframe(vector<Columna*> pcol, vector<Fila*> pfil);
	~Dataframe();



};

Dataframe::Dataframe(vector<Columna*> pcol, vector<Fila*> pfil)
{

	this->pcol = pcol;
	this->pfil = pfil;

}

Dataframe::~Dataframe()
{
}