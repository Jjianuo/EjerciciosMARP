
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

int nCaminos(Matriz<char> const& mapa, int i, int j, int distancia) {
    //if (i >= mapa.numfils() || j >= mapa.numcols() || (i < mapa.numfils() && j < mapa.numcols() && mapa[i][j] == 'X')) return 0;
    //if (i == mapa.numfils() - 1 && j == mapa.numcols() - 1 && distancia == (mapa.numfils() - 1) + (mapa.numcols() - 1)) return 1;

    //return nCaminos(mapa, i + 1, j, distancia + 1) + nCaminos(mapa, i, j + 1, distancia + 1);

    int n = mapa.numfils();
    vector<int> casillas(mapa.numcols() + 1, 0);
    casillas[0] = 0;
    casillas[1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= mapa.numcols(); ++j) {
            if(mapa[i - 1][j - 1] != 'X')
                casillas[j] = casillas[j - 1] + casillas[j];
            else
                casillas[j] = 0;
        }
    }
    return casillas[mapa.numcols()];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int filas, columnas;
    cin >> filas >> columnas;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    Matriz<char> mapa(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> mapa[i][j];
        }
    }

    // escribir la solución
    cout << nCaminos(mapa, 0, 0, 0) << "\n";

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
