#include<iostream>
#pragma once

class Foco
{
private:
    bool encendido;

public:
    foco() {
        encendido= false;
    }
    void encender()
    {
        encendido = true;
    }
    void apagar()
    {
        encendido = false;
    }
    char LeerEstado = false;
