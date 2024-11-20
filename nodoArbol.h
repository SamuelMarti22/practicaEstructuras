#include <iostream>
using namespace std;

#ifndef NODOARBOL_H
#define NODOARBOL_H

class nodoArbol {
private:
    string nombre;
    int valor;
    int peso;
    int valorAcumulado;
    int pesoAcumulado;
    bool viable;
    nodoArbol *izq;
    nodoArbol *der;
    nodoArbol *padre;
public:
    nodoArbol(const string& nomrbe, int valor, int peso, nodoArbol *padre);
    int getValor();
    int getPeso();
    bool getViable();
    nodoArbol *getIzq();
    nodoArbol *getDer();
    void setValor(int valor);
    void setPeso(int peso);
    void setViable(bool viable);
    void setIzq(nodoArbol *izq);
    void setDer(nodoArbol *der);
    void calcularViable(int capacidadMaxima);
    nodoArbol* getPadre();
    void imprimir();
    string getNombre();
    void setNombre(string nombre);
    int getValorAcumulado();
    void setValorAcumulado(int valorAcumulado);
    int getPesoAcumulado();
    void setPesoAcumulado(int pesoAcumulado);


};



#endif //NODOARBOL_H
