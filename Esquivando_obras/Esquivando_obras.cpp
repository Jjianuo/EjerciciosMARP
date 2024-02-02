
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
    cout << nCaminos(mapa, 0, 0, 0) << "\n";

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
