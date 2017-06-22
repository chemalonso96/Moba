#pragma once

public enum  Direccion
{
	Izquiera, Derecha, Arriba, Abajo, Ninguno
};
public enum  Direccion2
{
	a,d,w,s, n
};

class Padre
{
public:

	Padre();
	~Padre();

	void SET_X(int k);
	void SET_Y(int k);
	void SET_Ancho(int k);
	void SET_Alto(int k);
	void SET_Dx(int k);
	void SET_Dy(int k);
	void SET_Vida(int k);
	void SET_movimiento(Direccion k);

	int GET_X();
	int GET_Y();
	int GET_Ancho();
	int GET_Alto();
	int GET_Dx();
	int GET_Dy();
	int GET_Vida();
	Direccion GET_movimiento();
	Rectangle rectangulo();


private:

	int X;
	int Y;
	int Ancho;
	int Alto;
	int Dx;
	int Dy;
	int Vida;
	Direccion Movimiento;

};

Padre::Padre()
{
	X = NULL;
	Y = NULL;
	Ancho = NULL;
	Alto = NULL;
	Dx = NULL;
	Dy = NULL;
	Vida = NULL;
	Movimiento = Direccion::Ninguno;
}



Padre::~Padre()
{
}

void Padre::SET_X(int k){ X = k; }
void Padre::SET_Y(int k){ Y = k; }
void Padre::SET_Ancho(int k){ Ancho = k; }
void Padre::SET_Alto(int k){ Alto = k; }
void Padre::SET_Dx(int k){ Dx = k; }
void Padre::SET_Dy(int k){ Dy = k; }
void Padre::SET_Vida(int k){ Vida = k; }
void Padre::SET_movimiento(Direccion k){ Movimiento = k; }

int Padre::GET_X(){ return X; }
int Padre::GET_Y(){ return Y; }
int Padre::GET_Ancho(){ return Ancho; }
int Padre::GET_Alto(){ return Alto; }
int Padre::GET_Dx(){ return Dx; }
int Padre::GET_Dy(){ return Dy; }
int Padre::GET_Vida(){ return Vida; }
Direccion Padre::GET_movimiento(){ return Movimiento; }
Rectangle Padre::rectangulo(){return Rectangle(X, Y, Ancho, Alto);}
