#pragma once 

#include"TeamB.h"
#include<List>

class ListaTeamB
{
public:
	ListaTeamB();
	~ListaTeamB();

	list<TeamB*> list_Team_B;

	void Agregar(int x, int y, Bitmap^bmp);
	void Mostrar(Graphics^gr, Bitmap^bmp);

};

ListaTeamB::ListaTeamB()
{
}

ListaTeamB::~ListaTeamB()
{
}

void ListaTeamB::Agregar(int x, int y, Bitmap^bmp){
	list_Team_B.push_back(new TeamB(x, y, bmp));
}
void ListaTeamB::Mostrar(Graphics^gr, Bitmap^bmp){
	for (list<TeamB*>::iterator it = list_Team_B.begin(); it != list_Team_B.end(); ++it){
		if ((*it)->GET_transparente() == true){
			(*it)->Mover(gr, bmp);
			(*it)->DibujarVida(gr);
		}
	}

}