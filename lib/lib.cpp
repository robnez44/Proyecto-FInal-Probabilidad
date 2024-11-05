#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
typedef vector<string> vs;

#ifdef _WIN32
#define CLEAR_CMD "cls"
#else
#define CLEAR_CMD "clear"
#endif

bool flag = true;

vs mundial = {"Argentina", "Francia", "Croacia", "Marruecos", "Portugal", "Inglaterra", "Paises Bajos", "Brasil"};

vs cAmerica = {"Argentina", "Mexico", "Ecuador", "Brasil", "Colombia", "Costa Rica", "Chile", "Uruguay"};

vs eurocopa = {"Alemania", "Espana", "Italia", "Francia", "Paises Bajos", "Portugal", "Inglaterra", "Republica Checa"};

void texto()
{
    string texto = "\nBienvenido a Fifa 25\n\n\n\nPresiona Enter para continuar...";
    int intervalo = 800; // Intervalo de tiempo en milisegundos

    while (flag)
    {
        // Limpia la pantalla
        system(CLEAR_CMD);
        // Muestra el texto
        cout << texto << std::endl;
        // Espera un intervalo
        this_thread::sleep_for(chrono::milliseconds(intervalo));
        system(CLEAR_CMD);
        // Espera el mismo intervalo antes de mostrar el texto de nuevo
        this_thread::sleep_for(chrono::milliseconds(intervalo));
    }
}

void inicio()
{
    system(CLEAR_CMD);
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
    system(CLEAR_CMD);
    cout << s;
    int opc;
    cin >> opc;
    return opc;
}

/*
void menuLiga(){
    system(CLEAR_CMD);
    cout << "Selecciona la liga del Equipo 1\n\n1. LaLiga\n2. Bundesliga\n3. Premier League\n4. Serie A\n5. Ligue 1\n";

    int opcion;
    cin >> opcion;
}
*/

int mostrarPaises(const vs &paises)
{
    for (int i = 0; i < paises.size(); i += 2)
    {
        cout << i + 1 << ". " << paises[i];
        if (i + 1 < paises.size())
        {
            cout << "\t\t\t" << i + 2 << ". " << paises[i + 1] << "\n";
        }
    }
    cout << "\n0. Volver\n";

    int opcion;
    cin >> opcion;

    if (opcion == 0)
        return 0;

    return opcion;
}

string menuPaises(int opc)
{
    int numPais;
    while (true)
    {
        system(CLEAR_CMD);
        switch (opc)
        {
        case 2:
            cout << "Equipos de la Copa América\n";
            numPais = mostrarPaises(cAmerica);
            if (numPais == 0)
                return "";
            return cAmerica[numPais - 1];
            break;
        case 3:
            cout << "Equipos de la Copa Mundial\n";
            numPais = mostrarPaises(mundial);
            if (numPais == 0)
                return "";
            return mundial[numPais - 1];
            break;
        case 4:
            cout << "Equipos de la Eurocopa\n";
            numPais = mostrarPaises(eurocopa);
            if (numPais == 0)
                return "";
            return eurocopa[numPais - 1];
            break;
        }
    }
}

string elegirCompeticion(int opc)
{
    switch (opc)
    {
    case 1:
        return "";
        // menuLiga();
        break;
    case 2:
    case 3:
    case 4:
        return menuPaises(opc);
        break;
    case 5:
        return "";
        // menuLiga();
        break;
    default:
        return "Opcion no valida";
    }
}

int menuCompeticion()
{
    string s = "\n1. UEFA Champions League\n2. Copa America\n3. Copa Mundial\n4. Eurocopa\n5. UEFA Super Copa\n0. Atras\n";
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
            break;
        }
    }
}