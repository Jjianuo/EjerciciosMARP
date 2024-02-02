
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>
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
 // 
// añade al final de sol el palíndromo más largo en patitos[i..j]
void reconstruir(string const& patitos, Matriz<int> const& patin, int i, int j, int k, string& sol) {
    if (i > j) return;
    if (i == j) sol[k] = patitos[i];
    else if (patitos[i] == patitos[j]) {
        sol[k] = patitos[i];
        sol[sol.length() - 1 - k] = patitos[i];
        reconstruir(patitos, patin, i + 1, j - 1, k + 1, sol);
    }
    else if (patin[i][j] == patin[i][j - 1] + 1) {
        sol[k] = patitos[j];
        sol[sol.length() - 1 - k] = patitos[j];
        reconstruir(patitos, patin, i, j - 1, k + 1, sol);
    }
    else {
        sol[k] = patitos[i];
        sol[sol.length() - 1 - k] = patitos[i];
        reconstruir(patitos, patin, i + 1, j, k + 1, sol);
    }
}

int rec(string& s, int i, int j, Matriz<int>& M) {
    int& res = M[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = 0;
        else if (s[i] == s[j])
            res = rec(s, i + 1, j - 1, M);
        else {
            res = min(rec(s, i + 1, j, M), rec(s, i, j - 1, M)) + 1;
        }
    }
    return res;
}

pair<int, string> resolver(string& s) {
    int n = s.size();
    Matriz<int> m(n, n, -1);

    int valor = rec(s, 0, n - 1, m);
    // cálculo de los objetos
    string sol(" ", valor + s.length());
    reconstruir(s, m, 0, n - 1, 0, sol);

    return { valor, sol };
}

bool resuelveCaso() {
    // leer los datos de la entrada
    string s;
    getline(cin, s);

    if (!std::cin)  // fin de la entrada
        return false;

    // escribir la solución
    pair<int, string> sol = resolver(s);
    cout << sol.first << " " << sol.second << "\n";
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
