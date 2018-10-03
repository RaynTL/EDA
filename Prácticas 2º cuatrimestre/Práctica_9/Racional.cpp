#include "Racional.h"
#include <cmath>

  //Metodos publicos

  	//**** COMPLETAR
	//  Deben implementarse los metodos publicos de la clase
	//****
Racional::Racional()
{
	_numer = 0;
	_denom = 1;
}

Racional::Racional(long numer, long denom)
{
	if (denom == 0)
		throw EDenominadorCero();
	
	_numer = numer;
	_denom = denom;
	reduce();		
}
	
Racional Racional::suma(Racional rac)
{
	//((_numer*mcm(_denom, rac._denom)) / _denom);

	//((rac._numer*mcm(_denom, rac._denom)) / rac._denom);

	long aux_numer = ((_numer*mcm(_denom, rac._denom)) / _denom) + ((rac._numer*mcm(_denom, rac._denom)) / rac._denom);
	long aux_denom = mcm(_denom, rac._denom);

	_numer = aux_numer;
	_denom = aux_denom;

	reduce();

	return *this;
}

Racional& Racional::operator- (const Racional& rac)
{
	//((_numer*mcm(_denom, rac._denom)) / _denom);

	//((rac._numer*mcm(_denom, rac._denom)) / rac._denom);

	long aux_numer = ((_numer*mcm(_denom, rac._denom)) / _denom) - ((rac._numer*mcm(_denom, rac._denom)) / rac._denom);
	long aux_denom = mcm(_denom, rac._denom);

	_numer = aux_numer;
	_denom = aux_denom;

	reduce();

	return *this;
}

Racional& Racional::operator*= (const Racional& rac)
{
	_numer *= rac._numer;
	_denom *= rac._denom;
	reduce();

	return *this;
}

Racional Racional::divideYActualiza(Racional rac)
{
	if (rac._numer == 0)
		throw EDivisionPorCero();

	_numer *= rac._denom;
	_denom *= rac._numer;
	reduce();

	return *this;
}

bool Racional::operator== (const Racional& rac)
{
	return (_numer == rac._numer) && (_denom == rac._denom);
}
  
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

