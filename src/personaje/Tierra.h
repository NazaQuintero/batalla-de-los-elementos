/*
 * Tierra.h
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_TIERRA_H_
#define PERSONAJE_TIERRA_H_

#include "Personaje.h"

const int RECUPERO_DE_ENERGIA_TIERRA = 8;

class Tierra: public Personaje {
public:

	// Constructores

	Tierra();

	Tierra(string nombre);

	Tierra(string nombre, int escudo, int vida);

	// Destructor

	virtual ~Tierra();

	// Metodos

	string obtenerElemento();

	string alimentar();
};

#endif /* PERSONAJE_TIERRA_H_ */
