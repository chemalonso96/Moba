#pragma once

#include"Vector_Matriz_Mapa.h"
#include"ListaTeamA.h"
#include"ListaTeamB.h"
#include"PoderTeamA.h"
#include"PoderTeamB.h"
#include"Mapa.h"
#include"ListTorreTeamA.h"
#include"ListTorreTeamB.h"
#include"PersonajeA.h"
#include"PersonajeB.h"

class Controladora
{
public:
	PersonajeA* obj_personajeA;
	PersonajeB* obj_personajeB;
	Vector_Matriz_Mapa* obj_vec_ma;
	ListaTeamA* obj_listTeamA;
	TeamA* obj_TeamA;
	ListaTeamB* obj_listTeamB;
	TeamB* obj_TeamB;
	Mapa* obj_mapa;
	PoderTeamA* obj_PTA;
	PoderTeamB* obj_PTB;
	ListTorreTeamA* obj_ListTTA;
	ListTorreTeamB* obj_ListTTB;
public:
	Controladora();
	~Controladora();

	void Mostrar_Todos(Graphics^gr, Bitmap^bmp_mapa, Bitmap^bmp_temaA, Bitmap^bmp_temaB, 
		Bitmap^bmp_TTA, Bitmap^bmp_TTB, Bitmap^bmp_personajeA, Bitmap^bmp_personajeB, Direccion d,Direccion2 d2);
	void Perseguir_A_hacia_B();
	void Perseguir_B_hacia_A();
	//todas las colisiones posibles
	bool Colision_TeamA_Vs_TeamB(TeamA* obj_TA, TeamB* obj_TB);
	void Verificar_Colision_TeamA_Vs_TeamB(Graphics^gr, Bitmap^bmp);
	bool Colision_TeamB_Vs_TeamA(TeamB* obj_TB, TeamA* obj_TA);
	void Verificar_Colision_TeamB_Vs_TeamA(Graphics^gr, Bitmap^bmp);
	bool Colision_TeamA_Vs_TorreB(TeamA* obj_TA,TorreTeamB* objTTB);
	void Vefiricar_Colision_TeamA_Vs_TorreB(Graphics^gr, Bitmap^bmp);
	bool Colision_TeamB_Vs_TorreA(TeamB* obj_TB, TorreTeamA* objTTA);
	void Vefiricar_Colision_TeamB_Vs_TorreA(Graphics^gr, Bitmap^bmp);
};

Controladora::Controladora()
{
	obj_vec_ma = new Vector_Matriz_Mapa();
	obj_listTeamA = new ListaTeamA();
	obj_listTeamB = new ListaTeamB();
	obj_mapa = new Mapa();
	obj_TeamA = new TeamA();
	obj_TeamB = new TeamB();
	obj_PTA = new PoderTeamA();
	obj_PTB = new PoderTeamB();
	obj_ListTTA = new ListTorreTeamA();
	obj_ListTTB = new ListTorreTeamB();
	obj_personajeA = new PersonajeA();
	obj_personajeB = new PersonajeB();
}

Controladora::~Controladora()
{
}

void Controladora::Mostrar_Todos(Graphics^gr, Bitmap^bmp_mapa, Bitmap^bmp_temaA, Bitmap^bmp_temaB,
	Bitmap^bmp_TTA, Bitmap^bmp_TTB, Bitmap^bmp_personajeA, Bitmap^bmp_personajeB, Direccion d, Direccion2 d2){
	obj_mapa->Dibujar(gr, bmp_mapa);
	obj_vec_ma->Mostrar(gr);
	obj_listTeamA->Mostrar(gr, bmp_temaA);
	obj_listTeamB->Mostrar(gr, bmp_temaB);
	obj_ListTTA->Mostrar(gr, bmp_TTA); 
	obj_ListTTB->Mostrar(gr, bmp_TTB);
	obj_personajeA->Mover(gr, bmp_personajeA, d);
	obj_personajeB->Mover(gr, bmp_personajeB, d2);
}

