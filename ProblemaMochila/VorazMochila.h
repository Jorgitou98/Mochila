#ifndef VorazMochila_H
#define VorazMochila_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h> 
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;


struct Objeto {
	double peso, valor;
	size_t id;
	bool operator >(Objeto const& o) const {
		return (valor / peso) > (o.valor / o.peso);
	}
	bool operator <(Objeto const& o) const {
		return (valor / peso) < (o.valor / o.peso);
	}
};

void mochilaVoraz(vector<Objeto> & objetos, double M,
	vector<double> & sol, double & valor, size_t & objetosMetidos) { // O(N log N)
	size_t N = objetos.size();
	sort(objetos.begin(), objetos.end(), greater<Objeto>());
	double peso = 0; valor = 0;
	size_t i;
	for (i = 0; i < N && peso + objetos[i].peso <= M; ++i) {
		sol[objetos[i].id] = 1; // el objeto D[i].id cabe completo
		objetosMetidos++;
		peso += objetos[i].peso;
		valor += objetos[i].valor;
	}
	if (i < N) { // partir el objeto D[i].id
		sol[objetos[i].id] = (M - peso) / objetos[i].peso;
		valor += sol[objetos[i].id] * objetos[i].valor;
	}
}

#endif