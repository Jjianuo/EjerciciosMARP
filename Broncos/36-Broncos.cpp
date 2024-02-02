
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
    // escribir la soluci�n
    cout << resolver(rivales, broncos) << '\n';
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
