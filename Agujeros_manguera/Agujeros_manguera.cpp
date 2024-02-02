
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

int voraz(const vector<int>& agujeros, int T) {
    if (agujeros.empty())
        return 0;
    int a = agujeros[0]; //primer agujero que se tapa
    int parches = 1;
    for (int i = 1; i < agujeros.size(); ++i) {
        if (agujeros[i] > T + a) {
            ++parches;
            a = agujeros[i];
        }
    }

    return parches;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int A, T;
    cin >> A >> T;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> agujeros(A);
    for (auto& e : agujeros)
        cin >> e;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
    cout << voraz(agujeros, T) << '\n';
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
