#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

class Lista {
private:
    // atributos
    Nodo* primero;
    Nodo* actual;
    int cantidad;

public:
    // constructor
    // POS: crea una cola vacia
    Lista();

    // PRE: 0 < pos <= cantidad + 1
    // POS: inserta el dato d en la posicion pos, la 1 es la primera
    //        ademas incrementa cantidad en 1
    void alta(Dato d, int pos);

    // PRE: 0 < pos <= cantidad
    // POS: saca el elemento que esta en pos
    void baja(int pos);

    // PRE: 0 < pos <= cantidad
    // POS: devuelve el elemento que esta en pos
    Dato consulta(int pos);

    // PRE:
    // POS: devuelve true si la lista esta vacia.
    bool vacia();

    // POS: libera la memoria
    virtual ~Lista();

    // PRE:
    // POS: devuelve la cantidad de elementos en la lista.
    int obtenerCantidad();

    // PRE:
    // POS: reinicia la posicion actual del iterador.
    void reiniciar();

    // PRE:
    // POS: devuelve true si el iterador puede seguir avanzando a la siguiente posicion, false caso contrario.
    bool haySiguiente();

    // PRE: haySiguiente() == true
    // POS: devuelve el Dato de la siguiente posicion.
    Dato siguiente();

    //POS: devuelve true si d esta en lista, false caso contrario
    bool esta(Dato d);

private:
    Nodo* obtenerNodo(int pos);
};


#endif // LISTA_H_INCLUDED
