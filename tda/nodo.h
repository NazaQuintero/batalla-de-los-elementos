#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>
#include "../personaje/Personaje.h"

using namespace std;

typedef Personaje* Dato;

class Nodo {
private:
    // atributos
    Dato dato;
    Nodo* siguiente;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato = d y siguiente = 0
    Nodo(Dato d);

    // destructor
    ~Nodo();

    // PRE:
    // POS: cambia el dato del nodo.
    void cambiarDato(Dato d);

    // PRE:
    // POS: cambia la referencia al siguiente nodo del parametro implicito
    void cambiarSiguiente(Nodo* s);

    // PRE:
    // POS: devuelve el dato del nodo.
    Dato obtenerDato();

    // PRE:
    // POS: devuelve el nodo siguiente al nodo pasado por parametro implicito.
    Nodo* obtenerSiguiente();
};

#endif // NODO_H_INCLUDED
