#pragma once 

#include"Padre.h"
using namespace System::Drawing;
using namespace std;

class PoderPersonajeA :public Padre
{
private:
	bool tranparente;
	int indice;//como no tiene pnto en la vertical solo colocamos un indice
	int AnchoI;
	int AltoI;
public:
	PoderPersonajeA(int x, int y, Bitmap^bmp);
	PoderPersonajeA();
	~PoderPersonajeA();

	void SET_transparente(bool k);
	bool GET_transparente();

	void SET_indice(int k);
	int GET_indice();

	void SET_AnchoI(int k);
	int GET_AnchoI();

	void SET_AltoI(int k);
	int GET_AltoI();

	void DibujarPoder1(Graphics^gr, Bitmap^bmp);
};

PoderPersonajeA::PoderPersonajeA(int x, int y, Bitmap^bmp)
{
	SET_transparente(false);
	SET_indice(0);
	SET_AnchoI(bmp->Width / 3);
	SET_AltoI(bmp->Height);
	SET_X(x);
	SET_Y(y);
	SET_Dx(0);
	SET_Dy(0);
	SET_Alto(50);
	SET_Ancho(50);
	SET_movimiento(Direccion::Ninguno);
}
PoderPersonajeA::PoderPersonajeA(){

}
PoderPersonajeA::~PoderPersonajeA()
{
}


void PoderPersonajeA::SET_transparente(bool k){ tranparente = k; }
bool PoderPersonajeA::GET_transparente(){ return tranparente; }

void PoderPersonajeA::SET_indice(int k){ indice = k; }
int PoderPersonajeA::GET_indice(){ return indice; }

void PoderPersonajeA::SET_AnchoI(int k){ AnchoI = k; }
int PoderPersonajeA::GET_AnchoI(){ return AnchoI; }

void PoderPersonajeA::SET_AltoI(int k){ AltoI = k; }
int PoderPersonajeA::GET_AltoI(){ return AltoI; }

void PoderPersonajeA::DibujarPoder1(Graphics^gr, Bitmap^bmp){
	Rectangle origen = Rectangle(GET_indice()*GET_AnchoI(), 0 * GET_AltoI(), GET_AnchoI(), GET_AltoI());
	Rectangle fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp, fin, origen, GraphicsUnit::Pixel);
	if (indice == 2){
		indice = 0;
	}
	indice++;
}

