
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 f(i) = horas de peli si se ve la peli i

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tiempo {
    int h;
    int m;
    int duracion;

    tiempo& operator+=(const tiempo& other) {
        this->h += other.h;
        this->m += other.m;
        while (this->m >= 60) {
            this->m -= 60;
            ++this->h;
        }

        return *this;
    }

    tiempo& operator+=(const int& other) {
        this->m += other;
        while (this->m >= 60) {
            this->m -= 60;
            ++this->h;
        }

        return *this;
    }

    friend tiempo operator+(tiempo l, const tiempo& r) {
        l += r;
        return l;
    }

    friend tiempo operator+(tiempo l, const int& r) {
        l += r;
        return l;
    }

    bool operator<(tiempo const& r) {
        return this->h < r.h || (this->h == r.h && this->m < r.m);
    }
    
    bool operator<=(tiempo const& r) {
        return this->h < r.h || (this->h == r.h && this->m <= r.m);
    }
};

int resuelve(vector<tiempo> const& horario) {
    int n = horario.size();
    int maximo = 0;
    vector<int> horas(n, 0);
    horas[0] = horario[0].duracion;

    for (int i = 0; i < n; ++i) {
        horas[i] = max(horas[i], horario[i].duracion);
        for (int j = 0; j < n; ++j) {
            if (horario[i] + horario[i].duracion + 10 <= horario[j]) {
                horas[j] = max(horas[j], horas[i] + horario[j].duracion);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        maximo = max(maximo, horas[i]);

    return maximo;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<tiempo> horario(N);
    int a, b;
    char c;
    for (int i = 0; i < N; ++i) {
        cin >> horario[i].h >> c >> horario[i].m >> horario[i].duracion;
    }
    // escribir la solución
    sort(horario.begin(), horario.end());
    cout << resuelve(horario) << '\n';
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
