
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int Infinito = 1000000000;
pair<int, int> resuelve(vector<int> const& potencia, vector<int> const& coste, int PMax, int PMin) {
    int n = potencia.size();
    vector<int> sol(PMax + 1, Infinito);
     sol[0] = 0; 
    for (int i = 1; i <= n; ++i) {
        for (int j = potencia[i - 1]; j <= PMax; ++j) {
            sol[j] = min(sol[j], sol[j - potencia[i - 1]] + coste[i - 1]);
        }
    }

    int pot = Infinito; int cos = Infinito;
    for (int i = PMin; i <= PMax; ++i) {
        if (cos > sol[i]) {
            cos = sol[i];
            pot = i;
        }
    }
    return {cos, pot};
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, PMax, PMin;
    cin >> N >> PMax >> PMin;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> potencia(N);
    vector<int> coste(N);
    for (auto& e : potencia)
        cin >> e;
    for (auto& e : coste)
        cin >> e;

    // escribir la soluci�n
    pair<int, int> a = resuelve(potencia, coste, PMax, PMin);
    if (a.first != Infinito)
        cout << a.first << " " << a.second;
    else
        cout << "IMPOSIBLE";

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
