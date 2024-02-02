
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 * 
 * MARP16 Pedro León Miranda
 * MARP48 Jianuo Wen
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


/*@ <answer>

 f(i, j) es un par que describe:
    - .formas --> el numero de formas de pagar una cantidad j considerando desde el tipo 1 al i utilizando el minimo numero de monedas
    - .monedas --> el numero min de monedas para pagar una cantidad j considerando desde el tipo 1 al i

 casos recursivos:
 Se descarta el tipo de monedas
 - vi > j --> f(i,j).monedas = f(i-1, j).monedas
              f(i,j).formas = f(i-1, j).formas

 No se descarta el tipo de monedas
 - vi <= j -->
     - f(i-1, j).monedas == f(i, j-vi).monedas + 1 
            --> f(i,j).formas = f(i-1, j).formas + f(i, j-vi).formas
            Tambien hay que actualizar el minimo numero de monedas
                f(i,j).monedas = f(i-1, j).monedas || f(i, j-vi).monedas    Ambos valores son iguales, da igual cual coger

     - f(i-1, j).monedas < f(i, j-vi).monedas + 1
            --> f(i,j).formas = f(i-1, j).formas
                f(i,j).monedas = f(i-1, j).monedas

     - f(i-1, j).monedas > f(i, j-vi).monedas + 1
            --> f(i,j).formas = f(i, j-vi).formas + 1
                f(i,j).monedas = f(i, j-vi).monedas

 2 casos bases
 No hay monedas para pagar
 f(0, j).monedas = infinito
 f(0, j).formas = 0

 No hay nada que pagar
 f(i, 0).monedas = 0
 f(i, 0).formas = 1

 Llamada inicial --> f(N, C)
 - N --> numero de tipos de monedas
 - C --> cantidad total a pagar

 Se ha resuelto por programacion dinamica ascendente y se ha reducido el espacio a un vector de tam C
 - Complejidad tiempo --> C*N
 - Complejdiad espacio --> C

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

int Infinito = 1000000000;

struct infoSol { 
    int minimo; int formas; 
};

int resuelve(int C, vector<int> const& tiposMonedas) {
    int n = tiposMonedas.size();
    vector<infoSol> monedas(C + 1, { Infinito, 0 });
    monedas[0] = { 0, 1 };
    for (int i = 1; i <= n; ++i) {
        for (int j = tiposMonedas[i - 1]; j <= C; ++j) {
            //int aux = min(monedas[j].minimo, monedas[j - tiposMonedas[i - 1]].minimo + 1);
            if (monedas[j].minimo == monedas[j - tiposMonedas[i - 1]].minimo + 1) {
                monedas[j] = { monedas[j].minimo, monedas[j].formas + monedas[j - tiposMonedas[i - 1]].formas };
            }
            else if (monedas[j - tiposMonedas[i - 1]].minimo + 1 < monedas[j].minimo) {
                monedas[j] = { monedas[j - tiposMonedas[i - 1]]. minimo + 1, monedas[j - tiposMonedas[i - 1]].formas };
            }
        }
    }

    return monedas[C].formas;
}

bool resuelveCaso() {

    int C, N;
    cin >> C >> N;
    if (!cin)
        return false;

    // leer el resto del caso y resolverlo
    vector<int> tiposMonedas(N);
    for (int i = 0; i < N; ++i) {
        cin >> tiposMonedas[i];
    }

    cout << resuelve(C, tiposMonedas) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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
