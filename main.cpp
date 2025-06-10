#include <iostream>
#include <string>
#include <vector>
#include "include/Libro.hpp"
#include "include/Revista.hpp"
#include "include/GestorPrestamos.hpp"
using namespace std;

int main() {
    cout << "\n==============================================\n";
    cout << "      SISTEMA DE GESTIÓN DE BIBLIOTECA" << endl;
    cout <<   "==============================================\n\n";
    // Crear materiales
    Libro* libro1 = new Libro("LIB-1984", "1984", "George Orwell", "Ciencia Ficción", 328, "Estantería A5", 1949);
    Revista* revista1 = new Revista("REV-NAT123", "National Geographic", "NatGeo", 123, 5, "Hemeroteca", 2023);
    cout << "\n********** CATÁLOGO INICIAL **********\n";
    libro1->mostrarInfo();
    cout << "--------------------------------------\n";
    revista1->mostrarInfo();
    cout << "\n********** PRÉSTAMOS **********\n";
    GestorPrestamos::registrarPrestamo(*libro1, "Juan Pérez");
    GestorPrestamos::registrarPrestamo(*revista1, "María García");
    cout << "\n********** ESTADO ACTUAL **********\n";
    libro1->mostrarInfo();
    cout << "--------------------------------------\n";
    revista1->mostrarInfo();
    cout << "\n********** DEVOLUCIONES **********\n";
    GestorPrestamos::procesarDevolucion(*libro1);
    GestorPrestamos::procesarDevolucion(*revista1);
    cout << "\n********** ESTADO FINAL **********\n";
    libro1->mostrarInfo();
    cout << "--------------------------------------\n";
    revista1->mostrarInfo();
    // Liberar memoria
    delete libro1;
    delete revista1;
    cout << "\n==============================================\n";
    cout << "        ¡Gracias por usar el sistema!" << endl;
    cout <<   "==============================================\n";
    return 0;
}
