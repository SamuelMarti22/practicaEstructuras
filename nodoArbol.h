#ifndef NODOARBOL_H
#define NODOARBOL_H

class nodoArbol {
private:
    int valor;
    int peso;
    bool viable;
    nodoArbol *izq;
    nodoArbol *der;
public:
    nodoArbol(int valor, int peso);
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
};



#endif //NODOARBOL_H
