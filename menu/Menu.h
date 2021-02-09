/*
 * Menu.h
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#ifndef MENU_MENU_H_
#define MENU_MENU_H_

#include <string>
#include <iostream>
#include <fstream>

#include "../terminal/Terminal.h"
#include "../utilitario/Utilitario.h"

using namespace std;

const string NOMBRE_ARCHIVO_OPCIONES = "opciones.txt";

const int CANTIDAD_DE_LINEAS = 8;
const int PRIMER_OPCION = 1;
const int ULTIMA_OPCION = 6;

class Menu {
private:
	//Atributos privados

	Terminal* terminal;
	Utilitario* utilitario;
	string opciones[CANTIDAD_DE_LINEAS];

	//Constructor vacio
	Menu();

	//Metodos privados
	void cargarOpciones();


public:
	//Atributos
	static Menu* menu;
	static Menu* obtenerInstancia();

	//Metodos

	virtual ~Menu();

	/**
	 * PRE: Las opciones fueron cargadas desde el archivo 'opciones.txt'.
	 * POS: Muestra por pantalla las opciones al usuario.
	 */
	void mostrarOpciones();

	/**
	 * PRE:
	 * POS: Muestra por pantalla el mensaje recibido en 'texto'. Retorna el numero ingresado por el usuario.
	 */
	int obtenerOpcion(string texto);

	/**
	 * PRE: listaDePersonajes != null, 1 <= opcion <= 6.
	 * POS: Ejecuta la opcion y solicita el ingreso de otra opcion mientras opcion != 6.
	 */
	void validarOpcion(int opcion, Lista* listaDePersonajes, string textoSolicitud);

	/**
	 * PRE: listaDePersonajes != null
	 * POS: Ejecuta la opcion.
	 */
	void ejecutarOpcion(int opcion, Lista* listaDePersonajes);



};

#endif /* MENU_MENU_H_ */
