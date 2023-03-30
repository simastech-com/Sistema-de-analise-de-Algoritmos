//---------------------------------------------------------------------------

#ifndef UFrmPrincipalH
#define UFrmPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TFrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *mnmPrincipal;
	TMenuItem *Eficincia1;
	TMenuItem *Algoritmosdeordenao1;
	TMenuItem *N1;
	TMenuItem *Sair1;
	TImage *imgPrincipal;
	TMenuItem *Crditos1;
	TMenuItem *Imagens1;
	TMenuItem *Desenvolvedor1;
	TMenuItem *Algoritmosdebusca1;
	void __fastcall EvFecharSistemaOnClick(TObject *Sender);
	void __fastcall EvAtivarAlgoritmosDeOrdenacaoOnClick(TObject *Sender);
	void __fastcall EvAtivarAnaliseDeAlgoritmosDeOrdenacao(TObject *Sender);
	void __fastcall EvAtivarAutorOnClick(TObject *Sender);
	void __fastcall EvAtivarBibliografiaOnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmPrincipal *FrmPrincipal;
//---------------------------------------------------------------------------
#endif
