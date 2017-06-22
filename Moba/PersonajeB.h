#pragma once 

#include"Padre.h"
using namespace std;
using namespace System::Drawing;

class PersonajeB :public Padre
{
public:
	int Energia;
	int puntoH;
	int puntoV;
	int AnchoI;
	int AltoI;
	bool transparente;
public:
	PersonajeB(int x, int y, Bitmap^bmp);
	PersonajeB();
	~PersonajeB();

	void Dibujar(Graphics^gr, Bitmap^bmp);
	void Mover(Graphics^gr, Bitmap^bmp, Direccion2 D);
	void DibujarVida(Graphics^gr);
	void DibujarEnergia(Graphics^gr);

};

PersonajeB::PersonajeB(int x, int y, Bitmap^bmp){
	AnchoI = bmp->Width / 4;
	AltoI = bmp->Height / 4;
	SET_X(x);
	SET_Y(y);
	transparente = true;
	puntoH = 0;
	puntoV = 0;
	SET_Dx(0);
	SET_Dy(0);
	SET_Alto(70);
	SET_Ancho(70);
	SET_Vida(100);
	Energia = 100;
}

PersonajeB::PersonajeB()
{
}

PersonajeB::~PersonajeB()
{
}

void PersonajeB::Dibujar(Graphics^gr, Bitmap^bmp){
	Rectangle Origen = Rectangle(AnchoI*puntoH, AltoI*puntoV, AnchoI, AltoI);
	Rectangle Fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp, Fin, Origen, GraphicsUnit::Pixel);
	if (puntoH == 3){
		puntoH = 0;
	}
	puntoH++;
}
void PersonajeB::Mover(Graphics^gr, Bitmap^bmp, Direccion2 D){
	switch (D)
	{
	case w:
		SET_Dy(-5);
		SET_Dx(0);
		puntoV = 3;
		break;
	case s:
		SET_Dy(5);
		SET_Dx(0);
		puntoV = 0;
		break;
	case d:
		SET_Dy(0);
		SET_Dx(5);
		puntoV = 2;
		break;
	case a:
		SET_Dy(0);
		SET_Dx(-5);
		puntoV = 1;
		break;
	case n:
		SET_Dx(0);
		SET_Dy(0);
		puntoH = 0;
		break;
	}
	SET_X(GET_X() + GET_Dx());
	SET_Y(GET_Y() + GET_Dy());
	Dibujar(gr, bmp);
	DibujarEnergia(gr);
	DibujarVida(gr);
}
void PersonajeB::DibujarVida(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), GET_X() - 1, GET_Y() - 12, 101, 4);
	gr->FillRectangle(gcnew SolidBrush(Color::Red), GET_X(), GET_Y() - 12, GET_Vida(), 3);
}
void PersonajeB::DibujarEnergia(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), GET_X() - 1, GET_Y() - 6, 101, 4);
	gr->FillRectangle(gcnew SolidBrush(Color::Yellow), GET_X(), GET_Y() - 6, Energia, 3);
}