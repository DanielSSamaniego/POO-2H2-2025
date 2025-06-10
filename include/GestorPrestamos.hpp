#ifndef GESTORPRESTAMOS_HPP
#define GESTORPRESTAMOS_HPP
#include <string>
using namespace std;

class MaterialBiblioteca;

class GestorPrestamos {
public:
    static void registrarPrestamo(MaterialBiblioteca& material, const string& usuario);
    static void procesarDevolucion(MaterialBiblioteca& material);
};

#endif
