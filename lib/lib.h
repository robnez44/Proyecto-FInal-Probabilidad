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

void textoParpadeante();
void inicio();
void menuPrincipal();

void menuCompeticion();

void menuLiga();
void menuEquiposLiga();

void mostrarPaises(const std::vector<std::string>&);
void menuPaises(int);

void calcularProbabilidades(Equipo e1, Equipo e2);
void mostrarTabla(Equipo e1, Equipo e2);

#endif
