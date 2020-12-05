/*
 * Utilitario.h
 *
 *  Created on: Nov 26, 2020
 *      Author: nazaquintero
 */

#ifndef UTILITARIO_UTILITARIO_H_
#define UTILITARIO_UTILITARIO_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "../tda/lista.h"
#include "../personaje/FabricaDePersonaje.h"
#include "../terminal/Terminal.h"


const string NOMBRE_ARCHIVO_PERSONAJES = "personajes.csv";
const int CANTIDAD_DE_DATOS = 4;

const string TEXTO_SOLICITUD_ELEMENTO = "Por favor, ingrese el elemento del Personaje que desea generar (tierra / fuego / agua / aire):";
const string TEXTO_SOLICITUD_NOMBRE = "Ingrese el nombre del Personaje:";
const string TEXTO_SOLICITUD_ESCUDO = "Ingrese el valor del escudo del Personaje (Entero entre " + to_string(MINIMO_VALOR_ESCUDO) + " y " + to_string(MAXIMO_VALOR_ESCUDO) + " inclusive):";
const string FORMATO_DE_ESCUDO = "Por favor, ingrese el valor del escudo (Entero entre " + to_string(MINIMO_VALOR_ESCUDO) + " y " + to_string(MAXIMO_VALOR_ESCUDO) + " inclusive):";
const string TEXTO_SOLICITUD_VIDA = "Ingrese el valor de la vida del Personaje (Entero entre " + to_string(MINIMO_VALOR_VIDA) + " y " + to_string(MAXIMO_VALOR_VIDA) + " inclusive):";
const string FORMATO_DE_VIDA = "Por favor, ingrese el valor de la vida (Entero entre " + to_string(MINIMO_VALOR_VIDA) + " y " + to_string(MAXIMO_VALOR_VIDA) + " inclusive):";

class Utilitario {
private:
	// Atributo privado
	Terminal* terminal;

	// Metodo privado
	void split(string cadena, char separador, vector<string> &resultado);

	// Constructor
	Utilitario();

public:
	// Atributo
	static Utilitario* utilitario;

	// Metodos

	/**
	 * PRE:
	 * POS: Devuelve unica instancia de Utilitario.
	 */
	static Utilitario* obtenerInstancia();

	/**
	 * PRE:
	 * POS: Carga en 'listaDePersonajes' la instancia del personajes correspondiente leido de 'personajes.csv'.
	 */
	void cargarPersonajes(Lista* listaDePersonajes);

	/**
	 * PRE: personaje != null
	 * POS: Muestra por pantalla los datos del personaje recibido por parametro.
	 */
	void mostrarPersonaje(Personaje* personaje);

	/**
	 * PRE: listaDePersonajes != null
	 * POS: Muestra por pantalla el nombre de cada personaje de 'listaDePersonajes'.
	 */
	void mostrarNombresDePersonajes(Lista* listaDePersonajes);

	/**
	 * PRE: listaDePersonajes != null
	 * POS: Devuelve la posicion en 'listaDePersonajes' del personaje ingresado por consola por el usuario.
	 */
	int obtenerPosicionPersonaje(Lista* listaDePersonajes);

	/**
	 * PRE: listaDePersonajes != null
	 * POS: Muestra por pantalla los datos del personaje en caso que se encuentre en 'listaDePersonajes'.
	 * Muestra por pantalla un mensaje de error caso contrario.
	 */
	void buscarPersonajePorNombre(Lista* listaDePersonajes);

	/**
	 * PRE:
	 * POS: Agrega en 'listaDePersonajes' el personaje que se creara con los datos ingresados por consola por el usuario.
	 */
	void agregarNuevoPersonaje(Lista* listaDePersonajes);

	/**
	 * PRE: listaDePersonajes != null
	 * POS: Se dara de baja de la 'listaDePersonajes' el personaje correspondiente al nombre ingresado por consola
	 * por el usuario.
	 */
	void eliminarPersonaje(Lista* listaDePersonajes);

	/**
	 * PRE: listaDePersonajes != null
	 * POS: Se alimentara al personaje correspondiente al nombre ingresado por consola por el usuario.
	 * Muestra un mensaje de error en caso de que el personaje no se encuentre en la lista.
	 */
	void alimentarPersonaje(Lista* listaDePersonajes);

	/**
	 * PRE:
	 * POS: Escribe en 'personajes.csv' los personajes contenidos en 'listaDePersonajes'.
	 */
	void guardarPersonajes(Lista* listaDePersonajes);


	// Destructor
	virtual ~Utilitario();

};

#endif /* UTILITARIO_UTILITARIO_H_ */
