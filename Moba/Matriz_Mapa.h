#pragma once 

#include<vector>

using namespace std;
using namespace System::Drawing;


class Matriz_Mapa
{
private:
	int X;
	int Y;
	int Ancho;
	int Alto;
public:

	int Estado;//Esta variable va captar los matos de la matris para pintarlos

	Matriz_Mapa();
	Matriz_Mapa(int x, int y, int estado);
	~Matriz_Mapa();

	void SET_X(int k);
	void SET_Y(int k);
	void SET_Ancho(int k);
	void SET_Alto(int k);


	int GET_X();
	int GET_Y();
	int GET_Ancho();
	int GET_Alto();

	void Dibujar(Graphics^gr);
};
Matriz_Mapa::Matriz_Mapa()
{
}

Matriz_Mapa::Matriz_Mapa(int x, int y, int estado)
{
	X = x;
	Y = y;
	Ancho = 23;
	Alto = 23;
	Estado = estado;
}

Matriz_Mapa::~Matriz_Mapa()
{
}

void Matriz_Mapa::SET_X(int k){ X = k; }
void Matriz_Mapa::SET_Y(int k){ Y = k; }
void Matriz_Mapa::SET_Ancho(int k){ Ancho = k; }
void Matriz_Mapa::SET_Alto(int k){ Alto = k; }

int Matriz_Mapa::GET_X(){ return X; }
int Matriz_Mapa::GET_Y(){ return Y; }
int Matriz_Mapa::GET_Ancho(){ return Ancho; }
int Matriz_Mapa::GET_Alto(){ return Alto; }

void Matriz_Mapa::Dibujar(Graphics^gr){
	if (Estado == 0){
		gr->DrawRectangle(gcnew Pen(Color::Yellow), X, Y, Ancho, Alto);
	}
	else if (Estado == 1){
		gr->DrawRectangle(gcnew Pen(Color::Red), X, Y, Ancho, Alto);
	}
	else if (Estado == 2){
		gr->DrawRectangle(gcnew Pen(Color::White), X, Y, Ancho, Alto);
	}
}