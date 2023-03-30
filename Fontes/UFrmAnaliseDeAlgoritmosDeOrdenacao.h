//---------------------------------------------------------------------------

#ifndef UFrmAnaliseDeAlgoritmosDeOrdenacaoH
#define UFrmAnaliseDeAlgoritmosDeOrdenacaoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TFrmAnaliseDeAlgoritmosDeOrdenacao : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *grpVetor;
	TGroupBox *grpOrdenar;
	TLabeledEdit *edtTamanhoDoVetor;
	TLabeledEdit *edtFaixaDeNumeros;
	TButton *btnGerarVetor;
	TButton *btnResetar;
	TCheckBox *chxSelecionarTudo;
	TCheckBox *chxInsercao;
	TCheckBox *chxQuickSort;
	TCheckBox *chxBolha;
	TCheckBox *chxMergeSort;
	TCheckBox *chxSelecao;
	TChart *chrGraficoDeOrdenacao;
	TListView *lvwRelatorioDeOrdenacao;
	TBarSeries *Series1;
	TButton *btnOrdenar;
	TCheckBox *chxPassagemAutomatica;
	TLabeledEdit *edtTempo;
	void __fastcall EvFecharAnaliseDeAlgoritmosDeOrdenacaoOnClose(TObject *Sender, TCloseAction &Action);
	void __fastcall EvSelecionarTudoOnClick(TObject *Sender);
	void __fastcall EvGerarVetorOnClick(TObject *Sender);
	void __fastcall EvResetarGrafico(TObject *Sender);
	void __fastcall EvOrdenarVetorOnClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
	struct strVetor
	{
		double numero;
		int    cor;
	};
    strVetor *vVetor;
	int      vTamanho;
	int      vFaixa;
	int      vTempoParaPausa;

	void __fastcall FncPlotarVetorNoGrafico();
	void __fastcall FncPausa();
	void __fastcall FncOrdenarPorSelecao();
	void __fastcall FncCopiarVetor(strVetor *pVetorOriginal, strVetor *pVetorCopia);
	void __fastcall FncOrdenarPorInsercao();
	void __fastcall FncOrdenarPorBolha();
	void __fastcall FncOrdenarPorQuickSort();
	void __fastcall FncOrdenarPorQuickSortRecursivo(strVetor *pVetor, int pInicio, int pFim, int &pQuantidadeDeComparacoes, int &pQuantidadeDeTrocas);
	void __fastcall FncOrdenarPorMergeSort();
	void __fastcall FncOrdenarPorMergeSortRecursivo(strVetor *pVetor, int pInicio, int pFim, int &pQuantidadeDeComparacoes, int &pQuantidadeDeTrocas);
	__fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmAnaliseDeAlgoritmosDeOrdenacao *FrmAnaliseDeAlgoritmosDeOrdenacao;
//---------------------------------------------------------------------------
#endif
