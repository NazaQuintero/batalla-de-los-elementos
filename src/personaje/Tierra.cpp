/*
 * Tierra.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: nazaquintero
 */

#include "Tierra.h"

Tierra::Tierra() {
	this->asignarEnergia();
}

Tierra::Tierra(string nombre) {
	this->asignarNombre(nombre);
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Tierra::Tierra(string nombre, int escudo, int vida) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
}

string Tierra::obtenerElemento() {
	return "tierra";
}

string Tierra::alimentar() {

	int energiaRecuperada;

	if(this->obtenerEnergia() <= MAXIMO_VALOR_ENERGIA - RECUPERO_DE_ENERGIA_TIERRA) {

		energiaRecuperada = RECUPERO_DE_ENERGIA_TIERRA;

		this->incrementarEnergia(RECUPERO_DE_ENERGIA_TIERRA);

	} else {

		energiaRecuperada = MAXIMO_VALOR_ENERGIA - this->obtenerEnergia();

		this->asignarEnergia(MAXIMO_VALOR_ENERGIA);
	}

	return "El personaje: " + this->obtenerNombre() + " fue alimentado con hierbas, y ha recuperado: " + to_string(energiaRecuperada) + " puntos de energia.";

}

Tierra::~Tierra() {

}

