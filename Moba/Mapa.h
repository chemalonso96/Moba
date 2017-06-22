#pragma once 

#include"Padre.h"

using namespace System::Drawing;
using namespace std;

class Mapa :public Padre
{
public:
	Mapa();
	~Mapa();

	void Dibujar(Graphics^gr, Bitmap^bmp);
};

Mapa::Mapa()
{
	SET_X(0);
	SET_Y(0);
	SET_Ancho(1357);
	SET_Alto(690);
}

Mapa::~Mapa()
{
}

void Mapa::Dibujar(Graphics^gr, Bitmap^bmp){
	gr->DrawImage(bmp, GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
}
