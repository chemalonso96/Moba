#pragma once 

#include"Padre.h"
#include"PoderPersonajeA.h"
using namespace std;
using namespace System::Drawing;

class PersonajeA:public Padre
{
public:
	int Energia;
	int puntoH;
	int puntoV;
	int AnchoI;
	int AltoI;
	bool transparente;
public:
	PersonajeA(int x, int y, Bitmap^bmp);
	PersonajeA();
	~PersonajeA();

	void Dibujar(Graphics^gr, Bitmap^bmp);
	void Mover(Graphics^gr, Bitmap^bmp, Direccion D);
	void DibujarVida(Graphics^gr);
	void DibujarEnergia(Graphics^gr);

	list<PoderPersonajeA*> list_PoderPersonajeA;
	void AgregarPoder(int x, int y, Bitmap^bmp);
	void MostrarPoder(Graphics^gr, Bitmap^bmp);
};

PersonajeA::PersonajeA(int x, int y, Bitmap^bmp){
	AnchoI = bmp->Width / 4;
	AltoI = bmp->Height / 4;
	SET_X(x);
	SET_Y(y);
	transparente=true;
	puntoH = 0;
	puntoV = 0;
	SET_Dx(0);
	SET_Dy(0);
	SET_Alto(70);
	SET_Ancho(70);
	SET_movimiento(Direccion::Ninguno);
	SET_Vida(100);
	Energia = 100;
}

PersonajeA::PersonajeA()
{
}

PersonajeA::~PersonajeA()
{
}

void PersonajeA::Dibujar(Graphics^gr, Bitmap^bmp){
	Rectangle Origen = Rectangle(AnchoI*puntoH, AltoI*puntoV, AnchoI, AltoI);
	Rectangle Fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp, Fin, Origen, GraphicsUnit::Pixel);
	if (puntoH == 3){
		puntoH = 0;
	}
	puntoH++;
}
void PersonajeA::Mover(Graphics^gr, Bitmap^bmp, Direccion D){
	switch (D)
	{
	case Arriba:
		SET_Dy(-5);
		SET_Dx(0);
		puntoV = 3;
		break;
	case Abajo:
		SET_Dy(5);
		SET_Dx(0);
		puntoV=0;
		break;
	case Derecha:
		SET_Dy(0);
		SET_Dx(5);
		puntoV=2;
		break;
	case Izquiera:
		SET_Dy(0);
		SET_Dx(-5);
		puntoV=1;
		break;
	case Ninguno:
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
void PersonajeA::DibujarVida(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), GET_X() - 1, GET_Y() - 12, 101, 4);
	gr->FillRectangle(gcnew SolidBrush(Color::Red), GET_X(), GET_Y() - 12, GET_Vida(), 3);
}
void PersonajeA::DibujarEnergia(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), GET_X() - 1, GET_Y() - 6, 101, 4);
	gr->FillRectangle(gcnew SolidBrush(Color::Yellow), GET_X(), GET_Y() - 6, Energia, 3);
}

void PersonajeA::AgregarPoder(int x, int y, Bitmap^bmp){
	list_PoderPersonajeA.push_back(new PoderPersonajeA(x, y, bmp));
}
void PersonajeA::MostrarPoder(Graphics^gr, Bitmap^bmp){
	for (list<PoderPersonajeA*>::iterator it = list_PoderPersonajeA.begin(); it != list_PoderPersonajeA.end(); ++it){
		(*it)->DibujarPoder1(gr, bmp);
	}
}