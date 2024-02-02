
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#include "ConjuntosDisjuntos.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 O(N + S log*N) donde N es el numero de puntos en la ciudad y S es el numero de supermercados

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C;
    cin >> N >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    ConjuntosDisjuntos cd(N);
    int v, w;
    for (int i = 0; i < C; ++i) {
        cin >> v >> w;
        --v; --w;
        cd.unir(v, w);
    }
    
    int S;
    cin >> S;
    //vector<int> supermercados(N, -1);
    //for (int i = 0; i < S; ++i) {
    //    cin >> v >> w;
    //    --v;
    //    supermercados[v] = w;

    //    int aux = cd.buscar(v);
    //    if (supermercados[aux] == -1) supermercados[aux] = w;
    //    else supermercados[aux] = min(supermercados[aux], w);
    //}

    unordered_map<int, int> supermercados;
    for (int i = 0; i < S; ++i) {
        cin >> v >> w;
        --v;

        int aux = cd.buscar(v);
        auto res = supermercados.insert({ aux, w });
        if (!res.second) {
            res.first->second = min(res.first->second, w);
        }
    }

    int K, punto;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> punto;
        --punto;
        int aux = cd.buscar(punto);
        if (supermercados.count(aux) == 0) cout << "MENUDO MARRON";
        else cout << supermercados[aux];

        cout << "\n";
    }
    cout << "---\n";

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
