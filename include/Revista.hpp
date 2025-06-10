#ifndef REVISTA_HPP
#define REVISTA_HPP
#include "MaterialBiblioteca.hpp"
#include <string>
using namespace std;

class Revista : public MaterialBiblioteca {
private:
    string editorial;
    int numero;
    int mesPublicacion;
public:
    Revista(string cod, string tit, string ed, int num, int mes, string ubi, int anio);
    virtual ~Revista() override;
    virtual void mostrarInfo() const override;
};

#endif
