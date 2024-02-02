
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

int resuelve(int N, int F) {
    vector<int> pivotes(N, 0);
    pivotes[0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = i - F - 1; j < i; ++j) {
            if (j >= 0) {
                pivotes[i] = pivotes[i] + pivotes[j];
                pivotes[i] = pivotes[i] % 1000000007;
            }
        }
    }

    return pivotes[N - 1];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, F;
    cin >> N >> F;
    if (N == 0 && F == 0)
        return false;

    cout << resuelve(N, F) << '\n';
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
