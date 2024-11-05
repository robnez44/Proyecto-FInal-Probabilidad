#include <bits/stdc++.h>
#include "lib/lib.h"
using namespace std;

int main()
{
    inicio();
    while (true)
    {
        int opc = menuPrincipal();
        if (opc == 0)
            break;

        while (true)
        {
            string nombre = elegirCompeticion(opc);
            if (nombre.empty())
                break;
        }
    }

    return 0;
}