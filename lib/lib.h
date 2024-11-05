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

void texto();
void inicio();
int obtenerOpc(std::string);
int menuPrincipal();

int menuCompeticion();
std::string elegirCompeticion(int);

void menuLiga();
void menuEquiposLiga();

int mostrarPaises(const std::vector<std::string> &);
std::string menuPaises(int);

void calcularProbabilidades(Equipo e1, Equipo e2);
void mostrarTabla(Equipo e1, Equipo e2);

#endif
