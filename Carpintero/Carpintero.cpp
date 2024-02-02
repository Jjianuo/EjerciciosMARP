
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include "EnterosInf.h"

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

EntInf resuelve(vector<int> const& marcas, int L) {
    int n = marcas.size() - 2;
    Matriz<EntInf> cortes(n + 2, n + 2, 0);

    for(int i = 0; i < n; ++i)
        cortes[i][i + 1] = 0;

    for (int d = 2; d < n + 2; ++d) // recorre diagonales
        for (int i = 0; i < n - d + 2; ++i)  { // recorre elementos de diagonal 
            int j = i + d;
            cortes[i][j] = Infinito;
            for (int k = i + 1; k < j; ++k) { // k es el corte
                EntInf temp = cortes[i][k] + cortes[k][j] + 2 * (marcas[j] - marcas[i]);
                if (temp < cortes[i][j]) { // es mejor partir por k
                    cortes[i][j] = temp;
                }
            }
        }
    return cortes[0][n + 1];
}

bool resuelveCaso() {
    int L, N;
    // leer los datos de la entrada
    cin >> L >> N;
    if (L == 0 && N == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> marcas(N + 2);
    marcas[0] = 0; marcas[N + 1] = L;
    for (int i = 1; i <= N; ++i)
        cin >> marcas[i];
    // escribir la soluci�n
    cout << resuelve(marcas, L) << "\n";
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
