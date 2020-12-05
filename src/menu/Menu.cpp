/*
 * Menu.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: nazaquintero
 */

#include "Menu.h"

Menu::Menu() {
	this->terminal = Terminal::obtenerInstancia();
	this->utilitario = Utilitario::obtenerInstancia();
	cargarOpciones();
}

Menu::~Menu() {
}

void Menu::cargarOpciones() {
	fstream archivo_opciones(NOMBRE_ARCHIVO_OPCIONES, ios::in);

	if(!archivo_opciones.is_open()) {

		cout << "No se encontro un archivo con el nombre \"" << NOMBRE_ARCHIVO_OPCIONES << "\" ." << endl;

	} else {

		string linea;

		int i = 0;
		while(getline(archivo_opciones, linea) && i < CANTIDAD_DE_LINEAS) {
			opciones[i] = linea;
			i++;
		}

	}
	archivo_opciones.close();
}

Menu* Menu::obtenerInstancia() {

	if(!menu)
		menu = new Menu();

	return menu;
}

void Menu::mostrarOpciones() {

	for (int i = 0; i < CANTIDAD_DE_LINEAS; ++i) {
		if(i == 0 || i == CANTIDAD_DE_LINEAS - 1) {
			cout << opciones[i] << endl << endl;
		} else {
			cout << opciones[i] << endl;
		}
	}

}

int Menu::obtenerOpcion(string texto) {
	return this->terminal->leerNumero(texto, PRIMER_OPCION, ULTIMA_OPCION);
}

void Menu::validarOpcion(int opcion, Lista* listaDePersonajes, string textoSolicitud) {
	while(opcion != ULTIMA_OPCION) {

		ejecutarOpcion(opcion, listaDePersonajes);

		mostrarOpciones();

		opcion = obtenerOpcion(textoSolicitud);
	}
}

void Menu::ejecutarOpcion(int opcion, Lista* listaDePersonajes) {
	switch (opcion) {
		case 1:
			utilitario->agregarNuevoPersonaje(listaDePersonajes);
			break;
		case 2:
			utilitario->eliminarPersonaje(listaDePersonajes);
			break;
		case 3:
			utilitario->mostrarNombresDePersonajes(listaDePersonajes);
			break;
		case 4:
			utilitario->buscarPersonajePorNombre(listaDePersonajes);
			break;
		case 5:
			utilitario->alimentarPersonaje(listaDePersonajes);
			break;
		default:
			cout << "La opcion ingresada no es correcta." << endl << endl;
			break;
	}
}

