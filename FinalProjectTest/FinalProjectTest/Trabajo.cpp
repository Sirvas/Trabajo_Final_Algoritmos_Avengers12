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


void exportarArchivo(Dataframe* df, char delim) {
	string archivoN;
	cout << "Ingrese el nombre del archivo a crear: " << endl;
	getline(cin, archivoN);
	cout << "ingrese el caracter separador a utilizar en el archivo: " << endl;
	cin >> delim;
	ofstream outfile(archivoN);
	
	for (auto fil : df->getfil()) {
		for (int i = 0; i < df->getcol().size(); i++) {
			outfile << fil->getdata(df->getcol()[i]->getnombre()) << delim ;
			if (i == df->getcol().size() - 1) {
				outfile << "\b" << "\n";
			}
		}
		cout << endl;
	}
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

	bool x = true;
	while (x) {
		cout << "Seleccione la operacion que desee realizar: " << endl;
		cout << "Opción 1 (Indexado de Datos): " << endl;
		cout << "Opción 2 (Selección de Datos): " << endl;
		cout << "Opción 3 (Filtrado de Datos): " << endl;
		cout << "Opción 4 (Ordenamiento de Datos): " << endl;
		cout << "Opción 5 (Exportación de Datos): " << endl;
		cout << "Salir (Elegir 0): " << endl;
		cin >> op;
		switch (op) {
		case 0: x = false; break;
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		}
	}

	//opciones

	getchar();
	return 0;
}