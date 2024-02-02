
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

#include "ConjuntosDisjuntos.h"
#include "Grafo.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 O(N * M)

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int Infinito = 1000000000;

class resolver : public ConjuntosDisjuntos {
    vector<int> minimos;
    vector<bool> usado;
public:
    resolver(int N) : ConjuntosDisjuntos(N), minimos(N, Infinito), usado(N, false) { };

    int costeRumor(vector<int> const& soborno) {
        int acu = 0;
        for (int i = 0; i < minimos.size(); ++i) {
            int aux = buscar(i);
            minimos[aux] = min(minimos[aux], soborno[i]);
        }
        for (int i = 0; i < minimos.size(); ++i) {
            int aux = buscar(i);
            if (!usado[aux]) {
                acu += minimos[aux];
                usado[aux] = true;
            }
        }

        return acu;
    }
};

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    resolver cs(N);
    vector<int> soborno(N);
    for (auto& e : soborno)
        cin >> e;

    int a, b;
    for (int i = 0;i < M; ++i) {
        cin >> a >> b;
        --a; --b;
        cs.unir(a, b);
    }

    cout << cs.costeRumor(soborno) << "\n";

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
