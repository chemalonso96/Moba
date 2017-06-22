#pragma once 

#include"Padre.h"
using namespace System::Drawing;
using namespace std;

class TorreTeamA:public Padre
{
private:
	bool transparente;
public:

	void SET_transparente(bool k);
	bool GET_transparente();
	TorreTeamA(int x, int y, int vida, Bitmap^bmp);
	TorreTeamA();
	~TorreTeamA();

	void Dibujar(Graphics^gr,Bitmap^bmp);
	void DibujarVida(Graphics^gr);
};

TorreTeamA::TorreTeamA(int x, int y, int vida,Bitmap^bmp){
	SET_X(x);
	SET_Y(y);
	SET_Ancho(100);
	SET_Alto(120);
	SET_Dy(0);
	SET_Dx(0);
	SET_Vida(vida);
	SET_movimiento(Ninguno);
	SET_transparente(true);
}
TorreTeamA::TorreTeamA()
{
} 

TorreTeamA::~TorreTeamA()
{
}

void TorreTeamA::SET_transparente(bool k){ transparente = k; }
bool TorreTeamA::GET_transparente(){ return transparente; }

void TorreTeamA::Dibujar(Graphics^gr, Bitmap^bmp){
	gr->DrawImage(bmp, GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
}
void TorreTeamA::DibujarVida(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), GET_X() - 1, GET_Y() - 6, 101, 4);
	gr->FillRectangle(gcnew SolidBrush(Color::Red), GET_X(), GET_Y() - 5, GET_Vida(), 3);
}
