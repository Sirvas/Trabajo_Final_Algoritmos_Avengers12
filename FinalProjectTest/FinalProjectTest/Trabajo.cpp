#include "separador.h"
#include "DataFrame.h"

int main() {
	char separadora;
	string nArchivo, str, nombreC;
	vector<string> dump;
	vector<Fila*> sfilas;
	vector<Columna*> scolumnas;
	vector<Dataframe*> DataFrameSet;

	int nFilasBase(0), nColumnasBase(0), op, cont(1), indi(0);

	cout << "Ingrese el caracter separador del archivo a procesar:" << endl;
	cin >> separadora;

	cout << "Ingrese el nombre del archivo:" << endl;
	cin.ignore();
	getline(cin, nArchivo);


	ifstream infile(nArchivo);


	while (getline(infile, str)) {

		dump = split(str, separadora);

		if (cont == 1) {
		for (int i = 0; i < dump.size(); i++) {
			cout << "Ingrese el nombre de la primera columna de datos:" << endl;
			cin.ignore();
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

    Dataframe dforiginal(scolumnas, sfilas);

	cout << "Mostrando dataframe original: " << endl << endl;

	//mostrar dataframe

	cout << "Seleccione la operacion que desee realizar" << endl;
	cin >> op;

	//opciones

	getchar();
	return 0;
}