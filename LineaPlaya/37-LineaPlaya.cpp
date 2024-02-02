
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

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resolver(const vector<pair<int, int>>& edificios) {
    if (edificios.empty())
        return 0;
    int tunel = 0;
    int ret = 0;
    int i = 0;
    while(i < edificios.size()) {
        if (tunel <= edificios[i].second) {
            tunel = edificios[i].second;
            ++ret;
            ++i;
        }
        while (i < edificios.size() && tunel > edificios[i].first) {
            ++i;
        }
    }
    return ret;
}

struct aaa{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada
    cin >> N;
    if (N == 0)
        return false;
    vector<pair<int, int>> edificios(N);
    // resolver el caso posiblemente llamando a otras funciones
    int w, e;
    for (auto& t : edificios) {
        cin >> w >> e;
        t = { w, e };
    }

    sort(edificios.begin(), edificios.end(), aaa());
    // escribir la solución
    cout << resolver(edificios) << '\n';
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
