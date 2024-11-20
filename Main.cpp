#include "arbolBinario.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    // Ejemplo de objetos
    vector<Objeto> objetos = {
        Objeto("Hola",3, 4),  // (valor, peso)
        Objeto("Mundo",2, 3),
        Objeto("jeje", 5, 6)
    };
    int pesoMaximo = 10;

    arbolBinario arbol(nullptr);  // Crea el árbol con la raíz nula inicialmente

    // Generamos el árbol de fuerza bruta
    arbol.generarArbolFuerzaBruta(objetos, pesoMaximo);

    // Marcamos los nodos terminales (hojas) como viables
    arbol.marcarNodosViables(arbol.getRaiz());

    // Ahora puedes recorrer el árbol para encontrar los nodos viables
    // y realizar la evaluación de las soluciones viables.

    return 0;
}
