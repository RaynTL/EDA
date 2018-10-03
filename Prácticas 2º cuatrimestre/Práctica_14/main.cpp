#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cuentaTramosNavegables(const Arbin<int>& cuenca, int& contador )
{
	int iz = 0, dr = 0;

	if (!cuenca.esVacio())
	{
		if (cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio())
			return 1;

		if (!cuenca.hijoIz().esVacio())
			iz = cuentaTramosNavegables(cuenca.hijoIz(), contador);

		if (iz >= 3)
			contador++;
		else if (iz < 0)
			iz = 0;

		if (!cuenca.hijoDer().esVacio())
			dr = cuentaTramosNavegables(cuenca.hijoDer(), contador);

		if (dr >= 3)
			contador++;
		else if (dr < 0)
			dr = 0;
	}
	return iz + dr + cuenca.raiz();
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int contador = 0;
	int prof = 0;
	cuentaTramosNavegables(cuenca, contador);

	return contador;
}


Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}