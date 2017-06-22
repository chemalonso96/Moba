#pragma once 

#include"TorreTeamB.h"
#include<list>

class ListTorreTeamB
{
public:
	ListTorreTeamB();
	~ListTorreTeamB();

	list<TorreTeamB*> list_TorreB;

	void Agregar(int x, int y, int vida, Bitmap^bmp);
	void Mostrar(Graphics^gr, Bitmap^bmp);
};

ListTorreTeamB::ListTorreTeamB()
{
}

ListTorreTeamB::~ListTorreTeamB()
{
}

void ListTorreTeamB::Agregar(int x, int y, int vida, Bitmap^bmp){
	list_TorreB.push_back(new TorreTeamB(x, y, vida, bmp));
}
void ListTorreTeamB::Mostrar(Graphics^gr, Bitmap^bmp){
	for (list<TorreTeamB*>::iterator it = list_TorreB.begin(); it != list_TorreB.end(); ++it){
		if ((*it)->GET_transparente() == true){
			(*it)->Dibujar(gr, bmp);
			(*it)->DibujarVida(gr);
		}
	}
}