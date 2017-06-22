#pragma once

#include"Matriz_Mapa.h"
#include<vector>

using namespace std;

class Vector_Matriz_Mapa
{
private:
	int V;
	int H;
	int Estado;
public:
	Vector_Matriz_Mapa();
	~Vector_Matriz_Mapa();

	vector<Matriz_Mapa*> Vector_Matriz;

	void Agregar(int x, int y, int estado);
	void Llamar_Archivo();
	void Mostrar(Graphics^gr);

};

Vector_Matriz_Mapa::Vector_Matriz_Mapa()
{

}

Vector_Matriz_Mapa::~Vector_Matriz_Mapa()
{
}

void Vector_Matriz_Mapa::Agregar(int x, int y, int estado){
	Vector_Matriz.push_back(new Matriz_Mapa(x, y, estado));
}
void Vector_Matriz_Mapa::Llamar_Archivo(){
	FILE* Fp = freopen("MATRIZ.txt", "r", stdin);
	scanf("%d %d", &V, &H);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < H; j++) {
			scanf("%d", &Estado);
			Agregar(i * 23, j * 23, Estado);
		}
	}
	fclose(Fp);
}
void Vector_Matriz_Mapa::Mostrar(Graphics^gr){
	for (int i = 0; i < Vector_Matriz.size(); i++){
		Vector_Matriz[i]->Dibujar(gr);
	}
}

