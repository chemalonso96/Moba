#pragma once

#include"Padre.h"
#include"PoderTeamB.h"
#include<List>
using namespace System::Drawing;
using namespace std;

class TeamB :public Padre
{
private:
	bool transparente;
	int puntoH;
	int puntoV;
	int AnchoI;
	int AltoI;
public:
	TeamB(int x, int y, Bitmap^bmp);
	TeamB();
	~TeamB();
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
	list<PoderTeamB*> list_PoderB;
	void AgregarPoder(int x, int y, Bitmap^bmp);
	void MostrarPoder(Graphics^gr, Bitmap^bmp);
	void EliminarPoder();
};

TeamB::TeamB(int x, int y, Bitmap^bmp)
{
	SET_X(x);
	SET_Y(y);
	SET_transparente(true);
	SET_puntoH(0);
	SET_puntoV(1);
	SET_AnchoI(bmp->Width / 12);
	SET_AltoI(bmp->Height / 8);
	SET_Dx(-5);
	SET_Dy(5);
	SET_Alto(30);
	SET_Ancho(30);
	SET_movimiento(Direccion::Ninguno);
	SET_Vida(30);
}

TeamB::TeamB()
{
}

TeamB::~TeamB()
{
}

void TeamB::SET_transparente(bool k){ transparente = k; }
void TeamB::SET_puntoH(int k){ puntoH = k; }
void TeamB::SET_puntoV(int k){ puntoV = k; }
void TeamB::SET_AnchoI(int k){ AnchoI = k; }
void TeamB::SET_AltoI(int k){ AltoI = k; }

bool TeamB::GET_transparente(){ return transparente; }
int TeamB::GET_puntoH(){ return puntoH; }
int TeamB::GET_puntoV(){ return puntoV; }
int TeamB::GET_AnchoI(){ return AnchoI; }
int TeamB::GET_AltoI(){ return AltoI; }

void TeamB::Dibujar(Graphics^gr, Bitmap^bmp){
	Rectangle Origen = Rectangle(GET_AnchoI()*GET_puntoH(), GET_AltoI()*GET_puntoV(), GET_AnchoI(), GET_AltoI());
	Rectangle Fin = Rectangle(GET_X(), GET_Y(), GET_Ancho(), GET_Alto());
	gr->DrawImage(bmp, Fin, Origen, GraphicsUnit::Pixel);
	if (puntoH == 2){
		puntoH = 0;
	}
	else{
		puntoH++;
	}
}
void TeamB::Mover(Graphics^gr, Bitmap^bmp){
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
		SET_puntoV(1);
		break;
	}
	Dibujar(gr, bmp);
}
void TeamB::DibujarVida(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), GET_X() - 1, GET_Y() - 6, 31, 4);
	gr->FillRectangle(gcnew SolidBrush(Color::Blue ), GET_X(), GET_Y() - 5, GET_Vida(), 3);
}

void TeamB::AgregarPoder(int x, int y, Bitmap^bmp){
	list_PoderB.push_back(new PoderTeamB(x, y, bmp));
}
void TeamB::MostrarPoder(Graphics^gr, Bitmap^bmp){
	for (list<PoderTeamB*>::iterator it = list_PoderB.begin(); it != list_PoderB.end(); ++it){
		(*it)->Dibujar(gr, bmp);
	}
}
void TeamB::EliminarPoder(){
	for (list<PoderTeamB*>::iterator it = list_PoderB.begin(); it != list_PoderB.end(); ++it){
		list_PoderB.pop_back();
	}
}