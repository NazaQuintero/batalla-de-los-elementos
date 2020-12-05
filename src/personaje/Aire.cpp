/*
 * Aire.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#include "Aire.h"

Aire::Aire() {
	this->asignarEnergia();
}

Aire::Aire(string nombre) {
	this->asignarNombre(nombre);
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Aire::Aire(string nombre, int escudo, int vida) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
}

string Aire::obtenerElemento() {
	return "aire";
}

string Aire::alimentar() {
	return "Los Personajes de tipo Aire no necesitan alimentarse.";
}

Aire::~Aire() {

}

