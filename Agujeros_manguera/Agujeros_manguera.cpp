
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

int voraz(const vector<int>& agujeros, int T) {
    if (agujeros.empty())
        return 0;
    int a = agujeros[0]; //primer agujero que se tapa
    int parches = 1;
    for (int i = 1; i < agujeros.size(); ++i) {
        if (agujeros[i] > T + a) {
            ++parches;
            a = agujeros[i];
        }
    }

    return parches;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int A, T;
    cin >> A >> T;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> agujeros(A);
    for (auto& e : agujeros)
        cin >> e;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << voraz(agujeros, T) << '\n';
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
