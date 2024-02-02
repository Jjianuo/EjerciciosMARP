
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

#include "Matriz.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 f(i, j) es el coste minimo de viajar al poblado j desde el poblado i
 f(i, j) = min(f(i, j), f(i + 1, j) + ci)

 casos base:
 f(i, i) = 0
 f(i, j) = 0 si j < i (no se puede ir en contra de la corriente)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int Infinito = 1000000000;

Matriz<int> resolver(Matriz<int> const& poblados) {
    int n = poblados.numfils();
    Matriz<int> caminos(n, n, 0);
    caminos[n - 2][n - 1] = poblados[n - 2][n - 1];

    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            caminos[i][j] = min(poblados[i][j], caminos[i + 1][j] + poblados[i][i + 1]);
        }
    }

    return caminos;
}

void Floyd(Matriz<int> const& G, Matriz<int>& C) {
    int V = G.numfils(); // número de vértices de G
    // inicialización
    C = G;

    // actualizaciones de las matrices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                }
            }
        }
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> poblados(N, N, Infinito);
    for(int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) 
            cin >> poblados[i][j];
        

    // resolver el caso posiblemente llamando a otras funciones
    //Matriz<int> res = resolver(poblados);
    Matriz<int> res(N, N, 0);
    Floyd(poblados, res);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }


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
