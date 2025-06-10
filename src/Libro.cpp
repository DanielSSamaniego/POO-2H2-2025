#include "Libro.hpp"
#include <iostream>

Libro::Libro(string cod, string tit, string aut, string gen, int pag, string ubi, int anio)
    : MaterialBiblioteca(cod, tit, ubi, anio), autor(aut), numPaginas(pag), genero(gen) {}

Libro::~Libro() {
    cout << "Libro descatalogado: " << titulo << endl;
}

void Libro::mostrarInfo() const {
    MaterialBiblioteca::mostrarInfo();
    cout << "Autor: " << autor << " | Género: " << genero 
         << " | Páginas: " << numPaginas << "\n";
}
