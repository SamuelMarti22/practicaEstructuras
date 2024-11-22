#include "arbolBinario.h"
#include <algorithm>

arbolBinario::arbolBinario(nodoArbol *raiz) {
    this->raiz = raiz;
}

nodoArbol *arbolBinario::getRaiz() {
    return raiz;
}

void arbolBinario::setRaiz(nodoArbol *raiz) {
    this->raiz = raiz;
}

//Pasamos el valor del vector por referencia para que se modifique en la función
void arbolBinario::preOrder(nodoArbol *nodo,  vector<nodoArbol*> &valoresViables) {
    if (nodo == nullptr){
        return; // Caso base: si el nodo es nulo, termina
    }

    // Procesa el nodo actual
    if (nodo->getViable()) {
        valoresViables.push_back(nodo);
    }

    // Llama recursivamente al subárbol izquierdo
    preOrder(nodo->getIzq(),valoresViables);

    // Llama recursivamente al subárbol derecho
    preOrder(nodo->getDer(),valoresViables);
}

// Función para crear el árbol binario, teniendo en cuenta la lista de Objetos y el peso máximo y partiendo de un nodo raiz
//En el árbol, cuando incluímos un objeto, se crea como hijo izquierdo, y se imprime con el prefijo |--; cuando no se incluye, se crea como hijo derecho y se imprime con el prefijo +--.
void arbolBinario::generarArbolFuerzaBruta(const vector<Objeto> &objetos, int pesoMaximo, nodoArbol* raiz) {
    queue<nodoArbol *> cola;
    cola.push(raiz);

    for (int i = 0; i < objetos.size(); ++i) {
        int tamaño = cola.size();
        for (int j = 0; j < tamaño; ++j) {
            nodoArbol *nodoActual = cola.front();
            cola.pop();

            // Nodo izquierdo (agregar objeto i)
            if (nodoActual->getPesoAcumulado() + objetos[i].peso <= pesoMaximo) {
                nodoArbol *izq = new nodoArbol(objetos[i].nombre, objetos[i].valor, objetos[i].peso, nodoActual);
                izq->setValorAcumulado(nodoActual->getValorAcumulado() + objetos[i].valor);
                izq->setPesoAcumulado(nodoActual->getPesoAcumulado() + objetos[i].peso);
                nodoActual->setIzq(izq);
                cola.push(izq);
            }

            // Nodo derecho (no agregar objeto i)
            nodoArbol *der = new nodoArbol(objetos[i].nombre, 0, 0, nodoActual);
            der->setValorAcumulado(nodoActual->getValorAcumulado());
            der->setPesoAcumulado(nodoActual->getPesoAcumulado());
            nodoActual->setDer(der);
            cola.push(der);
        }
    }
}

//Funcion para marcar los nodos viables (las hojas del arbol)
void arbolBinario::marcarNodosViables(nodoArbol *nodo) {
    // Caso base: si el nodo es nulo, no hacer nada
    if (nodo == nullptr) {
        return;
    }

    // Si el nodo no tiene hijos, es un nodo terminal (hoja)
    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        nodo->setViable(true); // Marcamos el nodo como viable
    }

    // Recursión a los subárboles
    marcarNodosViables(nodo->getIzq());
    marcarNodosViables(nodo->getDer());
}

//Función para mostrar el árbol binario
void arbolBinario::mostrarArbol(nodoArbol *nodo, string prefijo, bool seIncluye) {
    if (nodo != nullptr) {
        cout << prefijo;
        //Si se incluye, mustra |-- sino muestra +--
        cout << (seIncluye ? "|--" : "+--");

        // Imprimir el valor del nodo
        cout << nodo->getNombre() << " (" << nodo->getValorAcumulado() << ", " << nodo->getPesoAcumulado() << ")" << endl;

        // Calcular el prefijo para los hijos
        string nuevoPrefijo = prefijo + (seIncluye ?"|   " : "    ");

        // Llamar recursivamente a los hijos
        mostrarArbol(nodo->getIzq(), nuevoPrefijo, true);
        mostrarArbol(nodo->getDer(), nuevoPrefijo, false);
    }
}
