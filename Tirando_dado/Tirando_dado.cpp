
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"

int Infinito = 1000000000;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 f(i, j) es el numero de formas de conseguir la cantidad j con el numero de caras i
 f(i, j) = 

 casos base:
 f(0, j) = 0 si j > 0
 f(i, 0) = 0 si i > 0

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

//int resolverAux(Matriz<int>& M, int i, int j) {
//    if (i == j) return 1;
//    if (i == 0 || i > j) return 0;
//    if (i < j && j == 0) return 0;
//
//    M[i][j] = resolverAux(M, i - 1, j) + resolverAux(M, i, j - i);
//
//    return M[i][j];
//}
//
//int resolver(int C, int S) {
//    Matriz<int> M(C + 1, S + 1, Infinito);
//    M[0][0] = 0;
//    int ret = resolverAux(M, C, S);
//    return ret;
//}

int resolver(int C, int S) {
    //Matriz<int> M(C + 1, S + 1, 0);
    //M[0][0] = 0;
    //for (int i = 1; i <= C; ++i) {
    //    for (int j = 1; j <= S; ++j) {
    //        if (i < j)
    //            M[i][j] = M[i - 1][j] + M[i][j - i];
    //        else if (i > j)
    //            M[i][j] = M[i - 1][j];
    //        else
    //            M[i][j] = M[i - 1][j] + 1;
    //    }
    //}

    vector<int> M(S + 1, 0);
    M[0] = 0;
    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= S; ++j) {
            if (i < j)
                M[j] += M[j - i];
            if(i == j)
                ++M[j];
        }
    }

    return M[S];
}

void resuelveCaso() {
    int C, S;
    cin >> C >> S;

    cout << resolver(C, S) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
