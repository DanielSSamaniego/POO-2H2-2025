#include "Revista.hpp"
#include <iostream>

Revista::Revista(string cod, string tit, string ed, int num, int mes, string ubi, int anio)
    : MaterialBiblioteca(cod, tit, ubi, anio), editorial(ed), numero(num), mesPublicacion(mes) {}

Revista::~Revista() {
    cout << "Revista retirada: " << titulo << endl;
}

void Revista::mostrarInfo() const {
    MaterialBiblioteca::mostrarInfo();
    cout << "Editorial: " << editorial << " | Número: " << numero 
         << " | Mes: " << mesPublicacion << "\n";
}
