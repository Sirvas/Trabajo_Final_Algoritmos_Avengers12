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
	Dataframe();
	~Dataframe();



};

Dataframe::Dataframe()
{
}

Dataframe::~Dataframe()
{
}