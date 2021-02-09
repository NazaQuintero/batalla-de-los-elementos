//============================================================================
// Name        : Batalla de los elementos
// Author      : Quintero Nazareno 105296
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Batalla de los elementos C++, Ansi-style
//============================================================================

#include "menu/Menu.h"
#include "terminal/Terminal.h"
#include "validaciones/Validador.h"
#include "utilitario/Utilitario.h"

Menu* Menu::menu = 0;
Terminal* Terminal::terminal = 0;
Validador* Validador::validador = 0;
Utilitario* Utilitario::utilitario = 0;

const string TEXTO_SOLICITUD_OPCION = "Por favor, ingrese una opcion para continuar:";

int main() {

	srand(time(0));

	Lista* listaDePersonajes = new Lista();

	Utilitario* utilitario = Utilitario::obtenerInstancia();

	utilitario->cargarPersonajes(listaDePersonajes);

	Menu* menu = Menu::obtenerInstancia();

	menu->mostrarOpciones();

	int opcion = menu->obtenerOpcion(TEXTO_SOLICITUD_OPCION);

	menu->validarOpcion(opcion, listaDePersonajes, TEXTO_SOLICITUD_OPCION);

	utilitario->guardarPersonajes(listaDePersonajes);

	delete listaDePersonajes;
	delete menu;
	delete utilitario;

	return 0;
}
