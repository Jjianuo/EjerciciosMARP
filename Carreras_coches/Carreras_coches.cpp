
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

int coches(const vector<int>& pilas, int voltaje) {
    int ret = 0;
    int i = 0; int j = pilas.size() - 1;
    while (i < j) {
        int voltAct = pilas[i]; 
        while (i < j && pilas[i] + pilas[j] < voltaje) {
            --j;
        }
        if (i < j && pilas[i] + pilas[j] >= voltaje) {
            ++ret; ++i; --j;
        }
    }
    return ret;
}

void resuelveCaso() {
    int N, V;
    // leer los datos de la entrada
    cin >> N >> V;
    // resolver el caso posiblemente llamando a otras funciones
    vector<int> pilas(N);
    for (auto& e : pilas)
        cin >> e;
    sort(pilas.begin(), pilas.end(), greater<int>());
    // escribir la soluci�n
    cout << coches(pilas, V) << '\n';
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
