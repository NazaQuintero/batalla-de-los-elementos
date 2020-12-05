/*
 * ConstructorDePersonaje.h
 *
 *  Created on: Nov 19, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_FABRICADEPERSONAJE_H_
#define PERSONAJE_FABRICADEPERSONAJE_H_

#include "Personaje.h"
#include "Agua.h"
#include "Fuego.h"
#include "Tierra.h"
#include "Aire.h"

#include <iostream>

using namespace std;

class FabricaDePersonaje {
public:

	// Constructor

	FabricaDePersonaje();

	// Destructor

	virtual ~FabricaDePersonaje();

	//Metodos

	/**
	 * PRE: El elemento es un elemento valido.
	 * POS: Devuelve un puntero que apuntara a una instancia de la clase correspondiente al elemento.
	 */
	Personaje* obtenerPersonaje(string elemento, string nombre, int escudo, int vida);

	Personaje* obtenerPersonaje(string elemento, string nombre);
};

#endif /* PERSONAJE_FABRICADEPERSONAJE_H_ */
