#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
typedef vector<string> vs;

#ifdef _WIN32
const string CLEAR_CMD = "cls";
#else
const string CLEAR_CMD = "clear";
#endif

bool flag = true;

vs mundial = {"Argentina", "Francia", "Croacia", "Marruecos", "Portugal", "Inglaterra", "Paises Bajos", "Brasil"};

vs cAmerica = {"Argentina", "Mexico", "Ecuador", "Brasil", "Colombia", "Costa Rica", "Chile", "Uruguay"};

vs eurocopa = {"Alemania", "Espana", "Italia", "Francia", "Paises Bajos", "Portugal", "Inglaterra", "Checa"};

vs laLiga = {"Real Madrid", "Barcelona", "Atl Madrid", "Sevilla"};

vs bundesliga = {"Bayern de Munich", "Frankfurt", "Dortmund", "Leverkusen"};

vs serieA = {"Juventus", "Napoli", "AC Milan", "Fiorentina"};

void texto()
{
    string texto = "\nBienvenido a Fifa 25\n\n\n\nPresiona Enter para continuar...";
    int intervalo = 800; // Intervalo de tiempo en milisegundos

    while (flag)
    {
        // Limpia la pantalla
        system(CLEAR_CMD.c_str());
        // Muestra el texto
        cout << texto << std::endl;
        // Espera un intervalo
        this_thread::sleep_for(chrono::milliseconds(intervalo));
        system(CLEAR_CMD.c_str());
        // Espera el mismo intervalo antes de mostrar el texto de nuevo
        this_thread::sleep_for(chrono::milliseconds(intervalo));
    }
}

void inicio()
{
    system(CLEAR_CMD.c_str());
    // Iniciar el parpadeo en un hilo separado
    thread parpadeoThread(texto);
    // Espera que el usuario presione una tecla
    cin.get();
    // Detiene el parpadeo
    flag = false;
    // Espera que el hilo de parpadeo termine
    parpadeoThread.join();
}

int obtenerOpc(string s)
{
    system(CLEAR_CMD.c_str());
    cout << s;
    int opc;
    cin >> opc;
    return opc;
}

int mostrarEquipos(const vs &equipos)
{

    cout << "\n";
    for (int i = 0; i < equipos.size(); i += 2)
    {
        cout << i + 1 << ". " << equipos[i];
        if (i + 1 < equipos.size())
        {
            cout << "\t\t\t" << i + 2 << ". " << equipos[i + 1] << "\n";
        }
    }
    cout << "\n0. Volver\n";

    int opcion;
    cin >> opcion;

    if (opcion == 0)
        return 0;

    return opcion;
}

string menuLiga(string str)
{
    string s = str + "Selecciona la liga del Equipo\n\n1. LaLiga\n2. Bundesliga\n3. Serie A\n0. Volver\n";
    int numLiga, opcion = obtenerOpc(s);
    system(CLEAR_CMD.c_str());
    switch (opcion)
    {
    case 1:
        cout << "Equipos de LaLiga\n";
        numLiga = mostrarEquipos(laLiga);
        if (numLiga == 0)
            return "";
        return laLiga[numLiga - 1];
    case 2:
        cout << "Equipos de la Bundesliga\n";
        numLiga = mostrarEquipos(bundesliga);
        if (numLiga == 0)
            return "";
        return bundesliga[numLiga - 1];
    case 3:
        cout << "Equipos de la Serie A\n";
        numLiga = mostrarEquipos(serieA);
        if (numLiga == 0)
            return "";
        return serieA[numLiga - 1];
    default:
        return "Opcion no valida";
    }
}

string menuPaises(int opc, string str)
{
    int numPais;
    // while (true)
    //{
    system(CLEAR_CMD.c_str());
    switch (opc)
    {
    case 2:
        cout << str << "Equipos de la Copa América\n";
        numPais = mostrarEquipos(cAmerica);
        if (numPais == 0)
            return "";
        return cAmerica[numPais - 1];
    case 3:
        cout << str << "Equipos de la Copa Mundial\n";
        numPais = mostrarEquipos(mundial);
        if (numPais == 0)
            return "";
        return mundial[numPais - 1];
    case 4:
        cout << str << "Equipos de la Eurocopa\n";
        numPais = mostrarEquipos(eurocopa);
        if (numPais == 0)
            return "";
        return eurocopa[numPais - 1];
    default:
        return "Opcion no valida";
    }
    //}
}

