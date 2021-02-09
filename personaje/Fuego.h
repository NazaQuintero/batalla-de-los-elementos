/*
 * Fuego.h
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_FUEGO_H_
#define PERSONAJE_FUEGO_H_

#include "Personaje.h"

const int RECUPERO_DE_VIDA_FUEGO = 15;

class Fuego: public Personaje {
public:

	// Constructores

	Fuego();

	Fuego(string nombre);

	Fuego(string nombre, int escudo, int vida);

	// Destructor

	virtual ~Fuego();

	// Metodos

	string obtenerElemento();

	string alimentar();
};

#endif /* PERSONAJE_FUEGO_H_ */
