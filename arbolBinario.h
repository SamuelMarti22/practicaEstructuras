#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <nodoArbol.h>
#include <Objeto.h>
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
    void levelOrder();
    void preOrder(nodoArbol *nodo);
    void levelOrderAndGetLastLevelNodes(vector<nodoArbol *> &ultimoNivel);
    vector<vector<nodoArbol *>> getPathsFromLastLevelNodes();
    void generarArbolFuerzaBruta(const vector<Objeto> &objetos, int pesoMaximo);
    void marcarNodosViables(nodoArbol *nodo);
};



#endif //ARBOLBINARIO_H
