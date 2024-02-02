/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


/*@ <answer>


//O(N*logN)


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using namespace std;
int seleccionTrabajos(const vector<pair<int, int>>& trabajos, int C, int F) {

	int tiempoActual = C;
	int numTrabajos = 0;
	int i = 0;
	bool pos = true;
	while (tiempoActual < F) { 
		int tiempoMaxFin = -1;

		while (i < trabajos.size() && trabajos[i].first <= tiempoActual) { 
			if(trabajos[i].second > tiempoMaxFin)
				tiempoMaxFin = trabajos[i].second;
			++i;
		}
		if (tiempoMaxFin != -1) {
			++numTrabajos;
			tiempoActual = tiempoMaxFin;
		}
		else
			return -1;

	}

	return numTrabajos;
}

bool comp_fin(pair<int, int> const& a, pair<int, int> const& b) {
	return a.first < b.first;
}

bool resuelveCaso() {
	int C, F, N;
	cin >> C >> F >> N;
	if (C == 0 && F == 0 && N == 0)
		return false;

	vector<pair<int, int>>trabajos(N); //2 pares para ini ci y fin fi

	for (auto& n : trabajos) cin >> n.first >> n.second;

	sort(trabajos.begin(), trabajos.end()); //ordena según fin 
	int nTrabajos = seleccionTrabajos(trabajos, C, F);
	if (nTrabajos < 1) cout << "Imposible";
	else cout << nTrabajos;
	cout << "\n";


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