void Controladora::Perseguir_A_hacia_B(){
	//mitad para abajo
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		if ((*itA)->GET_Y() > 165 && (*itA)->GET_Y() < 343) {
			(*itA)->SET_movimiento(Direccion::Arriba);
		}
	}
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		if ((*itA)->GET_Y() > 69 && (*itA)->GET_Y() < 155) {
			(*itA)->SET_movimiento(Direccion::Abajo);
		}
	}
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		if ((*itA)->GET_Y() >= 155 && (*itA)->GET_Y() <= 165){
			(*itA)->SET_movimiento(Direccion::Derecha);
		}
	}
	//mitad para arriba
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		if ((*itA)->GET_Y() >= 343 && (*itA)->GET_Y() < 490) {
			(*itA)->SET_movimiento(Direccion::Abajo);
		}
	}
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		if ((*itA)->GET_Y() > 500 && (*itA)->GET_Y() < 610) {
			(*itA)->SET_movimiento(Direccion::Arriba);
		}
	}
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		if ((*itA)->GET_Y() >= 490 && (*itA)->GET_Y() <= 500){
			(*itA)->SET_movimiento(Direccion::Derecha);
		}
	}
}
void Controladora::Perseguir_B_hacia_A(){
	//mitad para abajo
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		if ((*itB)->GET_Y() > 165 && (*itB)->GET_Y() < 343) {
			(*itB)->SET_movimiento(Direccion::Arriba);
		}
	}
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		if ((*itB)->GET_Y() > 69 && (*itB)->GET_Y() < 155) {
			(*itB)->SET_movimiento(Direccion::Abajo);
		}
	}
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		if ((*itB)->GET_Y() >= 155 && (*itB)->GET_Y() <= 165){
			(*itB)->SET_movimiento(Direccion::Izquiera);
		}
	}
	//mitad para arriba
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		if ((*itB)->GET_Y() >= 343 && (*itB)->GET_Y() < 490) {
			(*itB)->SET_movimiento(Direccion::Abajo);
		}
	}
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		if ((*itB)->GET_Y() > 500 && (*itB)->GET_Y() < 610) {
			(*itB)->SET_movimiento(Direccion::Arriba);
		}
	}
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		if ((*itB)->GET_Y() >= 490 && (*itB)->GET_Y() <= 500){
			(*itB)->SET_movimiento(Direccion::Izquiera);
		}
	}
}

bool Controladora::Colision_TeamA_Vs_TeamB(TeamA* obj_TA, TeamB* obj_TB){
	if (obj_TA->rectangulo().IntersectsWith(obj_TB->rectangulo()) ){
		return true;
	}
	else{
		return false;
	}
}
void Controladora::Verificar_Colision_TeamA_Vs_TeamB(Graphics^gr, Bitmap^bmp){
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
			if (Colision_TeamA_Vs_TeamB((*itA), (*itB)) == true){
				(*itA)->SET_X((*itA)->GET_X() - 4);
				(*itA)->AgregarPoder((*itA)->GET_X()+5, (*itA)->GET_Y(), bmp);
				(*itA)->MostrarPoder(gr, bmp);
				(*itA)->list_PoderA.pop_front();//elimina el primer poder puesto para uqe ya no se vuelva a mostrar
				(*itB)->SET_Vida((*itB)->GET_Vida() - 0.5);
				if ((*itB)->GET_Vida() == 0){
					int m;
					m = 185 + rand() % 400;
					(*itB)->SET_X(1050);
					(*itB)->SET_Y(m);
					(*itB)->SET_Vida(30);//185-507
				}
			}
		}
	}
}

