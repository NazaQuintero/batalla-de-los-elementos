/*
 * Terminal.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#include "Terminal.h"

Terminal::Terminal() {
	this->validador = Validador::obtenerInstancia();
}

Terminal::~Terminal() {
	delete this->validador;
}

Terminal* Terminal::obtenerInstancia() {

	if(!terminal)
		terminal = new Terminal();

	return terminal;
}

int Terminal::leerNumero(string texto, int min, int max) {
	string numeroStr;
	cout << texto << endl;
	cin >> numeroStr;

	while(!validador->esNumeroValido(numeroStr)) {
		cout << "El valor ingresado no es un numero. Por favor, ingrese una opcion valida:" << endl;
		cin >> numeroStr;
	}

	int opcion = stoi(numeroStr);

	while(!validador->esOpcionValida(opcion, min, max)) {
		cout << "La opcion ingresada no es correcta. Por favor, ingrese un numero entre " << min << " y " << max << " inclusives:" << endl;
		cin >> numeroStr;
		opcion = stoi(numeroStr);
	}

	return opcion;
}

char Terminal::obtenerOpcion() {
	char opcion;
	cin >> opcion;
	return opcion;
}

string Terminal::obtenerDato(string texto) {
	string dato;
	cout << texto << endl;
	cin >> dato;
	return dato;
}

int Terminal::obtenerDatoEntero(string texto_solicitud, string formatoDelDato) {
	string datoIngresado = obtenerDato(texto_solicitud);

	while(!this->validador->esNumeroValido(datoIngresado)) {
		cout << "El valor ingresado no es un numero. " << formatoDelDato << endl;
		cin >> datoIngresado;
	}

	return stol(datoIngresado);

}

void Terminal::validarDatoEntero(string casoAValidar, int &datoAValidar, string textoSolicitud, string formatoDelDato) {

	while(!this->validador->esValorCasoValido(casoAValidar, datoAValidar)) {
		cout << "Valor " << casoAValidar << " invalido" << endl;
		datoAValidar = obtenerDatoEntero(textoSolicitud, formatoDelDato);
	}

}

void Terminal::validarElemento(string &elemento, string textoSolicitud) {

	while(!this->validador->esElementoValido(elemento)) {
		cout << "Elemento invalido" << endl;
		elemento = obtenerDato(textoSolicitud);
	}
}

