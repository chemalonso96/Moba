#pragma once

#include"Padre.h"
#include"PoderTeamA.h"
#include<List>
using namespace System::Drawing;
using namespace std;

class TeamA:public Padre
{
private:
	bool transparente;
	int puntoH;
	int puntoV;
	int AnchoI;
	int AltoI;
public:
	TeamA(int x,int y,Bitmap^bmp);
	TeamA();
	~TeamA();
	void SET_transparente(bool k);
	void SET_puntoH(int k);
	void SET_puntoV(int k);
	void SET_AnchoI(int k);
	void SET_AltoI(int k);

	bool GET_transparente();
	int GET_puntoH();
	int GET_puntoV();
	int GET_AnchoI();
	int GET_AltoI();

	void Dibujar(Graphics^gr, Bitmap^bmp);
	void Mover(Graphics^gr, Bitmap^bmp);
	void DibujarVida(Graphics^gr);

	//poder
	list<PoderTeamA*> list_PoderA;
	void AgregarPoder(int x, int y, Bitmap^bmp);
	void MostrarPoder(Graphics^gr, Bitmap^bmp);
};

TeamA::TeamA(int x, int y, Bitmap^bmp)
{
	SET_X(x);
	SET_Y(y);
	SET_transparente(true);
	SET_puntoH(0);
	SET_puntoV(2);
	SET_AnchoI(bmp->Width / 12);
	SET_AltoI(bmp->Height / 8);
	SET_Dx(0);
	SET_Dy(0);
	SET_Alto(30);
	SET_Ancho(30);
	SET_movimiento(Direccion::Ninguno);
	SET_Vida(30);
}

TeamA::TeamA()
{
}

TeamA::~TeamA()
{
}

void TeamA::SET_transparente(bool k){ transparente = k; }
void TeamA::SET_puntoH(int k){ puntoH = k; }
void TeamA::SET_puntoV(int k){ puntoV = k; }
void TeamA::SET_AnchoI(int k){ AnchoI = k; }
void TeamA::SET_AltoI(int k){ AltoI = k; }

bool TeamA::GET_transparente(){return transparente;}
int TeamA::GET_puntoH(){return puntoH;}
int TeamA::GET_puntoV(){return puntoV;}
int TeamA::GET_AnchoI(){return AnchoI;}
int TeamA::GET_AltoI(){return AltoI;}

void TeamA::Dibujar(Graphics^gr, Bitmap^bmp){
	Rectangle Origen = Rectangle(GET_AnchoI()*GET_puntoH(), GET_AltoI()*GET_puntoV(), GET_AnchoI(), GET_AltoI());
	Rectangle Fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp, Fin, Origen, GraphicsUnit::Pixel);
	if (puntoH == 2){
		puntoH = 0;
	}
	puntoH++;
}
void TeamA::Mover(Graphics^gr, Bitmap^bmp){
	switch (GET_movimiento())
	{
	case Arriba:
		SET_Dy(-5);
		SET_Y(GET_Y() + GET_Dy());
		SET_puntoV(3);
		break;
	case Abajo:
		SET_Dy(5);
		SET_Y(GET_Y() + GET_Dy()); 
		SET_puntoV(0);
		break;
	case Derecha:
		SET_Dx(5);
		SET_X(GET_X() + GET_Dx());
		SET_puntoV(2);
		break;
	case Izquiera:
		SET_Dx(-5);
		SET_X(GET_X() + GET_Dx());
		SET_puntoV(1);
		break;
	case Ninguno:
		SET_Dx(0);
		SET_Dy(0);
		SET_puntoV(2);
		break;
	}
	Dibujar(gr, bmp);
}
void TeamA::DibujarVida(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black),GET_X()-1,GET_Y()-6,31,4);
	gr->FillRectangle(gcnew SolidBrush(Color::Red), GET_X(), GET_Y()-5, GET_Vida(), 3);
}


//poder
void TeamA::AgregarPoder(int x, int y, Bitmap^bmp){
	list_PoderA.push_back(new PoderTeamA(x, y, bmp));
}
void TeamA::MostrarPoder(Graphics^gr, Bitmap^bmp){
	for (list<PoderTeamA*>::iterator it = list_PoderA.begin(); it != list_PoderA.end(); ++it){
		(*it)->Dibujar(gr, bmp);
	}
}

//197-133