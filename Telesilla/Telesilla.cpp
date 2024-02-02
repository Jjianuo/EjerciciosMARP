
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
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

int sillas(deque<int>& pesos, int maxPeso) {
    int ret = 0;
    int i = pesos.size() - 1;

    while (!pesos.empty()) {
        int pesoAct = pesos.back(); pesos.pop_back();
        ++ret;
        if (!pesos.empty() && pesoAct + pesos.front() <= maxPeso) {
            pesos.pop_front();
        }
    }
    return ret;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int pesoMax, personas;
    cin >> pesoMax >> personas;
    if (!std::cin)  // fin de la entrada
        return false;

    deque<int> pesos;
    int p;
    for (int i = 0; i < personas; ++i) {
        cin >> p;
        pesos.push_back(p);
    }
    // resolver el caso posiblemente llamando a otras funciones
    sort(pesos.begin(), pesos.end());
    // escribir la solución
    cout << sillas(pesos, pesoMax) << '\n';
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
