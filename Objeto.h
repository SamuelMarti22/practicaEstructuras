//
// Created by Acer on 20/11/2024.
//
#include <string>
using namespace std;
#ifndef OBJETO_H
#define OBJETO_H

class Objeto {
public:
    string nombre;
    int valor;
    int peso;
    Objeto(const string &nombre, int valor, int peso);
};



#endif //OBJETO_H
