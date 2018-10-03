#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR 
	Lista<string>::ConstIterator citB = bien.cbegin(); // Iterador para la lista buena
	Lista<string>::ConstIterator citM = mal.cbegin(); // Iterador para la lista mala
	Diccionario<string, int> dic = Diccionario<string, int>();

	int aux = 0;

	while (citB != bien.cend())
	{
		if (!dic.contiene(citB.elem()))
			dic.inserta(citB.elem(), 1);
		else
		{
			aux = dic.valorPara(citB.elem());
			aux++;
			dic.inserta(citB.elem(), aux);
		}
		citB.next();
	}

	while (citM != mal.cend())
	{
		if (!dic.contiene(citM.elem()))
			dic.inserta(citM.elem(), -1);
		else
		{
			aux = dic.valorPara(citM.elem());
			aux--;
			dic.inserta(citM.elem(), aux);
		}
		citM.next();
	}

	Diccionario<string, int>::ConstIterator citD = dic.cbegin(); // Iterador del diccionario
	while (citD != dic.cend())
	{
		if (citD.valor() != 0)
			listado.pon_final(Puntuacion(citD.clave(), citD.valor()));
		citD.next();
	}

}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}