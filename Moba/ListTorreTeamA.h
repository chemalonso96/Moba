#pragma once 

#include"TorreTeamA.h"
#include<list>

class ListTorreTeamA
{
public:
	ListTorreTeamA();
	~ListTorreTeamA();

	list<TorreTeamA*> list_TorreA;

	void Agregar(int x, int y, int vida, Bitmap^bmp);
	void Mostrar(Graphics^gr, Bitmap^bmp);
};

ListTorreTeamA::ListTorreTeamA()
{
}

ListTorreTeamA::~ListTorreTeamA()
{
}

void ListTorreTeamA::Agregar(int x, int y, int vida, Bitmap^bmp){
	list_TorreA.push_back(new TorreTeamA(x, y, vida, bmp));
}
void ListTorreTeamA::Mostrar(Graphics^gr, Bitmap^bmp){
	for (list<TorreTeamA*>::iterator it = list_TorreA.begin(); it != list_TorreA.end();++it){
		if ((*it)->GET_transparente() == true){
			(*it)->Dibujar(gr, bmp);
			(*it)->DibujarVida(gr);
		}
	}
}