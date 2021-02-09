/*
 * Fuego.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#include "Fuego.h"

Fuego::Fuego() {
	this->asignarEnergia();
}

Fuego::Fuego(string nombre) {
	this->asignarNombre(nombre);
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Fuego::Fuego(string nombre, int escudo, int vida) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
}

string Fuego::obtenerElemento() {
	return "fuego";
}

string Fuego::alimentar() {

	int vidaRecuperada;

	if(this->obtenerVida() <= MAXIMO_VALOR_VIDA - RECUPERO_DE_VIDA_FUEGO) {

		vidaRecuperada = RECUPERO_DE_VIDA_FUEGO;

		this->incrementarVida(RECUPERO_DE_VIDA_FUEGO);

	} else {

		vidaRecuperada = MAXIMO_VALOR_VIDA - this->obtenerVida();

		this->asignarVida(MAXIMO_VALOR_VIDA);

	}

	return "El personaje: " + this->obtenerNombre() + " fue alimentado con madera, y ha recuperado: " + to_string(vidaRecuperada) + " puntos de vida.";

}

Fuego::~Fuego() {

}

