#pragma once 

#include"TeamA.h"
#include<List>

class ListaTeamA
{
public:
	ListaTeamA();
	~ListaTeamA();

	list<TeamA*> list_Team_A;

	void Agregar(int x, int y, Bitmap^bmp);
	void Mostrar(Graphics^gr, Bitmap^bmp);

};

ListaTeamA::ListaTeamA()
{
}

ListaTeamA::~ListaTeamA()
{
}

void ListaTeamA::Agregar(int x, int y, Bitmap^bmp){
	list_Team_A.push_back(new TeamA(x, y, bmp));
}
void ListaTeamA::Mostrar(Graphics^gr, Bitmap^bmp){
	for (list<TeamA*>::iterator it = list_Team_A.begin(); it != list_Team_A.end();++it){
		if ((*it)->GET_transparente() == true){
			(*it)->Mover(gr, bmp);
			(*it)->DibujarVida(gr);
		}
	}
	
}