#pragma once 

#include"Padre.h"
using namespace System::Drawing;
using namespace std;

class PoderTeamB :public Padre
{
private:
	bool tranparente;
	int indice;//como no tiene pnto en la vertical solo colocamos un indice
	int AnchoI;
	int AltoI;
public:
	PoderTeamB(int x, int y, Bitmap^bmp);
	PoderTeamB();
	~PoderTeamB();

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

PoderTeamB::PoderTeamB(int x, int y, Bitmap^bmp)
{
	SET_transparente(false);
	SET_indice(0);
	SET_AnchoI(bmp->Width / 5);
	SET_AltoI(bmp->Height);
	SET_X(x);
	SET_Y(y);
	SET_Dx(0);
	SET_Dy(0);
	SET_Alto(30);
	SET_Ancho(30);
	SET_movimiento(Direccion::Ninguno);
}
PoderTeamB::PoderTeamB(){

}
PoderTeamB::~PoderTeamB()
{
}


void PoderTeamB::SET_transparente(bool k){ tranparente = k; }
bool PoderTeamB::GET_transparente(){ return tranparente; }

void PoderTeamB::SET_indice(int k){ indice = k; }
int PoderTeamB::GET_indice(){ return indice; }

void PoderTeamB::SET_AnchoI(int k){ AnchoI = k; }
int PoderTeamB::GET_AnchoI(){ return AnchoI; }

void PoderTeamB::SET_AltoI(int k){ AltoI = k; }
int PoderTeamB::GET_AltoI(){ return AltoI; }

void PoderTeamB::Dibujar(Graphics^gr, Bitmap^bmp){
	Rectangle origen = Rectangle(GET_indice()*GET_AnchoI(), 0 * GET_AltoI(), GET_AnchoI(), GET_AltoI());
	Rectangle fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp, fin, origen, GraphicsUnit::Pixel);
	if (indice == 5){
		indice = 0;
	}
	indice++;
}