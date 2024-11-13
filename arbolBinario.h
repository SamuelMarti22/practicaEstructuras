#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <nodoArbol.h>
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
};



#endif //ARBOLBINARIO_H
