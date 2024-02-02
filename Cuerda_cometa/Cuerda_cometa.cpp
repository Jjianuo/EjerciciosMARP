
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"
#include "Matriz.h"
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
struct info {
    long long int maneras = 0;
    EntInf cuerdasMinimas = Infinito;
    EntInf costeMinimo = Infinito;
};

//info solucion(const vector<pair<int, int>>& cuerdas, Matriz<info>& M, int L, int i) {
//    int n = cuerdas.size();
//    vector<info> C(L + 1);
//    C[0] = { 0,0,0 };
//    for (int i = 1; i < n; ++i) {
//        for (int j = 1; j <= L; ++j) {
//            C[j].maneras = C[j].maneras + C[j - 1].maneras; 
//            C[j].costeMinimo = min(C[j].costeMinimo + 1, C[j - 1].costeMinimo);
//            C[j].cuerdasMinimas = min(C[j].cuerdasMinimas + cuerdas[i].second, C[j - 1].cuerdasMinimas); 
//        }
//    }
//
//    info sol = { 0,0,0 };
//    if (C[L].maneras != 0) {
//        int i = n, j = L;
//        while (j > 0) { // no se ha conseguido la cuerda
//            if (cuerdas[i - 1].first <= j && C[j].maneras == C[j - 1].maneras + 1) {
//                // tomamos una moneda de tipo i
//                j = j - cuerdas[i - 1].first;
//            }
//            else // no tomamos más monedas de tipo i
//                --i;
//        }
//    }
//
//    return sol;
//}

//info solucion(const vector<pair<int, int>>& cuerdas, Matriz<info>& M, int L, int i) {
//    if (L == 0) return {1, 0, 0};
//    if (i == 0) return {0, Infinito, Infinito};
//    if (cuerdas[i].first > L) 
//        M[i][L] = solucion(cuerdas, M, L, i - 1);
//    else {
//        info aux = solucion(cuerdas, M, L - cuerdas[i].first, i - 1);
//        info aux2 = solucion(cuerdas, M, L, i - 1);
//        M[i][L] = { aux.maneras + aux2.maneras, min(aux.cuerdasMinimas + 1, aux2.cuerdasMinimas), min(aux.costeMinimo + cuerdas[i].second, aux2.costeMinimo) };
//    }
//
//    return M[i][L];
//}

info solucion2(const vector<pair<int, int>>& c, int L) {
    int n = c.size();
    vector<info> _cuerdas(L + 1, { 0, Infinito, Infinito });
    _cuerdas[0] = { 1, 0, 0 };

    for (int i = 1; i <= n; ++i)
        for (int j = L; j >= c[i - 1].first; --j) {
            _cuerdas[j] = { 
                _cuerdas[j - c[i - 1].first].maneras + _cuerdas[j].maneras, 
                min(_cuerdas[j - c[i - 1].first].cuerdasMinimas + 1, _cuerdas[j].cuerdasMinimas),
                min(_cuerdas[j - c[i - 1].first].costeMinimo + c[i - 1].second, _cuerdas[j].costeMinimo) };
        }
    return _cuerdas[L];
}

//EntInf maneras(const vector<pair<int, int>>& cuerdas, Matriz<EntInf>& M, int L, int i) {
//    if (L == 0) return 1;
//    if (i == 0) return 0;
//    if (cuerdas[i].first > L) 
//        M[i][L] = maneras(cuerdas, M, L, i - 1);
//    else
//        M[i][L] = maneras(cuerdas, M, L - cuerdas[i].first, i - 1) + maneras(cuerdas, M, L, i - 1);
//
//    return M[i][L];
//}
//
//EntInf minimo(const vector<pair<int, int>>& cuerdas, Matriz<EntInf>& M, int L, int i) {
//    if (L == 0) return 0;
//    if (i == 0) return Infinito;
//    if (cuerdas[i].first > L)
//        M[i][L] = minimo(cuerdas, M, L, i - 1);
//    else
//        M[i][L] = min(minimo(cuerdas, M, L - cuerdas[i].first, i - 1) + 1, minimo(cuerdas, M, L, i - 1));
//
//    return M[i][L];
//}
//
//EntInf costeMinimo(const vector<pair<int, int>>& cuerdas, Matriz<EntInf>& M, int L, int i) {
//    if (L == 0) return 0;
//    if (i == 0) return Infinito;
//    if (cuerdas[i].first > L)
//        M[i][L] = costeMinimo(cuerdas, M, L, i - 1);
//    else
//        M[i][L] = min(costeMinimo(cuerdas, M, L - cuerdas[i].first, i - 1) + cuerdas[i].second, costeMinimo(cuerdas, M, L, i - 1));
//
//    return M[i][L];
//}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, V;
    cin >> N >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<pair<int, int>> cuerdas(N);
    for (int i = 0; i < N; ++i) {
        cin >> cuerdas[i].first >> cuerdas[i].second;
    }
    info sol2 = solucion2(cuerdas, V);

    if (sol2.maneras > 0)
        cout << "SI " << sol2.maneras << " " << sol2.cuerdasMinimas << " " << sol2.costeMinimo << '\n';
    else
        cout << "NO\n";

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
