
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
vector<int> resolver(vector<int> const& s, int valor) {
    int n = s.size();
    vector<EntInf> sectores(valor + 1, Infinito);
    sectores[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = s[i - 1]; j <= valor; ++j) {
            sectores[j] = min(sectores[j], sectores[j - s[i - 1]] + 1);
        }
    }

    vector<int> sol;
    if (sectores[valor] != Infinito) {
        int i = n, j = valor;
        while (j > 0) { // no se ha pagado todo
            if (s[i - 1] <= j && sectores[j] == sectores[j - s[i - 1]] + 1) {
                // tomamos una moneda de tipo i
                sol.push_back(s[i - 1]);
                j = j - s[i - 1];
            }
            else // no tomamos m�s monedas de tipo i
                --i;
        }
    }
    return sol;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int valor, nSectores;
    cin >> valor >> nSectores;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> sectores(nSectores);
    for (auto& e : sectores)
        cin >> e;
    // escribir la soluci�n
    vector<int> sol = resolver(sectores, valor);
    if (!sol.empty()) {
        cout << sol.size() << ": ";
        for (auto e : sol)
            cout << e << " ";
    }
    else
        cout << "Imposible";

    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
