
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

int resolver(const vector<int>& rivales, const vector<int>& broncos) {
    int ret = 0;
    for (int i = 0; i < rivales.size(); ++i) {
        if (broncos[i] > rivales[i])
            ret += broncos[i] - rivales[i];
    }
    return ret;
}

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada
    cin >> N;
    if (N == 0)
        return false;
    vector<int> rivales(N);
    vector<int> broncos(N);
    // resolver el caso posiblemente llamando a otras funciones
    for (auto& e : rivales)
        cin >> e;
    for (auto& e : broncos)
        cin >> e;

    sort(rivales.begin(), rivales.end(), greater<int>());
    sort(broncos.begin(), broncos.end());
    // escribir la solución
    cout << resolver(rivales, broncos) << '\n';
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
