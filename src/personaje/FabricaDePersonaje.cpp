/*
 * ConstructorDePersonaje.cpp
 *
 *  Created on: Nov 19, 2020
 *      Author: nazaquintero
 */

#include "FabricaDePersonaje.h"


FabricaDePersonaje::~FabricaDePersonaje() {

}

FabricaDePersonaje::FabricaDePersonaje() {

}

Personaje* FabricaDePersonaje::obtenerPersonaje(string elemento, string nombre, int escudo, int vida) {

	if(elemento == "")
		return 0;

	Personaje* personaje;

	if (elemento == "agua") {

		personaje = new Agua(nombre, escudo, vida);

	} else if (elemento == "fuego") {

		personaje = new Fuego(nombre, escudo, vida);

	} else if (elemento == "tierra") {

		personaje = new Tierra(nombre, escudo, vida);

	} else if (elemento == "aire") {

		personaje = new Aire(nombre, escudo, vida);

	} else {
		cout << "Elemento: [" << elemento << "] inexistente" << endl;
		personaje = 0;
	}

	return personaje;
}

Personaje* FabricaDePersonaje::obtenerPersonaje(string elemento, string nombre) {

	if(elemento == "")
		return 0;

	Personaje* personaje;

	if (elemento == "agua") {

		personaje = new Agua(nombre);

	} else if (elemento == "fuego") {

		personaje = new Fuego(nombre);

	} else if (elemento == "tierra") {

		personaje = new Tierra(nombre);

	} else if (elemento == "aire") {

		personaje = new Aire(nombre);

	} else {
		cout << "Elemento: [" << elemento << "] inexistente" << endl;
		personaje = 0;
	}

	return personaje;
}

