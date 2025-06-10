#ifndef LIBRO_HPP
#define LIBRO_HPP
#include "MaterialBiblioteca.hpp"
#include <string>
using namespace std;

class Libro : public MaterialBiblioteca {
private:
    string autor;
    int numPaginas;
    string genero;
public:
    Libro(string cod, string tit, string aut, string gen, int pag, string ubi, int anio);
    virtual ~Libro() override;
    virtual void mostrarInfo() const override;
};

#endif
