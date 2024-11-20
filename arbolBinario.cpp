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

void arbolBinario::levelOrder() {
    if (this->raiz == nullptr) {
        return; // Si el árbol está vacío, no hay nada que recorrer.
    }

    // Cola que almacena pares de nodo y nivel.
    queue<pair<nodoArbol *, int>> cola;
    cola.push({this->raiz, 0}); // Empieza con la raíz en el nivel 0.

    while (!cola.empty()) {
        // Obtén el nodo y su nivel.
        auto actual = cola.front();
        nodoArbol *nodo = actual.first;
        int nivel = actual.second;
        cola.pop();

        // Imprime el nodo y su nivel.
        cout << "Nivel " << nivel << ": " << nodo->getValor() << endl;

        // Agrega los hijos del nodo a la cola con su nivel incrementado.
        if (nodo->getIzq() != nullptr) {
            cola.push({nodo->getIzq(), nivel + 1});
        }
        if (nodo->getDer() != nullptr) {
            cola.push({nodo->getDer(), nivel + 1});
        }
    }
}

void arbolBinario::preOrder(nodoArbol *nodo) {
    if (nodo == nullptr){
        return; // Caso base: si el nodo es nulo, termina
    }

    // Procesa el nodo actual
    cout << nodo->getValor() << " ";

    // Llama recursivamente al subárbol izquierdo
    preOrder(nodo->getIzq());

    // Llama recursivamente al subárbol derecho
    preOrder(nodo->getDer());
}

void arbolBinario::levelOrderAndGetLastLevelNodes(vector<nodoArbol *> &ultimoNivel) {
    if (this->raiz == nullptr) {
        return; // Si el árbol está vacío, no hay nada que recorrer.
    }

    // Cola que almacena pares de nodo y nivel.
    queue<pair<nodoArbol *, int>> cola;
    cola.push({this->raiz, 0}); // Empieza con la raíz en el nivel 0.

    int nivelActual = 0;
    int ultimoNivelEncontrado = -1;

    while (!cola.empty()) {
        // Obtén el nodo y su nivel.
        auto actual = cola.front();
        nodoArbol *nodo = actual.first;
        int nivel = actual.second;
        cola.pop();

        // Si estamos en un nuevo nivel, vaciamos el vector de nodos del último nivel
        if (nivel != ultimoNivelEncontrado) {
            // Si ya hemos encontrado nodos en un nivel anterior, los guardamos
            if (ultimoNivelEncontrado != -1) {
                // Aquí los nodos del último nivel ya fueron almacenados
                ultimoNivel.clear();
            }
            ultimoNivelEncontrado = nivel;
        }

        // Si estamos en el último nivel, agregamos el nodo al vector
        if (nivel == ultimoNivelEncontrado) {
            ultimoNivel.push_back(nodo);
        }

        // Agrega los hijos del nodo a la cola con su nivel incrementado.
        if (nodo->getIzq() != nullptr) {
            cola.push({nodo->getIzq(), nivel + 1});
        }
        if (nodo->getDer() != nullptr) {
            cola.push({nodo->getDer(), nivel + 1});
        }
    }
}

vector<vector<nodoArbol *>> arbolBinario::getPathsFromLastLevelNodes() {
    vector<vector<nodoArbol *>> paths;  // Esta será la lista de listas que almacenará los caminos.
    vector<nodoArbol *> ultimoNivel;

    // Obtener los nodos del último nivel
    levelOrderAndGetLastLevelNodes(ultimoNivel);

    // Para cada nodo terminal (del último nivel), obtener el camino hacia la raíz
    for (nodoArbol *nodo : ultimoNivel) {
        vector<nodoArbol *> camino;
        while (nodo != nullptr) {
            camino.push_back(nodo);
            nodo = nodo->getPadre();  // Subir al nodo padre
        }

        // Invertir el camino para tener la ruta desde el nodo terminal hasta la raíz
        reverse(camino.begin(), camino.end());
        paths.push_back(camino);
    }

    return paths;
}

void arbolBinario::generarArbolFuerzaBruta(const vector<Objeto> &objetos, int pesoMaximo) {
    queue<nodoArbol *> cola;
    nodoArbol *raiz = new nodoArbol(0, objetos[0].valor, objetos[0].peso, nullptr);
    cola.push(raiz);

    for (size_t i = 1; i < objetos.size(); ++i) {
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
void arbolBinario::marcarNodosViables(nodoArbol *nodo) {
    // Caso base: si el nodo es nulo, no hacer nada
    if (nodo == nullptr) {
        return;
    }

    // Si el nodo no tiene hijos, es un nodo terminal (hoja)
    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        nodo->setViable(true); // Marcamos el nodo como viable
        cout << nodo->getNombre() << endl;
    }

    // Recursión a los subárboles
    marcarNodosViables(nodo->getIzq());
    marcarNodosViables(nodo->getDer());
}