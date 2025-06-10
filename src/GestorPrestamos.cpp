#include "GestorPrestamos.hpp"
#include "MaterialBiblioteca.hpp"
#include <iostream>

void GestorPrestamos::registrarPrestamo(MaterialBiblioteca& material, const string& usuario) {
    if (material.disponible) {
        material.disponible = false;
        cout << "\n[PRÉSTAMO] " << material.titulo 
             << " prestado a: " << usuario << endl;
    } else {
        cout << "\n[ERROR] " << material.titulo << " no está disponible\n";
    }
}

void GestorPrestamos::procesarDevolucion(MaterialBiblioteca& material) {
    if (!material.disponible) {
        material.disponible = true;
        cout << "\n[DEVOLUCIÓN] " << material.titulo << " regresado\n";
    } else {
        cout << "\n[ERROR] " << material.titulo << " ya está disponible\n";
    }
}
