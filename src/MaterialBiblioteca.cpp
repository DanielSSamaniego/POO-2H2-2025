#include "MaterialBiblioteca.hpp"

MaterialBiblioteca::MaterialBiblioteca(string cod, string tit, string ubi, int anio)
    : codigo(cod), titulo(tit), ubicacion(ubi), anioPublicacion(anio), disponible(true) {
    cout << "Material registrado: [" << codigo << "] " << titulo << endl;
}

MaterialBiblioteca::~MaterialBiblioteca() {
    cout << "Material eliminado: " << titulo << " (" << codigo << ")\n";
}

void MaterialBiblioteca::mostrarInfo() const {
    cout << "[" << codigo << "] " << titulo 
         << " (" << anioPublicacion << ")\n"
         << "Ubicación: " << ubicacion
         << " | Estado: " << (disponible ? "Disponible" : "Prestado") << endl;
}
