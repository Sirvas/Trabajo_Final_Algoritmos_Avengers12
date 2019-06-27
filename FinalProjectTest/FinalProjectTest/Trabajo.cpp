#include "separador.h"
#include "DataFrame.h"
#include <time.h>

vector<string> split(string str, char separadora) {
	istringstream iss(str);
	string cad;
	vector<string> arr;
	while (getline(iss, cad, separadora)) {
		arr.push_back(cad);
	}
	return arr;
}


int main() {
	char separadora(',');
	string nArchivo(""), nombreC("");
	vector<string> dump;
	vector<Fila*> sfilas;
	vector<Columna*> scolumnas;
	vector<Dataframe*> DataFrameSet;
	
	int nFilasBase(0), nColumnasBase(0), op(0), cont(1);

	cout << "Ingrese el caracter separador del archivo a procesar:" << endl;
	cin >> separadora;
	cin.ignore();

	cout << "Ingrese el nombre del archivo:" << endl;
	
	getline(cin, nArchivo);
	

	
	ifstream infile;
	infile.open(nArchivo);
	
	while (infile.good()) {
		string str;
		getline(infile, str);
		dump = split(str, separadora);

		if (cont == 1) {
		for (int i = 0; i < dump.size(); i++) {
			vector<string> vec;
			vec.push_back(dump[i]);
			cout << "Ingrese el nombre de la columna de datos:" << endl;
			getline(cin, nombreC);
			Columna *C = new Columna(nombreC, vec);
			scolumnas.push_back(C);
		}
		nColumnasBase = dump.size();
		cont--;
	}else for (int i = 0; i < dump.size(); i++) {
		scolumnas[i]->addData(dump[i]);
    	}

		Fila *F = new Fila(nFilasBase);
		sfilas.push_back(F);
		nFilasBase++;
		dump.clear();

	}
	infile.close();

	colmap mapa;
	for (auto ccol : scolumnas) {
		mapa[ccol->getnombre()] = ccol;
	}

	for (auto ffil : sfilas) {
		ffil->setcolmap(&mapa);
	}


    Dataframe *dforiginal = new Dataframe(scolumnas, sfilas);
	DataFrameSet.push_back(dforiginal);

	cout << "Mostrando dataframe original con " << nFilasBase << " filas y "<< nColumnasBase << " columnas: "  << endl << endl;

	dforiginal->mostrardf();

	cout << "Seleccione la operacion que desee realizar" << endl;
	cin >> op;

	switch (op) {


	}

	//opciones

	getchar();
	return 0;
}