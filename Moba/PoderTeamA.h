#pragma once 

#include"Padre.h"
using namespace System::Drawing;
using namespace std;

class PoderTeamA:public Padre
{
private:
	bool tranparente;
	int indice;//como no tiene pnto en la vertical solo colocamos un indice
	int AnchoI;
	int AltoI;
public:
	PoderTeamA(int x, int y, Bitmap^bmp);
	PoderTeamA();
	~PoderTeamA();

	void SET_transparente(bool k);
	bool GET_transparente();

	void SET_indice(int k);
	int GET_indice();

	void SET_AnchoI(int k);
	int GET_AnchoI();

	void SET_AltoI(int k);
	int GET_AltoI();

	void Dibujar(Graphics^gr, Bitmap^bmp);
};

PoderTeamA::PoderTeamA(int x,int y,Bitmap^bmp)
{
	SET_transparente(false);
	SET_indice(0);
	SET_AnchoI(bmp->Width / 3);
	SET_AltoI(bmp->Height);
	SET_X(x);
	SET_Y(y);
	SET_Dx(0);
	SET_Dy(0);
	SET_Alto(25);
	SET_Ancho(25);
	SET_movimiento(Direccion::Ninguno);
}
PoderTeamA::PoderTeamA(){

}
PoderTeamA::~PoderTeamA()
{
}


void PoderTeamA::SET_transparente(bool k){	tranparente = k; }
bool PoderTeamA::GET_transparente(){ return tranparente; }

void PoderTeamA::SET_indice(int k){ indice = k; }
int PoderTeamA::GET_indice(){ return indice; }

void PoderTeamA::SET_AnchoI(int k){ AnchoI = k; }
int PoderTeamA::GET_AnchoI(){ return AnchoI; }

void PoderTeamA::SET_AltoI(int k){ AltoI = k; }
int PoderTeamA::GET_AltoI(){ return AltoI; }

void PoderTeamA::Dibujar(Graphics^gr, Bitmap^bmp){
	Rectangle origen = Rectangle(GET_indice()*GET_AnchoI(),0*GET_AltoI(),GET_AnchoI(),GET_AltoI());
	Rectangle fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp,fin,origen,GraphicsUnit::Pixel);
	if (indice == 2){
		indice = 0;
	}
	indice++;
}