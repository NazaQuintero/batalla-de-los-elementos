/*
 * Personaje.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: nazaquintero
 */

#include "Personaje.h"

Personaje::Personaje() {
	this->asignarEscudo();
	this->asignarVida();
	this->asignarEnergia();
}

Personaje::~Personaje() {

}

int Personaje::obtenerNroRandom(int min, int max) {
	return (rand() % max) + (min);
}

void Personaje::asignarNombre(string nombre) {
	this->nombre = nombre;
}

string Personaje::obtenerNombre() {
	return this->nombre;
}

void Personaje::asignarEscudo() {
	this->escudo = obtenerNroRandom(MINIMO_VALOR_ESCUDO, MAXIMO_VALOR_ESCUDO);
}

void Personaje::asignarEscudo(int escudo) {
	this->escudo = escudo;
}

int Personaje::obtenerEscudo() {
	return this->escudo;
}

void Personaje::asignarVida() {
	this->vida = obtenerNroRandom(MINIMO_VALOR_VIDA, MAXIMO_VALOR_VIDA);
}

void Personaje::asignarVida(int vida) {
	this->vida = vida;
}

void Personaje::incrementarVida(int incremento) {
	this->vida += incremento;
}

int Personaje::obtenerVida() {
	return this->vida;
}

void Personaje::asignarEnergia() {
	this->energia = obtenerNroRandom(MINIMO_VALOR_ENERGIA, MAXIMO_VALOR_ENERGIA);
}

void Personaje::asignarEnergia(int energia) {
	this->energia = energia;
}

void Personaje::incrementarEnergia(int incremento) {
	this->energia += incremento;
}

int Personaje::obtenerEnergia() {
	return this->energia;
}

string Personaje::toString() {
	return this->obtenerElemento() + "," + this->obtenerNombre() + "," + to_string(this->obtenerEscudo()) + "," + to_string(this->obtenerVida());
}

