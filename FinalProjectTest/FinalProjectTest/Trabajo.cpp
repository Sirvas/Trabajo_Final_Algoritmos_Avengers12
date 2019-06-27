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

	int nFilasBase(0), nColumnasBase(0), op(0), cont(1), indi(0);

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
			cout << "Ingrese el nombre de la primera columna de datos:" << endl;
			getline(cin, nombreC);
			Columna *C = new Columna(nombreC, indi);
			scolumnas.push_back(C);
			indi++;
		}
		nColumnasBase = dump.size();
		cont--;
	}

		Fila *F = new Fila(dump);
		sfilas.push_back(F);
		nFilasBase++;
		dump.clear();

	}

    Dataframe *dforiginal = new Dataframe(scolumnas, sfilas);
	DataFrameSet.push_back(dforiginal);

	cout << "Mostrando dataframe original con " << nFilasBase << " filas y "<< nColumnasBase << " columnas: "  << endl << endl;

	//mostrar dataframe

	cout << "Seleccione la operacion que desee realizar" << endl;
	cin >> op;

	//opciones

	getchar();
	return 0;
}