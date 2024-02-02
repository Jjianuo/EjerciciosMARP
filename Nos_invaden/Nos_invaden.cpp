
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

int victorias(const vector<int>& ej1, const vector<int>& ej2) {
    int v = 0;
    int i = 0; int j = 0;
    while (i < ej1.size() && j < ej2.size()) {
        if (ej1[i] <= ej2[j]) { //hay victoria
            ++v; ++i; ++j;
        }
        else {
            ++j;
        }
    }
    return v;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> ej1(n);
    vector<int> ej2(n);
    for (auto& e : ej1)
        cin >> e;
    for (auto& e : ej2)
        cin >> e;
    sort(ej1.begin(), ej1.end());
    sort(ej2.begin(), ej2.end());
    // escribir la soluci�n
    cout << victorias(ej1, ej2) << '\n';
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
