#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "nodoArbol.h"
#include "Objeto.h"
#include <queue>
#include <iostream>
using namespace std;

class arbolBinario {
private:
    nodoArbol *raiz;
public:
    arbolBinario(nodoArbol *raiz);
    nodoArbol *getRaiz();
    void setRaiz(nodoArbol *raiz);
    void preOrder(nodoArbol *nodo, vector<nodoArbol*> &valoresViables);
    void generarArbolFuerzaBruta(const vector<Objeto> &objetos, int pesoMaximo, nodoArbol* raiz);
    void marcarNodosViables(nodoArbol *nodo);
    void mostrarArbol(nodoArbol *nodo, string prefijo, bool esUltimo);
};



#endif //ARBOLBINARIO_H
