#include "escritorPersonas.h"
#include "./excepciones/excepcionNoSePuedeAbrirArchivo.h"

EscritorPersonas::EscritorPersonas(std::string nombreArchivo)
{

    archivoSalida.open(nombreArchivo, std::ios::out | std::ios::binary);

    if (!archivoSalida.is_open())
    {
        throw new ExcepcionNoSePuedeAbrirArchivo();
    }
}

void EscritorPersonas::agregarPersona(Persona &persona)
{
    archivoSalida.write((char *)&persona, sizeof(Persona));
}

void EscritorPersonas::agregarVariasPersonas(std::vector<Persona> &vectorPersonas)
{
    for (Persona persona : vectorPersonas)
    {
        this->agregarPersona(persona);
    }
}

void EscritorPersonas::cerrar()
{
    archivoSalida.close();
}