/*
 * Utilitario.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: nazaquintero
 */

#include "Utilitario.h"

Utilitario::Utilitario() {
	this->terminal = Terminal::obtenerInstancia();
}

Utilitario::~Utilitario() {
	delete this->terminal;
}

Utilitario* Utilitario::obtenerInstancia() {

	if(!utilitario)
		utilitario = new Utilitario();

	return utilitario;

}

void Utilitario::split(string str, char sep, vector<string> &resultado) {

	istringstream f(str);
	string s;

	while(getline(f, s, sep)) {
		resultado.push_back(s);
	}

}

void Utilitario::cargarPersonajes(Lista* listaDePersonajes) {

	fstream archivo_personajes(NOMBRE_ARCHIVO_PERSONAJES, ios::in);

	if(!archivo_personajes.is_open()) {
		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_PERSONAJES << "\", se va a crear el archivo" << endl;
		archivo_personajes.open(NOMBRE_ARCHIVO_PERSONAJES, ios::out);
		archivo_personajes.close();
		archivo_personajes.open(NOMBRE_ARCHIVO_PERSONAJES, ios::in);
	}

	string linea;
	string elemento, nombre, escudoStr, vidaStr;
	int escudo, vida;

	vector<string> datos;

	while(archivo_personajes >> linea) {

		split(linea, ',', datos);

		elemento = datos[0];
		nombre = datos[1];
		escudoStr = datos[2];
		vidaStr = datos[3];

		escudo = stol(escudoStr);
		vida = stol(vidaStr);

		FabricaDePersonaje fabricaDePersonaje;

		Personaje* personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre, escudo, vida);

		datos.clear();

		listaDePersonajes->alta(personaje, 1);

	}

	archivo_personajes.close();

}

void Utilitario::mostrarPersonaje(Personaje* personaje) {
	cout << "~~~~ Personaje ~~~~" << endl;
	cout << "Elemento: " << personaje->obtenerElemento() << "\nNombre: " << personaje->obtenerNombre() << "\nEscudo: " << personaje->obtenerEscudo() << "\nVida: " << personaje->obtenerVida() << "\nEnergia: " << personaje->obtenerEnergia() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~\n" << endl;
}

void Utilitario::mostrarNombresDePersonajes(Lista* listaDePersonajes) {

	listaDePersonajes->reiniciar();
	
	cout << "~~~~~~~~~~~~ Personajes ~~~~~~~~~~~~" << endl;
	while(listaDePersonajes->haySiguiente()) {
		Dato personaje = listaDePersonajes->siguiente();
		cout << personaje->obtenerNombre() << endl << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

int Utilitario::obtenerPosicionPersonaje(Lista* listaDePersonajes) {

	int pos = 0;
	string nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	bool encontrado = false;
	listaDePersonajes->reiniciar();

	Personaje* personaje;

	while (listaDePersonajes->haySiguiente() && !encontrado) {
		personaje = listaDePersonajes->siguiente();
		encontrado = personaje->obtenerNombre() == nombre;
		pos++;
	}

	if(!encontrado) {
		pos = -1;
	}

	return pos;

}

void Utilitario::buscarPersonajePorNombre(Lista* listaDePersonajes) {

	int pos = obtenerPosicionPersonaje(listaDePersonajes);

	Personaje* personaje;

	if(pos > 0) {
		personaje = listaDePersonajes->consulta(pos);
		mostrarPersonaje(personaje);
	} else {
		cout << "El Personaje ingresado no se encuentra en la lista." << endl << endl;
	}

}

void Utilitario::agregarNuevoPersonaje(Lista* listaDePersonajes) {
	string elemento, nombre;

	FabricaDePersonaje fabricaDePersonaje;

	elemento = this->terminal->obtenerDato(TEXTO_SOLICITUD_ELEMENTO);

	this->terminal->validarElemento(elemento, TEXTO_SOLICITUD_ELEMENTO);

	nombre = this->terminal->obtenerDato(TEXTO_SOLICITUD_NOMBRE);

	Personaje* personaje = fabricaDePersonaje.obtenerPersonaje(elemento, nombre);

	listaDePersonajes->alta(personaje, 1);
}

void Utilitario::eliminarPersonaje(Lista* listaDePersonajes) {

	int pos = obtenerPosicionPersonaje(listaDePersonajes);

	if(pos > 0) {
		Personaje* personaje = listaDePersonajes->consulta(pos);
		cout << "Se ha eliminado al personaje: " << personaje->obtenerNombre() << endl << endl;
		listaDePersonajes->baja(pos);
	} else {
		cout << "El Personaje ingresado no existe." << endl << endl;
	}

}

void Utilitario::alimentarPersonaje(Lista* listaDePersonajes) {
	int pos = obtenerPosicionPersonaje(listaDePersonajes);

	if(pos > 0) {
		Personaje* personaje = listaDePersonajes->consulta(pos);
		cout << personaje->alimentar() << endl << endl;
	} else {
		cout << "El Personaje ingresado no existe." << endl << endl;
	}
}

void Utilitario::guardarPersonajes(Lista* listaDePersonajes) {
	ofstream archivo_personajes(NOMBRE_ARCHIVO_PERSONAJES, ofstream::trunc);

	listaDePersonajes->reiniciar();

	while(listaDePersonajes->haySiguiente()) {
		archivo_personajes << listaDePersonajes->siguiente()->toString() << endl;
	}

	archivo_personajes.close();
}
