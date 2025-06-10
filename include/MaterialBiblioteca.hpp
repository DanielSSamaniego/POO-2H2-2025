#ifndef MATERIALBIBLIOTECA_HPP
#define MATERIALBIBLIOTECA_HPP
#include <string>
#include <iostream>
using namespace std;

class MaterialBiblioteca {
private:
    string codigo;
    string ubicacion;
protected:
    string titulo;
    int anioPublicacion;
    bool disponible;
public:
    MaterialBiblioteca(string cod, string tit, string ubi, int anio);
    virtual ~MaterialBiblioteca();
    virtual void mostrarInfo() const;
    friend class GestorPrestamos;
};

#endif
