#include <iostream>
#include <string>
#include "pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
	// A IMPLEMENTAR
	Pila<char> p = Pila<char>();
	char c;

	bool ok = true;

	for (int i = 0; i < cadena.length() && ok; i++)
	{
		c = cadena[i];

		if ((c == '(') || (c == '[') || (c == '{'))
			p.apila(c);
		else if (p.esVacia() && ( (c == ')') || ( c == ']' ) || (c == '}') ) )
			ok = false;
		else
		{
			switch (c)
			{
			case ')':
				if (p.cima() == '(')
					p.desapila();
				else
					ok = false;
				break;
			case ']':
				if (p.cima() == '[')
					p.desapila();
				else
					ok = false;
				break;
			case '}':
				if (p.cima() == '{')
					p.desapila();
				else
					ok = false;
				break;

			default:
				break;
			}
		}
	}

	if (!p.esVacia())
		ok = false;

	return ok;
}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibrada(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;		  
	}
	return 0;
}	
