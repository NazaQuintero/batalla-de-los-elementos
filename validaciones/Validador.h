/*
 * Validador.h
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#ifndef VALIDACIONES_VALIDADOR_H_
#define VALIDACIONES_VALIDADOR_H_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int MINIMO_VALOR_ENERGIA = 0;
const int MAXIMO_VALOR_ENERGIA = 20;
const int MINIMO_VALOR_ESCUDO = 0;
const int MAXIMO_VALOR_ESCUDO = 2;
const int MINIMO_VALOR_VIDA = 10;
const int MAXIMO_VALOR_VIDA = 100;

const string NOMBRE_ARCHIVO_ELEMENTOS = "elementos.txt";
const int CANTIDAD_DE_ELEMENTOS = 4;

class Validador {
private:
	// Atributo
	string elementos[CANTIDAD_DE_ELEMENTOS];

	// Constructor
	Validador();

	// Metodo
	void cargarElementos();

public:
	// Atributos

	static Validador* validador;

	// Metodos

	static Validador* obtenerInstancia();

	/**
	 * PRE:
	 * POS: Devuelve true si la cadena pasada por parametro es un numero. False caso contrario.
	 */
	bool esNumeroValido(string numero);

	/**
	 * PRE:
	 * POS: Devuelve true si min <= opcion <= max. False caso contrario.
	 */
	bool esOpcionValida(int opcion, int min, int max);

	/**
	 * PRE:
	 * POS: Retorna true si MINIMO_VALOR_ESCUDO <= escudo <= MAXIMO_VALOR_ESCUDO. False caso contrario.
	 */
	bool esValorEscudoValido(int escudo);

	/**
	 * PRE:
	 * POS: Retorna true si MINIMO_VALOR_VIDA <= vida <= MAXIMO_VALOR_VIDA. False caso contrario.
	 */
	bool esValorVidaValido(int vida);

	/**
	 * PRE: caso == "escudo" || caso == "vida".
	 * POS: Devuelve true si para el caso, el valor es valido. False caso contrario.
	 */
	bool esValorCasoValido(string caso, int valor);

	/**
	 * PRE:
	 * POS: Devuelve true si 'elemento' es un elemento valido.
	 */
	bool esElementoValido(string elemento);

	// Destructor
	virtual ~Validador();


};

#endif /* VALIDACIONES_VALIDADOR_H_ */
