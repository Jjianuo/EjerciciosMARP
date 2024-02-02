
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct infoBat {
    int duracion;
    int index;

    const bool operator<(infoBat const& other) const {
        return duracion < other.duracion || duracion == other.duracion && index < other.index;
        //return duracion < other.duracion;
    }
};

int resuelve(IndexPQ<infoBat>& baterias, vector<infoBat>& bateriasIni, int B, int R, int T, int Z) {
    int tActual = 0;
    int repuestosUsados = 0;
    while (tActual <= T && !baterias.empty()) {
        while (!baterias.empty() && baterias.top().prioridad.duracion <= tActual) {
            int id = baterias.top().prioridad.index;
            if (bateriasIni[id].duracion - Z > 0) {
                baterias.update(baterias.top().elem, { tActual + bateriasIni[id].duracion - Z, id });
                bateriasIni[id].duracion -= Z;
            }
            else if (repuestosUsados < R) {
                baterias.update(baterias.top().elem, { tActual + bateriasIni[B + repuestosUsados].duracion, bateriasIni[B + repuestosUsados++].index });
            }
            else {
                baterias.pop();
            }
        }

        if(!baterias.empty())
            tActual = baterias.top().prioridad.duracion;
    }

    //baterias.top().prioridad.duracion <= tActual &&
    if (baterias.empty()) return -1;
    else if (repuestosUsados >= R && baterias.size() < B) return 0;
    else return 1;
}

bool resuelveCaso() {
    int B;
    cin >> B;
    if (!std::cin)  // fin de la entrada
        return false;

    int aux;
    IndexPQ<infoBat> baterias(B);
    vector<infoBat> bateriasIni;
    int i = 0;
    for (; i < B; ++i) {
        cin >> aux;
        baterias.push(i, { aux, i });
        bateriasIni.push_back({ aux, i });
    }

    int R;
    cin >> R;
    for (; i < R + B; ++i) {
        int aux;
        cin >> aux;
        bateriasIni.push_back({aux, i});
    }

    int Z, T;
    cin >> Z >> T;

    int sol = resuelve(baterias, bateriasIni, B, R, T, Z);
    if (sol == -1) {
        cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    }
    else { 
        //no se han usado todas las bats
        if (sol == 1) cout << "CORRECTO\n";
        else cout << "FALLO EN EL SISTEMA\n";

        while (!baterias.empty())
        {
            infoBat aux = baterias.top().prioridad; baterias.pop();
            cout << aux.index + 1 << " " << aux.duracion << "\n";

        }
    }

    cout << "---\n";

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
