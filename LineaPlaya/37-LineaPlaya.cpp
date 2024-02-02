
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    cout << resolver(edificios) << '\n';
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
