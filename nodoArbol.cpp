#include "nodoArbol.h"

nodoArbol::nodoArbol(const int valor, const int peso) {
    this->valor = valor;
    this->peso = peso;
    this->viable = false;
    this->izq = nullptr;
    this->der = nullptr;
}

int nodoArbol::getValor() {
    return valor;
}

int nodoArbol::getPeso() {
    return peso;
}

bool nodoArbol::getViable() {
    return viable;
}

nodoArbol *nodoArbol::getIzq() {
    return izq;
}

nodoArbol *nodoArbol::getDer() {
    return der;
}

void nodoArbol::setValor(int valor) {
    this->valor = valor;
}

void nodoArbol::setPeso(int peso) {
    this->peso = peso;
}

void nodoArbol::setViable(bool viable) {
    this->viable = viable;
}

void nodoArbol::setIzq(nodoArbol *izq) {
    this->izq = izq;
}

void nodoArbol::setDer(nodoArbol *der) {
    this->der = der;
}