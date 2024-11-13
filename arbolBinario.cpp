//
// Created by Acer on 7/11/2024.
//

#include "arbolBinario.h"

arbolBinario::arbolBinario(nodoArbol *raiz) {
    this->raiz = raiz;
}

nodoArbol *arbolBinario::getRaiz() {
    return raiz;
}

void arbolBinario::setRaiz(nodoArbol *raiz) {
    this->raiz = raiz;
}

void arbolBinario::levelOrder() {
    if (this->raiz == nullptr) {
        return;
    }
    queue<nodoArbol *> cola;
    cola.push(this->raiz);
    while (!cola.empty()) {
        nodoArbol *nodo = cola.front();
        cola.pop();
        cout << nodo->getValor() << " ";
        if (nodo->getIzq() != nullptr) {
            cola.push(nodo->getIzq());
        }
        if (nodo->getDer() != nullptr) {
            cola.push(nodo->getDer());
        }
    }
}

void arbolBinario::preOrder(nodoArbol *nodo) {
    if (nodo == nullptr) return; // Caso base: si el nodo es nulo, termina

    // Procesa el nodo actual
    cout << nodo->getValor() << " ";

    // Llama recursivamente al subárbol izquierdo
    preOrder(nodo->getIzq());

    // Llama recursivamente al subárbol derecho
    preOrder(nodo->getDer());
}
