/*
 * Personaje.h
 *
 *  Created on: Nov 15, 2020
 *      Author: nazaquintero
 */

#ifndef PERSONAJE_PERSONAJE_H_
#define PERSONAJE_PERSONAJE_H_

#include <string>
#include <iostream>
#include "../validaciones/Validador.h"

using namespace std;

class Personaje {

private:
	// Atributos

	string nombre;
	int escudo;
	int vida;
	int energia;

	// Metodos

	int obtenerNroRandom(int min, int max);

public:
	// Constructor

	Personaje();

	// Metodos

	virtual string obtenerElemento() = 0;
	virtual string alimentar() = 0;

	void asignarNombre(string nombre);
	string obtenerNombre();

	void asignarEscudo();
	void asignarEscudo(int escudo);
	int obtenerEscudo();

	void asignarVida();
	void asignarVida(int vida);
	int obtenerVida();
	void incrementarVida(int incremento);

	void asignarEnergia();
	void asignarEnergia(int energia);
	int obtenerEnergia();
	void incrementarEnergia(int incremento);

	string toString();

	// Destructor

	virtual ~Personaje();

};

#endif /* PERSONAJE_PERSONAJE_H_ */
