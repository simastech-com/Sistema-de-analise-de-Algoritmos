//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFrmBibliografia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmBibliografia *FrmBibliografia;
//---------------------------------------------------------------------------
__fastcall TFrmBibliografia::TFrmBibliografia(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmBibliografia::EvFecharFormularioOnClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrmBibliografia::EvFecharFormularioOnClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------

