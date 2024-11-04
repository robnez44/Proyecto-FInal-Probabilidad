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

void textoParpadeante()
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
        // Limpia la pantalla nuevamente
        system(CLEAR_CMD);
        // Espera el mismo intervalo antes de mostrar el texto de nuevo
        this_thread::sleep_for(chrono::milliseconds(intervalo));
    }
}

void inicio()
{
    system(CLEAR_CMD);
    // Iniciar el parpadeo en un hilo separado
    thread parpadeoThread(textoParpadeante);
    // Espera que el usuario presione una tecla
    cin.get();
    // Detiene el parpadeo
    flag = false;
    // Espera que el hilo de parpadeo termine
    parpadeoThread.join();
}

/*
void menuLiga(){
    system(CLEAR_CMD);
    cout << "Selecciona la liga del Equipo 1\n\n1. LaLiga\n2. Bundesliga\n3. Premier League\n4. Serie A\n5. Ligue 1\n";

    int opcion;
    cin >> opcion;
}
*/

void mostrarPaises(const vs& paises){
    for (int i = 0; i < paises.size(); i += 2)
            {
                cout << i + 1 << ". " << paises[i];
                if (i + 1 < paises.size())
                {
                    cout << "\t\t\t" << i + 2 << ". " << paises[i + 1] << "\n";
                }
            }
}

void menuPaises(int opc)
{
    while (true)
    {
        system(CLEAR_CMD);
        switch (opc)
        {
        case 2:
            cout << "Equipos de la Copa América\n";
            mostrarPaises(cAmerica);
            break;
        case 3: 
            cout << "Equipos de la Copa Mundial\n";
            mostrarPaises(mundial);
            break;
        case 4:
            cout << "Equipos de la Eurocopa\n";
            mostrarPaises(eurocopa);
            break;
        }

        cout << "\n0. Volver\n";
        int opcion;
        cin >> opcion;
        if (opcion == 0)
            return;
    }
}

void menuCompeticion()
{
    while (true)
    {
        system(CLEAR_CMD);
        cout << "\n1. UEFA Champions League\n2. Copa America\n3. Copa Mundial\n4. Eurocopa\n5. UEFA Super Copa\n0. Atras\n";

        int opcion;
        cin >> opcion;

        if (opcion == 0)
            return 0;

        switch (opcion)
        {
        case 1:
            // menuLiga();
            break;

        case 2:
            menuPaises(opcion);
            break;
        case 3:
            menuPaises(opcion);
            break;
        case 4:
            menuPaises(opcion);
            break;
        case 5:
            // menuLiga();
            break;
        }
    }
}

void menuPrincipal()
{
    while (true)
    {
        system(CLEAR_CMD);
        cout << "\n1. Partido rapido\n0. Salir\n\n\nEstamos trabajando en mas modos de juego...\n";

        int opcion;
        cin >> opcion;

        if (opcion == 0)
            return;

        switch (opcion)
        {
        case 1:
            menuCompeticion();
            break;
        }
    }
}
