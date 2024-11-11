#ifndef LIB_H
#define LIB_H

#include <bits/stdc++.h>

struct Equipo
{
    std::string nombre;
    int partidosJugados;
    int ganados;
    int empatados;
    int perdidos;
    int golesFavor;
    int golesContra;
    int diferenciaGoles;
};

extern const std::string CLEAR_CMD;

void texto();
void inicio();
int obtenerOpc(std::string);
int menuPrincipal();
int menuCompeticion();
std::string elegirCompeticion(int, std::string);
std::string menuLiga(std::string);
std::string menuPaises(int, std::string);
int mostrarEquipos(const std::vector<std::string> &);

void pedirDatosEquipo(Equipo &equipo);
void mostrarTabla(Equipo &, Equipo &);
void calcularProbabilidades(Equipo &, Equipo &);

#endif
