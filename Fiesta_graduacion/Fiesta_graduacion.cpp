
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "Matriz.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>

vector<string> leerLista() {
    string linea;
    getline(cin, linea);
    if (!cin)
        return {};
    vector<string> sec;
    stringstream ss(linea);
    string pal;
    while (ss >> pal)
        sec.push_back(pal);
    return sec;
}

vector<string> resuelve(vector<string> const& l1, vector<string> const& l2) {
    int n1 = l1.size(), n2 = l2.size();
    Matriz<int> M(n1 + 1, n2 + 1, 0);
    for(int i = n1 - 1; i >= 0; --i)
        for (int j = n2 - 1; j >= 0; --j) {
            if (l1[i] == l2[j]) M[i][j] = M[i + 1][j + 1] + 1;
            else M[i][j] = max(M[i + 1][j], M[i][j + 1]);
        }

    vector<string> ret;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (l1[i] == l2[j]) {
            ret.push_back(l1[i]);
            ++i; ++j;
        }
        else {
            if (M[i][j] == M[i + 1][j]) ++i;
            else if (M[i][j] == M[i][j + 1]) ++j;
        }
    }

    return ret;
}

bool resuelveCaso() {

    // leemos la entrada
    auto lista1 = leerLista();
    if (!cin)
        return false;
    auto lista2 = leerLista();

    // resolver el caso

    vector<string> aux = resuelve(lista1, lista2);
    for (auto e : aux)
        cout << e << " ";
    cout << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
