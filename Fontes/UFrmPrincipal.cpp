//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFrmPrincipal.h"
#include "UFrmAnaliseDeAlgoritmosDeOrdenacao.h"
#include "UFrmAnaliseDeAlgoritmosDeBusca.h"
#include "UFrmAutor.h"
#include "UFrmBibliografia.h"
//#include "UFrmEficienciaDeAlgoritmosDeOrdenacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmPrincipal *FrmPrincipal;
//---------------------------------------------------------------------------
__fastcall TFrmPrincipal::TFrmPrincipal(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmPrincipal::EvFecharSistemaOnClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrmPrincipal::EvAtivarAlgoritmosDeOrdenacaoOnClick(TObject *Sender)
{
	new TFrmAnaliseDeAlgoritmosDeOrdenacao(this);
}
//---------------------------------------------------------------------------
void __fastcall TFrmPrincipal::EvAtivarAnaliseDeAlgoritmosDeOrdenacao(TObject *Sender)
{
	new TFrmAnaliseDeAlgoritmosDeBusca(this);
}
//---------------------------------------------------------------------------
void __fastcall TFrmPrincipal::EvAtivarAutorOnClick(TObject *Sender)
{
	new TFrmAutor(this);
}
//---------------------------------------------------------------------------

void __fastcall TFrmPrincipal::EvAtivarBibliografiaOnClick(TObject *Sender)
{
	new TFrmBibliografia(this);
}
//---------------------------------------------------------------------------

