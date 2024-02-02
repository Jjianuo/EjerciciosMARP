
/*@ <authors>
 *
 * MARP16 Pedro León Miranda
 * MARP48 Jianuo Wen
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"
#include "EnterosInf.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Resolvemos el problema por programación dinámica basándonos en la siguiente
 recurrencia:

 n es el numero de filas y m numero de columnas
 aij es el valor que corresponde con la longitud de salto indicada en la componente (i,j) de la matriz proporcionada 

 f(i,j) = número de formas en las que se puede llegar a la casilla (n,m) desde (i,j)
 
 Un caso básico es que llegamos a la casilla (n,m), en ese caso hay una forma de llegar como mínimo
 f(n,m) = 1

 En los casos recursivos distinguimno según si nos salimos o no de la matriz.
 Si i + aij > n o j + aij > m se sale del tablero, no se tiene en cuenta.
 En caso contrario 
 f(i,j) = f(i, j + aij) si i + aij > n
 f(i,j) = f(i + aij, j) si j + aij > m
 f(i,j) = f(i + aij, j) + f(i, j + aij) si (i + aij < n && j + aij < m)
 
 La llamada inicial sería f(1,1) porque queremos saber el número de formas de ir desde (1,1) a (n,m)
 Implementamos la función de manera ascendente rellenando una tabla de tamaño n * m, de derecha a izquierda y de abajo a arriba
 Una vez rellenada en la casilla (0,0) aparecerá el número de formas

 La complejidad está en O(n * m) tanto en tiempo como en espacio

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int resuelve(Matriz<int> const& M, int i, int j) {
    if (i == M.numfils() - 1 && j == M.numcols() - 1)
        return 1;
    if (i > M.numfils() - 1 || j > M.numcols() - 1)
        return 0;

    return resuelve(M, i + M[i][j], j) + resuelve(M, i, j + M[i][j]);
}

int resuelve2(Matriz<int> const& M, int i, int j, Matriz<int> & M2) {
    if (i == M.numfils() - 1 && j == M.numcols() - 1)
        return 1;
    if (i > M.numfils() - 1 || j > M.numcols() - 1)
        return 0;
    if (M2[i][j] != -1)
        return M2[i][j];

    M2[i][j] = resuelve2(M, i + M[i][j], j, M2) + resuelve2(M, i, j + M[i][j], M2);
    return M2[i][j];
}

int resuelve3(Matriz<int> const& M) {
    Matriz<int> M2(M.numfils(), M.numcols(), 0);
    M2[M.numfils() - 1][M.numcols() - 1] = 1;
    for (int i = M.numfils() - 1; i >= 0; --i) {
        for (int j = M.numcols() - 1; j >= 0; --j) {
            if (i + M[i][j] < M.numfils()) {
                M2[i][j] += M2[i + M[i][j]][j];
            }
            if (j + M[i][j] < M.numcols()) {
                M2[i][j] += M2[i][j + M[i][j]];
            }
        }
    }

    return M2[0][0];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int filas, columnas;
    cin >> filas >> columnas;
    if (!std::cin)  // fin de la entrada
        return false;
    Matriz<int> M(filas, columnas);
    Matriz<int> M2(filas, columnas, -1);
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            cin >> M[i][j];
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    //cout << resuelve(M, 0, 0) << "\n";
    cout << resuelve3(M) << "\n";
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
#endif
    return 0;
}