string elegirCompeticion(int opc, string s)
{
    switch (opc)
    {
    case 1:
        return menuLiga(s);
        break;
    case 2:
    case 3:
    case 4:
        return menuPaises(opc, s);
    default:
        return "Opcion no valida";
    }
}

int menuCompeticion()
{
    string s = "Elige una competicion\n\n1. UEFA Champions League\n2. Copa America\n3. Copa Mundial\n4. Eurocopa\n0. Atras\n";
    while (true)
    {
        int opcion = obtenerOpc(s);

        if (opcion == 0)
            return 0;

        return opcion;
    }
}

int menuPrincipal()
{
    string s = "\n1. Partido rapido\n0. Salir\n\n\nEstamos trabajando en mas modos de juego...\n";
    while (true)
    {
        int opcion = obtenerOpc(s);
        if (opcion == 0)
            return 0;

        switch (opcion)
        {
        case 1:
            int competicion = menuCompeticion();
            if (competicion == 0)
                continue;

            return competicion;
        }
    }
}

void pedirDatosEquipo(Equipo &equipo)
{
    system(CLEAR_CMD.c_str());
    cout << "Introduce los datos para el equipo " << equipo.nombre << ":\n";
    cout << "Partidos Jugados: ";
    cin >> equipo.partidosJugados;

    cout << "Partidos Ganados: ";
    cin >> equipo.ganados;

    cout << "Partidos Empatados: ";
    cin >> equipo.empatados;

    cout << "Partidos Perdidos: ";
    cin >> equipo.perdidos;

    cout << "Goles a Favor (>= " << equipo.ganados << "): ";
    cin >> equipo.golesFavor;

    cout << "Goles en Contra (>= " << equipo.perdidos << "): ";
    cin >> equipo.golesContra;

    equipo.diferenciaGoles = equipo.golesFavor - equipo.golesContra;
}

void mostrarTabla(Equipo &equipo1, Equipo &equipo2)
{
    system(CLEAR_CMD.c_str());
    cout << "Equipo\t\tPJ\tG\tE\tP\tGF\tGC\tDG\n";
    cout << equipo1.nombre << "\t" << equipo1.partidosJugados << "\t" << equipo1.ganados << "\t"
        << equipo1.empatados << "\t" << equipo1.perdidos << "\t" << equipo1.golesFavor << "\t"
        << equipo1.golesContra << "\t" << equipo1.diferenciaGoles << "\n";
    cout << equipo2.nombre << "\t" << equipo2.partidosJugados << "\t" << equipo2.ganados << "\t"
        << equipo2.empatados << "\t" << equipo2.perdidos << "\t" << equipo2.golesFavor << "\t"
        << equipo2.golesContra << "\t" << equipo2.diferenciaGoles << "\n\n";
}

void calcularProbabilidades(Equipo &equipo1, Equipo &equipo2)
{
    double probGanarEq1 = (double)(equipo1.ganados) / equipo1.partidosJugados;
    double probGanarEq2 = (double)(equipo2.ganados) / equipo2.partidosJugados;

    double probEmpateEq1 = (double)(equipo1.empatados) / equipo1.partidosJugados;
    double probEmpateEq2 = (double)(equipo2.empatados) / equipo2.partidosJugados;

    double probEmpate = (probEmpateEq1 + probEmpateEq2) / 2.0;

    // Rendimiento ofensivo y defensivo
    double ofensivoEq1 = (double)(equipo1.golesFavor) / equipo1.partidosJugados;
    double defensivoEq2 = (double)(equipo2.golesContra) / equipo2.partidosJugados;

    double ofensivoEq2 = (double)(equipo2.golesFavor) / equipo2.partidosJugados;
    double defensivoEq1 = (double)(equipo1.golesContra) / equipo1.partidosJugados;

    // Ajustar probabilidades por el rendimiento
    probGanarEq1 *= ofensivoEq1 / defensivoEq2;
    probGanarEq2 *= ofensivoEq2 / defensivoEq1;

    // Normalizar las probabilidades
    double totalProb = probGanarEq1 + probGanarEq2 + probEmpate;
    probGanarEq1 /= totalProb;
    probGanarEq2 /= totalProb;
    probEmpate /= totalProb;

    cout << fixed << setprecision(2);
    cout << "Probabilidades para el partido entre " << equipo1.nombre << " y " << equipo2.nombre << ":\n";
    cout << equipo1.nombre << " gana: " << probGanarEq1 * 100 << "%\n";
    cout << "Empate: " << probEmpate * 100 << "%\n";
    cout << equipo2.nombre << " gana: " << probGanarEq2 * 100 << "%\n";
}
