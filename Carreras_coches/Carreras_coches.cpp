
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

int coches(const vector<int>& pilas, int voltaje) {
    int ret = 0;
    int i = 0; int j = pilas.size() - 1;
    while (i < j) {
        int voltAct = pilas[i]; 
        while (i < j && pilas[i] + pilas[j] < voltaje) {
            --j;
        }
        if (i < j && pilas[i] + pilas[j] >= voltaje) {
            ++ret; ++i; --j;
        }
    }
    return ret;
}

void resuelveCaso() {
    int N, V;
    // leer los datos de la entrada
    cin >> N >> V;
    // resolver el caso posiblemente llamando a otras funciones
    vector<int> pilas(N);
    for (auto& e : pilas)
        cin >> e;
    sort(pilas.begin(), pilas.end(), greater<int>());
    // escribir la solución
    cout << coches(pilas, V) << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
