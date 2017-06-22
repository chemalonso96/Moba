#pragma once

#include"Controladora.h"
#include<stdlib.h>
#include<time.h>
#include<vector>

namespace Moba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Controladora * obj_controlador;
		Bitmap^bmp_mapa;
		Bitmap^bmp_teamA;
		Bitmap^bmp_teamB;
		Bitmap^bmp_PA;
		Bitmap^bmp_PB;
		Bitmap^bmp_TorreTA;
		Bitmap^bmp_TorreTB;
		Bitmap^bmp_PersoajeA;
		Bitmap^bmp_PersoajeB;
		int respuesta;
		int valor;
		int *para_YA;
		int *para_YB;
		Direccion d;
		Direccion2 d2;
	public:
		MyForm(void)
		{
			obj_controlador = new Controladora();
			bmp_mapa = gcnew Bitmap("mapa.png");
			bmp_teamA = gcnew Bitmap("teamA.png");
			bmp_teamB = gcnew Bitmap("teamB.png");
			bmp_PA = gcnew Bitmap("PoderA.png");
			bmp_PB = gcnew Bitmap("PoderB.png");
			bmp_TorreTA = gcnew Bitmap("TorreTA.png");
			bmp_TorreTB = gcnew Bitmap("TorreTB.png");
			bmp_PersoajeA = gcnew Bitmap("personajeA.png");
			bmp_PersoajeB = gcnew Bitmap("personajeB.png");
			respuesta = NULL;
			valor = NULL;
			para_YA = new int[8];
			para_YB = new int[8];
			d = Ninguno;
			d2 = n;
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			delete obj_controlador;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1354, 733);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 Graphics^gr = this->CreateGraphics();
				 BufferedGraphicsContext^bgc = BufferedGraphicsManager::Current;
				 BufferedGraphics^bg = bgc->Allocate(gr, this->ClientRectangle);
				 obj_controlador->Mostrar_Todos(bg->Graphics, bmp_mapa, bmp_teamA, bmp_teamB, bmp_TorreTA, 
												bmp_TorreTB, bmp_PersoajeA, bmp_PersoajeB, d, d2);
				 obj_controlador->Verificar_Colision_TeamA_Vs_TeamB(bg->Graphics, bmp_PA);
				 obj_controlador->Verificar_Colision_TeamB_Vs_TeamA(bg->Graphics, bmp_PB);
				 obj_controlador->Vefiricar_Colision_TeamA_Vs_TorreB(bg->Graphics, bmp_PA);
				 obj_controlador->Vefiricar_Colision_TeamB_Vs_TorreA(bg->Graphics, bmp_PB);
				 obj_controlador->Perseguir_A_hacia_B();
				 obj_controlador->Perseguir_B_hacia_A();
				 
				 int contador = 0;
				 bg->Render(gr);
				 delete bg;
				 delete bgc;
				 delete gr;
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 obj_controlador->obj_vec_ma->Llamar_Archivo();

				 int R2;
				 int R3;
				 int respuestaB;
				 for (int i = 0; i < 15; i++){
					 respuesta = 162  + rand() % 400;
					 respuestaB = 162 + rand() % 400;
					 para_YA[i] = respuesta;
					 para_YB[i] = respuestaB;
				 }		
				 //TEAM A 250/500
				 for (int i = 0; i < 8; i++){
					 R2 = 250 + rand() % 300;
					 obj_controlador->obj_listTeamA->Agregar(R2, para_YA[i], bmp_teamA);
				 }
				 //TEAM B
				 for (int i = 0; i < 8; i++){
					 R3 = 850 + (rand() % 300);
					 obj_controlador->obj_listTeamB->Agregar(R3, para_YB[i], bmp_teamB);
				 }
				 
				 obj_controlador->obj_personajeA = new PersonajeA(100, 400, bmp_PersoajeA);
				 obj_controlador->obj_personajeB = new PersonajeB(1000, 400, bmp_PersoajeB);
				 //torre team A
				 obj_controlador->obj_ListTTA->Agregar(197,100,100,bmp_TorreTA);
				 obj_controlador->obj_ListTTA->Agregar(197, 433, 100, bmp_TorreTA);
				 //torre team B
				 obj_controlador->obj_ListTTB->Agregar(1050 , 100, 100, bmp_TorreTB);
				 obj_controlador->obj_ListTTB->Agregar(1050, 433, 100, bmp_TorreTB);

				 obj_controlador->obj_mapa = new Mapa();

	}
	private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 this->Text = "X" + e->X.ToString() + "Y" + e->Y.ToString();
	}
private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 d = Ninguno;
			 d2 = n;
}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::A){
				 d = Izquiera;
			 }
			 if (e->KeyCode == Keys::D){
				 d = Derecha;
			 }
			 if (e->KeyCode == Keys::S){
				 d = Abajo;
			 }
			 if (e->KeyCode == Keys::W){
				 d = Arriba;
			 }
			 if (e->KeyCode == Keys::Left){
				 d2 = a;
			 }
			 if (e->KeyCode == Keys::Right){
				 d2 = Direccion2::d;
			 }
			 if (e->KeyCode == Keys::Down){
				 d2 = s;
			 }
			 if (e->KeyCode == Keys::Up){
				 d2 = w;
			 }

}
};
}
