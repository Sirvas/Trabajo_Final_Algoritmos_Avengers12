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
	Dataframe() {};
	~Dataframe();

	vector<Columna*> getcol() {
		return pcol;
	}

	vector<Fila*> getfil() {
		return pfil;
	}

	void mostrardf() {
		for (auto col : pcol) {
			cout << col->getnombre() << " | ";
		}
		cout << endl << endl;

		for (auto fil : pfil) {
			for (int i = 0; i < pcol.size(); i++) {
				cout << fil->getdata(pcol[i]->getnombre()) << "  |  ";
			}
			cout<< endl;
		}
	}


	void selecdf(vector<string> cols) {
		Dataframe* df = new Dataframe();
		for (auto colname : cols) {
			for(auto col : this->pcol) {
				if (col->getnombre() == colname) {
					df->getcol().push_back(col);
				}
			}
		}
		df->pfil = this->pfil;
	}
  



};

Dataframe::Dataframe(vector<Columna*> pcol, vector<Fila*> pfil)
{

	this->pcol = pcol;
	this->pfil = pfil;

}

Dataframe::~Dataframe()
{
}