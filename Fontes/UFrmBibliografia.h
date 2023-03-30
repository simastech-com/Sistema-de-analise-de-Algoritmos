//---------------------------------------------------------------------------

#ifndef UFrmBibliografiaH
#define UFrmBibliografiaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFrmBibliografia : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnFechar;
	TLabel *Label4;
	void __fastcall EvFecharFormularioOnClick(TObject *Sender);
	void __fastcall EvFecharFormularioOnClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
	__fastcall TFrmBibliografia(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmBibliografia *FrmBibliografia;
//---------------------------------------------------------------------------
#endif
