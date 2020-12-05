#include "nodo.h"

Nodo::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

Nodo::~Nodo() {
	delete dato;
}

void Nodo::cambiarDato(Dato d) {
    dato = d;
}

void Nodo::cambiarSiguiente(Nodo* s) {
    this->siguiente = s;
}

Dato Nodo::obtenerDato() {
    return dato;
}

Nodo* Nodo::obtenerSiguiente() {
    return siguiente;
}
