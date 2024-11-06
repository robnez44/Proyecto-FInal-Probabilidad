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

vs eurocopa = {"Alemania", "Espana", "Italia", "Francia", "Paises Bajos", "Portugal", "Inglaterra", "Republica Checa"};

vs laLiga = {"Real Madrid", "Barcelona", "Atl Madrid", "Sevilla"};

vs bundesliga = {"Bayern de Munich", "Eintracht Frankfurt", "Borussia Dortmund", "Bayer Leverkusen"};

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