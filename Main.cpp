#include "arbolBinario.h"
#include "Objeto.h"
#include <vector>
#include <algorithm> // Para std::remove_if
#include <fstream>  // Para ifstream
#include <sstream>  // Para istringstream
using namespace std;

// Función para cargar objetos desde un archivo
vector<Objeto> cargarObjetosDesdeArchivo(const string nombreArchivo) {
    vector<Objeto> objetos; // Lista donde se almacenarán los objetos
    ifstream archivo(nombreArchivo); // Abrir el archivo

    if (!archivo.is_open()) { // Verificar que se abrió correctamente
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return objetos;
    }

    string linea;
    while (getline(archivo, linea)) { // Leer línea por línea
        istringstream stream(linea); // Convertir la línea a un flujo de entrada
        string nombre;
        int valor, peso;

        // Leer los datos desde la línea
        if (stream >> nombre >> valor >> peso) {
            // Crear el objeto y añadirlo a la lista
            objetos.emplace_back(nombre, valor, peso);
        } else {
            cerr << "Error al procesar la linea: " << linea << endl;
        }
    }

    archivo.close(); // Cerrar el archivo
    return objetos; // Devolver la lista de objetos
}

//En el árbol, cuando incluímos un objeto, se crea como hijo izquierdo, y se imprime con el prefijo |--; cuando no se incluye, se crea como hijo derecho y se imprime con el prefijo +--.

int main(int argc, char *argv[]) {
    //Creamos el vector en el que se guardan los objetos del archivo
    vector<Objeto> objetos = cargarObjetosDesdeArchivo("objetos.txt");
    //Obtenemos el peso máximo
    int pesoMaximo;
    cout << "Ingrese el peso maximo: ";
    cin >> pesoMaximo;
    nodoArbol *raiz = new nodoArbol(" ", 0, 0, nullptr);
    arbolBinario arbol(raiz);  // Crea el árbol con la raíz nula inicialmente

    // Generamos el árbol de fuerza bruta
    arbol.generarArbolFuerzaBruta(objetos, pesoMaximo, raiz);
    arbol.mostrarArbol(arbol.getRaiz(),"",false);

    // Marcamos los nodos terminales (hojas) como viables
    arbol.marcarNodosViables(arbol.getRaiz());

    vector <nodoArbol *> viables;
    //Agregamos a viables los nodos viables
    arbol.preOrder(raiz, viables);
    int mayorValor = 0;
    for (nodoArbol* i : viables) {
        if (i->getValorAcumulado() > mayorValor) {
            mayorValor = i->getValorAcumulado();
        }
    }

    for (nodoArbol* i : viables) {
        if (i->getValorAcumulado() != mayorValor) {
            i->setViable(false);
        }
    }
    //Limpiamos la lista viables, para que solo contegan los nodos con el mayor valor acumulado
    viables.erase(remove_if(viables.begin(), viables.end(),
    [](nodoArbol* nodo) {
        return !nodo->getViable(); // Elimina los nodos cuyo estado viable sea falso
    }),
    viables.end());

    vector<vector<nodoArbol*>> soluciones;
    //Agregamos a soluciones las soluciones viables (todo el path, desde la hoja hasta la raiz)
    for (nodoArbol* i : viables) {
        soluciones.push_back(i->trazarLinea(i));
    }
    //Mostramos las posibles soluciones
    for (vector <nodoArbol*> i : soluciones) {
        for (nodoArbol* j : i) {
            if (j->getNombre() != " " && j->getValor() != 0) {
                cout << j->getNombre() << " -> ";
            }
        }
        cout << "Valor total: " << i[0]->getValorAcumulado() << endl;
        cout << "Peso total: " << i[0]->getPesoAcumulado() << endl;
    }
    // Ahora puedes recorrer el árbol para encontrar los nodos viables
    // y realizar la evaluación de las soluciones viables.

    return 0;
}
