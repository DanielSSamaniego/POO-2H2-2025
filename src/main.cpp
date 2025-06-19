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
    vector<Revista*> revistas;

    libros.push_back(libro1);
    revistas.push_back(revista1);
    int opcion;
    do {
        cout << "\n===== MENÚ DE BIBLIOTECA =====\n";
        cout << "1. Registrar nuevo material" << endl;
        cout << "2. Consultar catálogo" << endl;
        cout << "3. Gestionar préstamos/devoluciones" << endl;
        cout << "4. Buscar materiales" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion) {
            case 1: {
                int tipo;
                cout << "Registrar: 1) Libro  2) Revista: ";
                cin >> tipo;
                cin.ignore();
                if (tipo == 1) {
                    string cod, tit, aut, gen, ubi;
                    int pag, anio;
                    cout << "Código: "; getline(cin, cod);
                    cout << "Título: "; getline(cin, tit);
                    cout << "Autor: "; getline(cin, aut);
                    cout << "Género: "; getline(cin, gen);
                    cout << "Páginas: "; cin >> pag; cin.ignore();
                    cout << "Ubicación: "; getline(cin, ubi);
                    cout << "Año: "; cin >> anio; cin.ignore();
                    libros.push_back(new Libro(cod, tit, aut, gen, pag, ubi, anio));
                    cout << "Libro registrado.\n";
                } else if (tipo == 2) {
                    string cod, tit, ed, ubi;
                    int num, mes, anio;
                    cout << "Código: "; getline(cin, cod);
                    cout << "Título: "; getline(cin, tit);
                    cout << "Editorial: "; getline(cin, ed);
                    cout << "Número: "; cin >> num; cin.ignore();
                    cout << "Mes: "; cin >> mes; cin.ignore();
                    cout << "Ubicación: "; getline(cin, ubi);
                    cout << "Año: "; cin >> anio; cin.ignore();
                    revistas.push_back(new Revista(cod, tit, ed, num, mes, ubi, anio));
                    cout << "Revista registrada.\n";
                }
                break;
            }
            case 2: {
                int subop;
                cout << "\n--- Catálogo ---\n";
                cout << "1. Libros\n2. Revistas\n0. Volver\nSeleccione una opción: ";
                cin >> subop;
                cin.ignore();
                if (subop == 1) {
                    if (libros.empty()) {
                        cout << "No hay libros registrados.\n";
                    } else {
                        cout << "\nLibros disponibles:\n";
                        for (size_t i = 0; i < libros.size(); ++i) {
                            cout << i+1 << ". " << libros[i]->getTitulo() << endl;
                        }
                        int idx;
                        cout << "Seleccione un libro para ver detalles (0 para volver): ";
                        cin >> idx;
                        cin.ignore();
                        if (idx > 0 && (size_t)idx <= libros.size()) {
                            libros[idx-1]->mostrarInfo();
                        }
                    }
                } else if (subop == 2) {
                    if (revistas.empty()) {
                        cout << "No hay revistas registradas.\n";
                    } else {
                        cout << "\nRevistas disponibles:\n";
                        for (size_t i = 0; i < revistas.size(); ++i) {
                            cout << i+1 << ". " << revistas[i]->getTitulo() << endl;
                        }
                        int idx;
                        cout << "Seleccione una revista para ver detalles (0 para volver): ";
                        cin >> idx;
                        cin.ignore();
                        if (idx > 0 && (size_t)idx <= revistas.size()) {
                            revistas[idx-1]->mostrarInfo();
                        }
                    }
                }
                break;
            }
            case 3: {
                int tipo;
                cout << "Gestionar: 1) Libro  2) Revista: ";
                cin >> tipo;
                cin.ignore();
                if (tipo == 1 && !libros.empty()) {
                    for (size_t i = 0; i < libros.size(); ++i) {
                        cout << i+1 << ". "; libros[i]->mostrarInfo();
                    }
                    int idx;
                    cout << "Seleccione libro: "; cin >> idx; cin.ignore();
                    cout << "1) Préstamo  2) Devolución: ";
                    int act; cin >> act; cin.ignore();
                    string usuario;
                    if (act == 1) {
                        cout << "Usuario: "; getline(cin, usuario);
                        GestorPrestamos::registrarPrestamo(*libros[idx-1], usuario);
                    } else if (act == 2) {
                        GestorPrestamos::procesarDevolucion(*libros[idx-1]);
                    }
                } else if (tipo == 2 && !revistas.empty()) {
                    for (size_t i = 0; i < revistas.size(); ++i) {
                        cout << i+1 << ". "; revistas[i]->mostrarInfo();
                    }
                    int idx;
                    cout << "Seleccione revista: "; cin >> idx; cin.ignore();
                    cout << "1) Préstamo  2) Devolución: ";
                    int act; cin >> act; cin.ignore();
                    string usuario;
                    if (act == 1) {
                        cout << "Usuario: "; getline(cin, usuario);
                        GestorPrestamos::registrarPrestamo(*revistas[idx-1], usuario);
                    } else if (act == 2) {
                        GestorPrestamos::procesarDevolucion(*revistas[idx-1]);
                    }
                } else {
                    cout << "No hay materiales registrados.\n";
                }
                break;
            }
            case 4: {
                int tipo;
                cout << "Buscar: 1) Libro  2) Revista: ";
                cin >> tipo;
                cin.ignore();
                string busqueda;
                bool encontrado = false;
                if (tipo == 1) {
                    cout << "Ingrese el título del libro: ";
                    getline(cin, busqueda);
                    for (auto l : libros) {
                        if (l->getTitulo() == busqueda) {
                            cout << "\nLibro encontrado:\n";
                            l->mostrarInfo();
                            encontrado = true;
                        }
                    }
                } else if (tipo == 2) {
                    cout << "Ingrese el título de la revista: ";
                    getline(cin, busqueda);
                    for (auto r : revistas) {
                        if (r->getTitulo() == busqueda) {
                            cout << "\nRevista encontrada:\n";
                            r->mostrarInfo();
                            encontrado = true;
                        }
                    }
                }
                if (!encontrado) cout << "No se encontró el material.\n";
                break;
            }
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while(opcion != 0);
  
    for (auto l : libros) delete l;
    for (auto r : revistas) delete r;

    delete libro1;
    delete revista1;
    return 0;
}