bool Controladora::Colision_TeamB_Vs_TeamA(TeamB* obj_TB, TeamA* obj_TA){
	if (obj_TB->rectangulo().IntersectsWith(obj_TA->rectangulo())){
		return true;
	}
	else{
		return false;
	}
}
void Controladora::Verificar_Colision_TeamB_Vs_TeamA(Graphics^gr, Bitmap^bmp){
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
			if (Colision_TeamB_Vs_TeamA((*itB), (*itA)) == true){
				(*itB)->SET_X((*itB)->GET_X() + 4);
				(*itB)->AgregarPoder((*itB)->GET_X()-5, (*itB)->GET_Y(), bmp);
				(*itB)->MostrarPoder(gr, bmp);
				(*itB)->list_PoderB.pop_front();//elimina el primer poder puesto para uqe ya no se vuelva a mostrar
				(*itA)->SET_Vida((*itA)->GET_Vida() - 1);
				if ((*itA)->GET_Vida() == 0){
					int m;
					m = 185 + rand() % 400;
					(*itA)->SET_X(250);
					(*itA)->SET_Y(m);
					(*itA)->SET_Vida(30);
				}
			}
		}
	}
}

bool Controladora::Colision_TeamA_Vs_TorreB(TeamA* obj_TA, TorreTeamB* objTTB){
	if (obj_TA->rectangulo().IntersectsWith(objTTB->rectangulo())){
		return true;
	}
	else{
		return false;
	}
}
void Controladora::Vefiricar_Colision_TeamA_Vs_TorreB(Graphics^gr, Bitmap^bmp){
	for (list<TeamA*>::iterator itA = obj_listTeamA->list_Team_A.begin(); itA != obj_listTeamA->list_Team_A.end(); ++itA){
		for (list<TorreTeamB*>::iterator itB = obj_ListTTB->list_TorreB.begin(); itB != obj_ListTTB->list_TorreB.end(); ++itB){
			if (Colision_TeamA_Vs_TorreB((*itA), (*itB)) == true){
				(*itA)->SET_X((*itA)->GET_X() - 10);
				(*itA)->AgregarPoder((*itA)->GET_X()+5, (*itA)->GET_Y(), bmp);
				(*itA)->MostrarPoder(gr, bmp);
				(*itA)->list_PoderA.pop_front();//elimina el primer poder puesto para uqe ya no se vuelva a mostrar
				(*itB)->SET_Vida((*itB)->GET_Vida() - 0.2);
			}
			if ((*itB)->GET_Vida() == 0){
				(*itB)->SET_transparente(false);
				(*itB)->SET_Alto(0);
				(*itB)->SET_Ancho(0);

				if ((*itA)->GET_Y() < 277 && (*itA)->GET_X() == 1020) {
					(*itA)->SET_Dy(5);
					(*itA)->SET_Dx(0);
					(*itA)->SET_movimiento(Abajo);
				}
				else if ((*itA)->GET_Y() >342 && (*itA)->GET_X() == 1020){
					(*itA)->SET_movimiento(Arriba);
				}
			}
		}
	}
}
//277-342

bool Controladora::Colision_TeamB_Vs_TorreA(TeamB* obj_TB, TorreTeamA* objTTA){
	if (obj_TB->rectangulo().IntersectsWith(objTTA->rectangulo())){
		return true;
	}
	else{
		return false;
	}
}
void Controladora::Vefiricar_Colision_TeamB_Vs_TorreA(Graphics^gr, Bitmap^bmp){
	for (list<TeamB*>::iterator itB = obj_listTeamB->list_Team_B.begin(); itB != obj_listTeamB->list_Team_B.end(); ++itB){
		for (list<TorreTeamA*>::iterator itA = obj_ListTTA->list_TorreA.begin(); itA != obj_ListTTA->list_TorreA.end(); ++itA){
			if (Colision_TeamB_Vs_TorreA((*itB), (*itA)) == true){
				(*itB)->SET_X((*itB)->GET_X() + 10);
				(*itB)->AgregarPoder((*itB)->GET_X()-5, (*itB)->GET_Y(), bmp);
				(*itB)->MostrarPoder(gr, bmp);
				(*itB)->list_PoderB.pop_front();
				(*itA)->SET_Vida((*itA)->GET_Vida() - 0.2);
				if ((*itA)->GET_Vida() == 0){
					(*itA)->SET_transparente(false);
				}
			}
		}
	}
}