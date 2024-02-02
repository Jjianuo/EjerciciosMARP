
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

pair<int, int> resuelve(Matriz<int> const& M) {
    int n = M.numfils();
    vector<int> C(n + 1, 0);
    vector<int> C2(n + 1, 0);
    int i = 1;
    for (; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            int aux = -1;
            if (i % 2 == 0) {
                if (j == 0) { //borde izquierdo
                    aux = max(C2[j], C2[j + 1]);
                }
                else if (j == n - 1) { //borde derecho
                    aux = max(C2[j], C2[j - 1]);
                }
                else {
                    aux = max(C2[j], C2[j - 1]);
                    aux = max(aux, C2[j + 1]);
                }
                C[j] = M[i - 1][j] + aux;
            }
            else if (i % 2 != 0) {
                if (j == 0) { //borde izquierdo
                    aux = max(C[j], C[j + 1]);
                }
                else if (j == n - 1) { //borde derecho
                    aux = max(C[j], C[j - 1]);
                }
                else {
                    aux = max(C[j], C[j - 1]);
                    aux = max(aux, C[j + 1]);
                }
                C2[j] = M[i - 1][j] + aux;
            }
        }
    }

    pair<int, int> col = { -1,0 };
    if (i % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            if (C2[i] > col.first) {
                col = { C2[i], i + 1 };
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (C[i] > col.first) {
                col = { C[i], i + 1 };
            }
        }
    }

    return col;

}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    Matriz<int> M(N, N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> M[i][j];
    // escribir la solución
    pair<int, int> res = resuelve(M);
    cout << res.first << " " << res.second << "\n";
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
