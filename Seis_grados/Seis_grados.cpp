
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

#include "Matriz.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int Infinito = 1000000000;

int Floyd(Matriz<int> const& G, Matriz<int>& C) {
    int V = G.numfils(); // n�mero de v�rtices de G
    // inicializaci�n
    C = G;
    int ret = 0;

    // actualizaciones de las matrices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {   
            for (int j = 0; j < V; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                }   
            }
        }
    }

    for (int i = 0; i < V; ++i) 
        for (int j = 0; j < V; ++j) {
            ret = max(ret, C[i][j]);
        }
        
    return ret;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int P, R;
    cin >> P >> R;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    Matriz<int> personas(P, P, Infinito);
    unordered_map<string, int> ids;
    // escribir la soluci�n
    int nid = 0;
    for (int i = 0; i < P; ++i)
        personas[i][i] = 0;

    for (int i = 0; i < R; ++i) {
        string n1, n2;
        cin >> n1 >> n2;
        if (ids.count(n1) == 0) {
            ids.insert({ n1, nid });
            ++nid;
        }
        if (ids.count(n2) == 0) {
            ids.insert({ n2, nid });
            ++nid;
        }

        personas[ids[n1]][ids[n2]] = 1; personas[ids[n2]][ids[n1]] = 1;
    }

    Matriz<int> aux;
    int grado = Floyd(personas, aux);
    if (grado < Infinito)
        cout << grado;
    else
        cout << "DESCONECTADA";

    cout << "\n";

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
