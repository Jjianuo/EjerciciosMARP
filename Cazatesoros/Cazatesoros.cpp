
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

struct Objeto { int profundidad; int valor; };

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

//int rec(vector<Objeto> const& tesoros, int i, int j, Matriz<int>& mochila) {
//    if (mochila[i][j] != -1) // subproblema ya resuelto
//        return mochila[i][j];
//    if (i == 0 || j == 0) mochila[i][j] = 0;
//    else if (tesoros[i - 1].profundidad * 3 > j)
//        mochila[i][j] = rec(tesoros, i - 1, j, mochila);
//    else
//        mochila[i][j] = max(rec(tesoros, i - 1, j, mochila),
//            rec(tesoros, i - 1, j - (tesoros[i - 1].profundidad * 3), mochila) + tesoros[i - 1].valor);
//    return mochila[i][j];
//}

//int resuelve(vector<Objeto> const& tesoros, int T, vector<Objeto>& sol) {
//    int n = tesoros.size();
//    Matriz<int> mochila(n + 1, T + 1, -1);
//    int valor = rec(tesoros, n, T, mochila);
//    // cálculo de los objetos
//    int i = n, j = T;
//    while (i > 0 && j > 0) {
//        if (mochila[i][j] != mochila[i - 1][j]) {
//            sol.push_back(tesoros[i - 1]); j = j - (tesoros[i - 1].profundidad * 3);
//        }
//        --i;
//    }
//    return valor;
//
//}

int resuelve(vector<Objeto> const& tesoros, int T, vector<Objeto>& sol) {
    int n = tesoros.size();
    vector<int> mochila(T + 1, 0);
    int valor = 0;
    mochila[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = T; j >= 1; --j) {
            if (j - tesoros[i - 1].profundidad * 3 >= 0)
                mochila[j] = max(mochila[j], mochila[j - (tesoros[i - 1].profundidad * 3)] + tesoros[i - 1].valor);
        }

    // cálculo de los objetos
    int i = n, j = T;
    while (i > 0 && j > 0) {
        if (mochila[j] != 0) {
            sol.push_back(tesoros[i - 1]); j = j - (tesoros[i - 1].profundidad * 3);
        }
        --i;
    }
    return mochila[T];

}

bool resuelveCaso() {

    // leer los datos de la entrada
    int T, N;
    cin >> T >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<Objeto> tesoros(N);
    for (auto& e : tesoros)
        cin >> e.profundidad >> e.valor;
    // escribir la solución
    vector<Objeto> sol;
    cout << resuelve(tesoros, T, sol) << "\n";
    cout << sol.size() << "\n";
    for (int i = sol.size() - 1; i >= 0; --i) {
        cout << sol[i].profundidad << " " << sol[i].valor << "\n";
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
