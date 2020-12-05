/*
 * Validador.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#include "Validador.h"

Validador::Validador() {
	cargarElementos();
}


Validador::~Validador() {

}

void Validador::cargarElementos() {
	fstream archivo_elementos(NOMBRE_ARCHIVO_ELEMENTOS, ios::in);

	if(!archivo_elementos.is_open()) {

		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_ELEMENTOS << "\" ." << endl;

	} else {

		string linea;

		int i = 0;
		while(getline(archivo_elementos, linea) && i < CANTIDAD_DE_ELEMENTOS) {
			elementos[i] = linea;
			i++;
		}

	}
	archivo_elementos.close();
}

Validador* Validador::obtenerInstancia() {

	if(!validador)
		validador = new Validador();

	return validador;
}

bool Validador::esNumeroValido(string numero) {
	bool esValido = true;

	int largoDelString = (int)numero.length();
	int i = 0;

	while(esValido && i < largoDelString) {
		esValido = isdigit(numero[i]);
		i++;
	}
	return esValido;
}

bool Validador::esOpcionValida(int opcion, int min,int max) {
	return (opcion >= min && opcion <= max);
}

bool Validador::esValorEscudoValido(int escudo) {
	return (escudo >= MINIMO_VALOR_ESCUDO && escudo <= MAXIMO_VALOR_ESCUDO);
}

bool Validador::esValorVidaValido(int vida) {
	return (vida >= MINIMO_VALOR_VIDA && vida <= MAXIMO_VALOR_VIDA);
}

bool Validador::esValorCasoValido(string caso, int valor) {
	if (caso == "escudo") {
		return esValorEscudoValido(valor);
	} else if (caso == "vida") {
		return esValorVidaValido(valor);
	} else {
		return false;
	}
}

bool Validador::esElementoValido(string elemento) {

	bool encontrado = false;

	int i = 0;
	while(!encontrado && i < CANTIDAD_DE_ELEMENTOS) {
		encontrado = elementos[i] == elemento;
		i++;
	}

	return encontrado;
}
