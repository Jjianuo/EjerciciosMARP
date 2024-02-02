
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
