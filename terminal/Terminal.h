/*
 * Terminal.h
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#ifndef TERMINAL_TERMINAL_H_
#define TERMINAL_TERMINAL_H_

#include <string>
#include <iostream>

#include "../validaciones/Validador.h"

using namespace std;

class Terminal {
private:
	// Atributo privado
	Validador* validador;

	// Constructor
	Terminal();

public:
	static Terminal* terminal;

	// Metodos
	static Terminal* obtenerInstancia();

	/**
	 * PRE:
	 * POS: Muestra por pantalla el mensaje recibido en 'texto'. Retorna el numero ingresado por el usuario. min <= numero <= max.
	 */
	int leerNumero(string texto, int min, int max);

	/**
	 * PRE:
	 * POS: Obtiene la opcion del menu ingresada por el usuario.
	 */
	char obtenerOpcion();

	/**
	 * PRE:
	 * POS: Muestra por pantalla el mensaje recibido en 'texto'. Retorna el string ingresado por el usuario.
	 */
	string obtenerDato(string texto);


	/**
	 * PRE:
	 * POS: Muestra por pantalla el mensaje recibido en 'texto'. Retorna el valor del dato como int.
	 */
	int obtenerDatoEntero(string textoSolicitud, string formatoDelDato);


	/**
	 * PRE: casoAValidar == "escudo" || casoAValidar == "vida"
	 * POS: Vuelve a solicitar el ingreso de 'datoAValidar' mientras no sea valido, mostrando 'formatoDelDato' por pantalla.
	 */
	void validarDatoEntero(string casoAValidar, int &datoAValidar, string textoSolicitud, string formatoDelDato);

	/**
	 * PRE:
	 * POS: Vuelve a solicitar el ingreso de 'elemento' mientras no sea valido, mostrando 'textoSolicitud' por pantalla.
	 */
	void validarElemento(string &elemento, string textoSolicitud);

	// Destructor
	virtual ~Terminal();

};

#endif /* TERMINAL_TERMINAL_H_ */
