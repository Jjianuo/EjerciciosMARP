
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    cout << sillas(pesos, pesoMax) << '\n';
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
