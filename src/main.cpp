#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Libro.hpp"
#include "Revista.hpp"
#include "GestorPrestamos.hpp"
using namespace std;

int main()
{
    cout << "=== SISTEMA DE GESTIÓN DE BIBLIOTECA ===\n\n";
 
    
    Libro *libro1 = new Libro("LIB-1984", "1984", "George Orwell", "Ciencia Ficción", 328, "Estantería A5", 1949);
    Revista *revista1 = new Revista("REV-NAT123", "National Geographic", "NatGeo", 123, 5, "Hemeroteca", 2023);
    cout << "\n=== CATÁLOGO INICIAL ===\n";
    libro1->mostrarInfo();
    revista1->mostrarInfo();


    GestorPrestamos::registrarPrestamo(*libro1, "Juan Pérez");
    GestorPrestamos::registrarPrestamo(*revista1, "María García");
    cout << "\n=== ESTADO ACTUAL ===\n";
    libro1->mostrarInfo();
    revista1->mostrarInfo();
 

    GestorPrestamos::procesarDevolucion(*libro1);
    GestorPrestamos::procesarDevolucion(*revista1);
    cout << "\n=== ESTADO FINAL ===\n";
    libro1->mostrarInfo();
    revista1->mostrarInfo();

    vector<Libro*> libros;
    libros.push_back(new Libro("LIB-1984", "1984", "George Orwell", "Ciencia Ficción", 328, "Estantería A5", 1949));
    libros.push_back(new Libro("LIB-HP1", "Harry Potter", "J.K. Rowling", "Fantasía", 350, "Estantería B2", 1997));
    // Ejemplo de búsqueda por título
    string busqueda;
    cout << "Ingrese el título del libro a buscar: ";
    getline(cin, busqueda);
    bool encontrado = false;
    for (auto libro : libros) {
        if (libro->getTitulo() == busqueda) {
            cout << "\nLibro encontrado:\n";
            libro->mostrarInfo();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "\nNo se encontró un libro con ese título.\n";
    }
    // Liberar memoria
    for (auto libro : libros) delete libro;
    // Liberar memoria
    delete libro1;
    delete revista1;
    return 0;
}
