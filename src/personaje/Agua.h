/*
 * Agua.h
 *
 *  Created on: Nov 15, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_AGUA_H_
#define PERSONAJE_AGUA_H_

#include "Personaje.h"

const int CANT_MAX_ALIMENTADO = 3;
const int RECUPERO_DE_ENERGIA_AGUA = 10;

class Agua: public Personaje {
private:

	int vecesAlimentado = 0;

public:

	// Constructores
	Agua();

	Agua(string nombre);

	Agua(string nombre, int escudo, int vida);

	// Destructor

	virtual ~Agua();

	// Metodos

	string obtenerElemento();

	string alimentar();
};

#endif /* PERSONAJE_AGUA_H_ */
