#include "nodoArbol.h"

nodoArbol::nodoArbol(const string &nombre, const int valor, const int peso, nodoArbol *padre) {
    this->valor = valor;
    this->peso = peso;
    this->nombre = nombre;
    this->valorAcumulado = 0; // Inicialmente no hay valor
    this->pesoAcumulado = 0; // Inicialmente no hay peso
    this->viable = false;
    this->izq = nullptr;
    this->der = nullptr;
    this->padre = padre;
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

void nodoArbol::calcularViable(int capacidadMaxima) {
    this->viable = (this->peso <= capacidadMaxima);
}

nodoArbol *nodoArbol::getPadre() {
    return padre;
}
void nodoArbol::setValorAcumulado(int valor) {
    this->valorAcumulado = valor;
}
void nodoArbol::setPesoAcumulado(int peso) {
    this->pesoAcumulado = peso;
}
int nodoArbol::getValorAcumulado() {
    return valorAcumulado;
}
int nodoArbol::getPesoAcumulado() {
    return pesoAcumulado;
}
string nodoArbol::getNombre() {
    return nombre;
}

void nodoArbol::imprimir() {
    cout << "Valor: " << valor << ", Peso: " << peso
            << ", Viable: " << (viable ? "Sí" : "No") << endl;
}