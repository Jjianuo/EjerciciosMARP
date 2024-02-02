
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "Matriz.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 f(i, j) = minimo numero necesario de veces de hacer trim desde i hasta j para una palabra s 

 f(i, j) = f(i + x, j + y) si i == j
 f(i, j) = min(f(i + x, j), f(i, j + y)) si i != j

 casos base:
 f(i, i) = 1
 f(j, i) = 0

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resolver(string S, Matriz<int>& M, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (M[i][j] != -1) return M[i][j];

    int k = i, l = j;
    while (k < j && S[k] == S[k + 1]) {
        ++k;
    } 
    while (l > i && S[l] == S[l - 1]) {
        --l;
    }
    if (S[i] == S[j])
        M[i][j] = resolver(S, M, k + 1, l - 1) + 1;
    else
        M[i][j] = min(resolver(S, M, k + 1, j) + 1, resolver(S, M, i, l - 1) + 1);

    return M[i][j];
}

int resolver(string S) {
    int n = S.size();
    Matriz<int> M(n, n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

        }
    }

}

bool resuelveCaso() {

    // leer los datos de la entrada
    string S;
    cin >> S;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> M(S.size(), S.size(), -1);
    cout << resolver(S, M, 0, S.size() - 1) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
