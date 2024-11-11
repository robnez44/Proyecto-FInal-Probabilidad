#include <bits/stdc++.h>
#include "lib/lib.h"
using namespace std;

int main()
{
    Equipo equipo1, equipo2;
    string nombre1, nombre2;

    inicio();
    do
    {
        int opc = menuPrincipal();
        if (opc == 0)
            break;

        nombre1 = elegirCompeticion(opc, "");
        string s = "Ahora elige el equipo 2\n\n";
        nombre2 = elegirCompeticion(opc, s);

        if (nombre1.empty() && nombre2.empty())
            break;

        equipo1.nombre = nombre1;
        equipo2.nombre = nombre2;

        pedirDatosEquipo(equipo1);
        pedirDatosEquipo(equipo2);

        mostrarTabla(equipo1, equipo2);

        

        cin.ignore();
        cin.get();
    } while (true);

    return 0;
}