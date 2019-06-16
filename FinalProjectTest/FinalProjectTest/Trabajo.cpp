#include "separador.h"
#include "DataFrame.h"

int main() {
	char separadora;
	string nArchivo, str;
	vector<string> dump;
	int nFilasBase, nColumnasBase;
	bool Lfinal;

	cout << "Ingrese el caracter separador del archivo a procesar:" << endl;
	cin >> separadora;

	cout << "Ingrese el nombre del archivo:" << endl;
	getline(cin, nArchivo);

	cout << "Si en la ultima linea del archivo especificado hay un salto de linea, ingrese 1. En el caso contrario, ingrese 0" << endl; 
	cin >> Lfinal;

	ifstream infile(nArchivo);

	if (Lfinal == true)
		nFilasBase = count(istreambuf_iterator<char>(infile), istreambuf_iterator<char>(), '\n');
	if (Lfinal == false)
		nFilasBase = count(istreambuf_iterator<char>(infile), istreambuf_iterator<char>(), '\n') + 1;

	while (getline(infile, str)) {
		dump = split(str, separadora);
	}

	nColumnasBase = dump.size() / nFilasBase;



	getchar();
	return 0;
}