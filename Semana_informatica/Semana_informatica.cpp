
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

struct infoActividad {
    int ini; int fin;

    const bool operator <(infoActividad const& other) const {
        return ini < other.ini;
    }
};

int numAmigos(vector<infoActividad> const& actividades) {
    priority_queue<int, vector<int>, greater<int>> amiguis;
    amiguis.push(actividades[0].fin);

    int cont = 0;
    for (int i = 1; i < actividades.size(); ++i) {
        int f = amiguis.top();

        if (actividades[i].ini >= f) { //hay alguien libre
            amiguis.pop();
        }
        amiguis.push(actividades[i].fin);
        cont = max(cont, (int)amiguis.size() - 1);
    }

    return cont;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<infoActividad> actividades(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        actividades[i] = { a, b };
    }

    sort(actividades.begin(), actividades.end());
    cout << numAmigos(actividades) << "\n";

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
