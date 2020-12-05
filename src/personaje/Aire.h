/*
 * Aire.h
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_AIRE_H_
#define PERSONAJE_AIRE_H_

#include "Personaje.h"

class Aire: public Personaje {
public:

	// Constructores

	Aire();

	Aire(string nombre);

	Aire(string nombre, int escudo, int vida);

	// Destructor

	virtual ~Aire();

	// Metodos

	string obtenerElemento();

	string alimentar();
};

#endif /* PERSONAJE_AIRE_H_ */
