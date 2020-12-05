/*
 * Agua.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: nazaquintero
 */

#include "Agua.h"

Agua::Agua() {
	this->asignarEnergia();
}

Agua::Agua(string nombre) {
	this->asignarNombre(nombre);
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}


Agua::Agua(string nombre, int escudo, int vida) {
	this->asignarEnergia();
	this->asignarNombre(nombre);
	this->asignarEscudo(escudo);
	this->asignarVida(vida);
}

string Agua::obtenerElemento() {
	return "agua";
}

string Agua::alimentar() {

	string mensajeResultado;

	if(vecesAlimentado == CANT_MAX_ALIMENTADO) {

		mensajeResultado = "Usted no puede alimentar mas de " + to_string(CANT_MAX_ALIMENTADO) + " veces a los Personajes de tipo Agua";

	} else {

		int energiaRecuperada;

		if(this->obtenerEnergia() <= MAXIMO_VALOR_ENERGIA - RECUPERO_DE_ENERGIA_AGUA) {

			energiaRecuperada = RECUPERO_DE_ENERGIA_AGUA;

			this->incrementarEnergia(RECUPERO_DE_ENERGIA_AGUA);

		} else {

			energiaRecuperada = MAXIMO_VALOR_ENERGIA - this->obtenerEnergia();

			this->asignarEnergia(MAXIMO_VALOR_ENERGIA);

		}

		vecesAlimentado++;

		mensajeResultado = "El personaje: " + this->obtenerNombre() + " fue alimentado con plancton, y ha recuperado: " + to_string(energiaRecuperada) + " puntos de energia.";
	}
	return mensajeResultado;
}

Agua::~Agua() {

}

