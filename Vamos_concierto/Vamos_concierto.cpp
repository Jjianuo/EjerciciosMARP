
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

struct infoFestival {
    int grupos; int precio;

    bool operator < (infoFestival const& other) const {
        return grupos < other.grupos || (grupos == other.grupos && precio > other.precio);
    }
};

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 f(i, j) = maximo numero de grupos que puede ver con el presupuesto i con los grupos del 1 al j

 f(i) = max(gk) para festivales de precio de 0 <= k <= i

 casos base:
 f(0) = 0

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resuelve(vector<infoFestival> const& festivales, int P) {
    vector<int> v(P + 1, 0);
    int n = festivales.size();

    v[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = P; j >= festivales[i].precio; --j) {
            if(j - festivales[i].precio >= 0)
                v[j] = max(v[j], v[j - festivales[i].precio] + festivales[i].grupos);
        }
    }

    return v[P];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int P, N;
    cin >> P >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<infoFestival> festivales(N);
    for (auto& e : festivales) {
        cin >> e.grupos >> e.precio;
    }
    //sort(festivales.begin(), festivales.end());
    cout << resuelve(festivales, P) << "\n";

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
