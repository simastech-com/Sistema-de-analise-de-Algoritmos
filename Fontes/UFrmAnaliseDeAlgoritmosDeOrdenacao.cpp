//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#pragma hdrstop

#include "UFrmAnaliseDeAlgoritmosDeOrdenacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmAnaliseDeAlgoritmosDeOrdenacao *FrmAnaliseDeAlgoritmosDeOrdenacao;
//---------------------------------------------------------------------------
__fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::TFrmAnaliseDeAlgoritmosDeOrdenacao(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::EvFecharAnaliseDeAlgoritmosDeOrdenacaoOnClose(TObject *Sender,
          TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::EvSelecionarTudoOnClick(TObject *Sender)
{
	if (chxSelecionarTudo->Checked)
	{
		chxInsercao  -> Checked = true;
		chxBolha     -> Checked = true;
		chxSelecao   -> Checked = true;
		chxQuickSort -> Checked = true;
		chxMergeSort -> Checked = true;
	}
	else
	{
		chxInsercao  -> Checked = false;
		chxBolha     -> Checked = false;
		chxSelecao   -> Checked = false;
		chxQuickSort -> Checked = false;
		chxMergeSort -> Checked = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::EvGerarVetorOnClick(TObject *Sender)
{
	int vContador;
	if (edtTamanhoDoVetor->Text == "")
	{
		ShowMessage("Preencha o tamanho do vetor!");
	}
	else if (edtFaixaDeNumeros->Text == "")
	{
		ShowMessage("Preencha a faixa de n�meros!");
	}
	else
	{
		vTamanho = edtTamanhoDoVetor->Text.ToInt();
		vFaixa   = edtFaixaDeNumeros->Text.ToInt();
		vVetor   = new (strVetor[vTamanho]);
		for (vContador = 0; vContador < vTamanho; vContador++)
		{
			vVetor[vContador].numero = random(vFaixa);
			vVetor[vContador].cor    = random(65535);
		}
		FncPlotarVetorNoGrafico();
		lvwRelatorioDeOrdenacao -> Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncPausa()
{
	Sleep(vTempoParaPausa);
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::EvResetarGrafico(TObject *Sender)
{
	FncPlotarVetorNoGrafico();
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::EvOrdenarVetorOnClick(TObject *Sender)
{
	if (edtTempo->Text == "")
	{
		ShowMessage("Preencha o tempo de atualiza��o da tela!");
	}
	else if (chrGraficoDeOrdenacao->BottomAxis->Maximum > 0)
	{
		lvwRelatorioDeOrdenacao->Clear();
		vTempoParaPausa = edtTempo->Text.ToInt();
		edtFaixaDeNumeros     -> Enabled = false;
		edtTamanhoDoVetor     -> Enabled = false;
		edtTempo              -> Enabled = false;
		btnGerarVetor         -> Enabled = false;
		btnOrdenar            -> Enabled = false;
		btnResetar            -> Enabled = false;
		chxBolha              -> Enabled = false;
		chxInsercao           -> Enabled = false;
		chxMergeSort          -> Enabled = false;
		chxPassagemAutomatica -> Enabled = false;
		chxQuickSort          -> Enabled = false;
		chxSelecao            -> Enabled = false;
		chxSelecionarTudo     -> Enabled = false;
		if (chxInsercao -> Checked)
		{
			if (!chxPassagemAutomatica->Checked)
			{
				if (MessageBox(NULL, L"Deseja iniciar a ordena��o por inser��o?", L"An�lise de Algoritmos de ordena��o", MB_YESNO + MB_ICONQUESTION + MB_DEFBUTTON1) == IDYES)
				{
					Caption = "Ordenando por inser��o...";
					FncOrdenarPorInsercao();
					Caption = "Ordenado por inser��o";
				}
			}
			else
			{
				Caption = "Ordenando por inser��o...";
				FncOrdenarPorInsercao();
				Caption = "Ordenado por inser��o";
            }
		}
		if (chxBolha -> Checked)
		{
            if (!chxPassagemAutomatica->Checked)
			{
				if (MessageBox(NULL, L"Deseja iniciar a ordena��o por bolha?", L"An�lise de Algoritmos de ordena��o", MB_YESNO + MB_ICONQUESTION + MB_DEFBUTTON1) == IDYES)
				{
					Caption = "Ordenando por bolha...";
					FncOrdenarPorBolha();
					Caption = "Ordenado por bolha";
				}
			}
			else
			{
				Caption = "Ordenando por bolha...";
				FncOrdenarPorBolha();
				Caption = "Ordenado por bolha";
            }
		}
		if (chxSelecao -> Checked)
		{
			if (!chxPassagemAutomatica->Checked)
			{
				if (MessageBox(NULL, L"Deseja iniciar a ordena��o por sele��o?", L"An�lise de Algoritmos de ordena��o", MB_YESNO + MB_ICONQUESTION + MB_DEFBUTTON1) == IDYES)
				{
					Caption = "Ordenando por sele��o...";
					FncOrdenarPorSelecao();
					Caption = "Ordenado por sele��o";
				}
			}
			else
			{
				Caption = "Ordenando por sele��o...";
				FncOrdenarPorSelecao();
				Caption = "Ordenado por sele��o";
            }
		}
		if (chxQuickSort -> Checked)
		{
			if (!chxPassagemAutomatica->Checked)
			{
				if (MessageBox(NULL, L"Deseja iniciar a ordena��o por QuickSort?", L"An�lise de Algoritmos de ordena��o", MB_YESNO + MB_ICONQUESTION + MB_DEFBUTTON1) == IDYES)
				{
					Caption = "Ordenando por QuickSort...";
					FncOrdenarPorQuickSort();
					Caption = "Ordenado por QuickSort";
				}
			}
			else
			{
				Caption = "Ordenando por QuickSort...";
				FncOrdenarPorQuickSort();
				Caption = "Ordenado por QuickSort";
            }
		}
		if (chxMergeSort -> Checked)
		{
            if (!chxPassagemAutomatica->Checked)
			{

				if (MessageBox(NULL, L"Deseja iniciar a ordena��o por MergeSort?", L"An�lise de Algoritmos de ordena��o", MB_YESNO + MB_ICONQUESTION + MB_DEFBUTTON1) == IDYES)
				{
					Caption = "Ordenando por MergeSort...";
					FncOrdenarPorMergeSort();
					Caption = "Ordenado por MergeSort";
				}
			}
			else
			{
				Caption = "Ordenando por MergeSort...";
				FncOrdenarPorMergeSort();
				Caption = "Ordenado por MergeSort";
            }
		}
		Caption = "An�lise de algoritmos de ordena��o";
		edtFaixaDeNumeros     -> Enabled = true;
		edtTamanhoDoVetor     -> Enabled = true;
		edtTempo              -> Enabled = true;
		btnGerarVetor         -> Enabled = true;
		btnOrdenar            -> Enabled = true;
		btnResetar            -> Enabled = true;
		chxBolha              -> Enabled = true;
		chxInsercao           -> Enabled = true;
		chxMergeSort          -> Enabled = true;
		chxPassagemAutomatica -> Enabled = true;
		chxQuickSort          -> Enabled = true;
		chxSelecao            -> Enabled = true;
		chxSelecionarTudo     -> Enabled = true;
	}
	else
	{
		ShowMessage("Gere o vetor primeiro!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncCopiarVetor(strVetor *pVetorOriginal, strVetor *pVetorCopia)
{
	double vNumero;
	int    vCor;
	int    vContadorElementos;

	for (vContadorElementos = 0; vContadorElementos < vTamanho; vContadorElementos++)
	{
		vNumero                                = pVetorOriginal[vContadorElementos].numero;
		vCor                                   = pVetorOriginal[vContadorElementos].cor;
		pVetorCopia[vContadorElementos].numero = vNumero;
		pVetorCopia[vContadorElementos].cor    = vCor;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncPlotarVetorNoGrafico()
{
	int    vContador;
	int    vCor;
	double vNumero;
	Series1               -> Clear();
	chrGraficoDeOrdenacao -> LeftAxis   -> Maximum = vFaixa;
	chrGraficoDeOrdenacao -> BottomAxis -> Maximum = vTamanho;
	for (vContador = 0; vContador < vTamanho; vContador++)
	{
		vNumero =  vVetor[vContador].numero;
		vCor    =  vVetor[vContador].cor;
		Series1 -> AddXY(vContador, vNumero, "", vCor);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorSelecao()
{
	int       vContadorElementos;
	int       vContadorComparacoes;
	int       vQuantidadeDeComparacoes = 0;
	int       vQuantidadeDeTrocas = 0;
	int       vPosicaoMenor;
	strVetor  *vVetorSelecao;
	double    vAuxiliarNumero;
	int       vAuxiliarCor;
	clock_t   vInicio;
	clock_t   vFim;
	clock_t   vTempoMiliSegundos;
	TListItem *vItem;
	String    vTempoFormatado;

	EvResetarGrafico(NULL);

	vVetorSelecao = new (strVetor[vTamanho]);

	FncCopiarVetor(vVetor, vVetorSelecao);

	vInicio      = clock();

	for (vContadorElementos = 0; vContadorElementos < vTamanho; vContadorElementos++)
	{
		vPosicaoMenor = vContadorElementos;
		for (vContadorComparacoes = vContadorElementos + 1; vContadorComparacoes < vTamanho; vContadorComparacoes++)
		{
			vQuantidadeDeComparacoes++;
			if (vVetorSelecao[vContadorComparacoes].numero < vVetorSelecao[vPosicaoMenor].numero)
			{
				vPosicaoMenor = vContadorComparacoes;
			}
		}
		if (vPosicaoMenor != vContadorElementos)
		{
			vAuxiliarNumero                          = vVetorSelecao[vPosicaoMenor].numero;
			vVetorSelecao[vPosicaoMenor].numero      = vVetorSelecao[vContadorElementos].numero;
			vVetorSelecao[vContadorElementos].numero = vAuxiliarNumero;

			vAuxiliarCor                             = vVetorSelecao[vPosicaoMenor].cor;
			vVetorSelecao[vPosicaoMenor].cor         = vVetorSelecao[vContadorElementos].cor;
			vVetorSelecao[vContadorElementos].cor    = vAuxiliarCor;

			Series1->ValueColor[vPosicaoMenor]       = TColor(vVetorSelecao[vPosicaoMenor].cor);
			Series1->ValueColor[vContadorElementos]  = TColor(vVetorSelecao[vContadorElementos].cor);

			Series1->YValue[vPosicaoMenor]           = vVetorSelecao[vPosicaoMenor].numero;
			Series1->YValue[vContadorElementos]      = vVetorSelecao[vContadorElementos].numero;

			vQuantidadeDeTrocas++;

			Update();
			FncPausa();
		}
	}
	vFim = clock();
	vTempoMiliSegundos =  (vFim - vInicio);
	vItem              =  lvwRelatorioDeOrdenacao->Items->Add();
	vItem->Caption     =  "Algoritmo de ordena��o por Sele��o";
	vItem->SubItems    -> Add("n�");
	vItem->SubItems    -> Add(vQuantidadeDeTrocas);
	vItem->SubItems    -> Add(vQuantidadeDeComparacoes);
	vItem->SubItems    -> Add(vTempoMiliSegundos);
	vTempoFormatado    =  String((int(vTempoMiliSegundos/3600000))) + "h" + String((int(vTempoMiliSegundos/60000))%60) + "min" + String((int(vTempoMiliSegundos/1000))%60) + "s," + String(vTempoMiliSegundos%1000);

	vItem->SubItems->Add(vTempoFormatado);

	delete vVetorSelecao;
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorInsercao()
{
	int       vContadorElementos;
	int       vContadorComparacoes;
	int       vQuantidadeDeComparacoes = 0;
	int       vQuantidadeDeTrocas = 0;
	strVetor  *vVetorInsercao;
	strVetor  vAuxiliar;
	clock_t   vInicio;
	clock_t   vFim;
	clock_t   vTempoMiliSegundos;
	TListItem *vItem;
	String    vTempoFormatado;

    EvResetarGrafico(NULL);

	vVetorInsercao = new (strVetor[vTamanho]);

	FncCopiarVetor(vVetor, vVetorInsercao);

	vInicio = clock();

	for (vContadorElementos = 1; vContadorElementos < vTamanho; vContadorElementos++)
	{
		vContadorComparacoes = vContadorElementos - 1;
		vAuxiliar.numero     = vVetorInsercao[vContadorElementos].numero;
		vAuxiliar.cor        = vVetorInsercao[vContadorElementos].cor;

		while((vAuxiliar.numero < vVetorInsercao[vContadorComparacoes].numero) && (vContadorComparacoes >= 0))
		{
			vQuantidadeDeComparacoes++;
			vVetorInsercao[vContadorComparacoes + 1].numero = vVetorInsercao[vContadorComparacoes].numero;
			vVetorInsercao[vContadorComparacoes + 1].cor    = vVetorInsercao[vContadorComparacoes].cor;
			Series1->ValueColor[vContadorComparacoes + 1]   = TColor(vVetorInsercao[vContadorComparacoes + 1].cor);
			Series1->YValue[vContadorComparacoes + 1]       = vVetorInsercao[vContadorComparacoes + 1].numero;
			Update();
			FncPausa();
			vContadorComparacoes--;
		}
		vQuantidadeDeComparacoes = vQuantidadeDeComparacoes + 2;
		if (vAuxiliar.numero < vVetorInsercao[vContadorComparacoes + 1].numero)
		{
			vVetorInsercao[vContadorComparacoes + 1].numero = vAuxiliar.numero;
			vVetorInsercao[vContadorComparacoes + 1].cor    = vAuxiliar.cor;
			Series1->ValueColor[vContadorComparacoes + 1]   = TColor(vAuxiliar.cor);
			Series1->YValue[vContadorComparacoes + 1]       = vAuxiliar.numero;
			Update();
			FncPausa();
			vQuantidadeDeTrocas++;
		}
	}
	vFim = clock();
	vTempoMiliSegundos =  (vFim - vInicio);
	vItem              =  lvwRelatorioDeOrdenacao->Items->Add();
	vItem->Caption     =  "Algoritmo de ordena��o por Inser��o";
	vItem->SubItems    -> Add("n�");
	vItem->SubItems    -> Add(vQuantidadeDeTrocas);
	vItem->SubItems    -> Add(vQuantidadeDeComparacoes);
	vItem->SubItems    -> Add(vTempoMiliSegundos);
	vTempoFormatado    =  String((int(vTempoMiliSegundos/3600000))) + "h" + String((int(vTempoMiliSegundos/60000))%60) + "min" + String((int(vTempoMiliSegundos/1000))%60) + "s," + String(vTempoMiliSegundos%1000);

	vItem->SubItems->Add(vTempoFormatado);

	delete vVetorInsercao;
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorBolha()
{
	bool      vTrocou = TRUE;
	int       vContadorElementos;
	int       vContadorComparacoes;
	int       vQuantidadeDeComparacoes = 0;
	int       vQuantidadeDeTrocas = 0;
	strVetor  *vVetorBolha;
	strVetor  vAuxiliar;
	clock_t   vInicio;
	clock_t   vFim;
	clock_t   vTempoMiliSegundos;
	TListItem *vItem;
	String    vTempoFormatado;

    EvResetarGrafico(NULL);

	vVetorBolha = new (strVetor[vTamanho]);

	FncCopiarVetor(vVetor, vVetorBolha);

	vInicio     = clock();

	for (vContadorElementos = 0; vContadorElementos < vTamanho - 1 && vTrocou == TRUE; vContadorElementos++)
	{
		vTrocou = FALSE;
		for (vContadorComparacoes = 0; vContadorComparacoes < vTamanho - vContadorElementos - 1; vContadorComparacoes++)
		{
			vQuantidadeDeComparacoes++;
			if (vVetorBolha[vContadorComparacoes].numero > vVetorBolha[vContadorComparacoes + 1].numero)
			{
				vTrocou                                       = TRUE;

				vAuxiliar.numero                              = vVetorBolha[vContadorComparacoes].numero;
				vAuxiliar.cor                                 = vVetorBolha[vContadorComparacoes].cor;

				vVetorBolha[vContadorComparacoes].numero      = vVetorBolha[vContadorComparacoes + 1].numero;
				vVetorBolha[vContadorComparacoes].cor         = vVetorBolha[vContadorComparacoes + 1].cor;
				Series1->ValueColor[vContadorComparacoes]     = TColor(vVetorBolha[vContadorComparacoes].cor);
				Series1->YValue[vContadorComparacoes]         = vVetorBolha[vContadorComparacoes].numero;

				vVetorBolha[vContadorComparacoes + 1].numero  = vAuxiliar.numero;
				vVetorBolha[vContadorComparacoes + 1].cor     = vAuxiliar.cor;
				Series1->ValueColor[vContadorComparacoes + 1] = TColor(vVetorBolha[vContadorComparacoes + 1].cor);
				Series1->YValue[vContadorComparacoes + 1]     = vVetorBolha[vContadorComparacoes + 1].numero;

				Update();
				FncPausa();
				vQuantidadeDeTrocas++;
			}
		}
	}
	vFim = clock();
	vTempoMiliSegundos =  (vFim - vInicio);
	vItem              =  lvwRelatorioDeOrdenacao->Items->Add();
	vItem->Caption     =  "Algoritmo de ordena��o por Bolha";
	vItem->SubItems    -> Add("n�");
	vItem->SubItems    -> Add(vQuantidadeDeTrocas);
	vItem->SubItems    -> Add(vQuantidadeDeComparacoes);
	vItem->SubItems    -> Add(vTempoMiliSegundos);
	vTempoFormatado    =  String((int(vTempoMiliSegundos/3600000))) + "h" + String((int(vTempoMiliSegundos/60000))%60) + "min" + String((int(vTempoMiliSegundos/1000))%60) + "s," + String(vTempoMiliSegundos%1000);

	vItem->SubItems->Add(vTempoFormatado);

	delete vVetorBolha;
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorQuickSort()
{
	int       vQuantidadeDeComparacoes = 0;
	int       vQuantidadeDeTrocas = 0;
	strVetor  *vVetorQuickSort;
	clock_t   vInicio;
	clock_t   vFim;
	clock_t   vTempoMiliSegundos;
	TListItem *vItem;
	String    vTempoFormatado;

	EvResetarGrafico(NULL);

	vVetorQuickSort    =  new (strVetor[vTamanho]);

	FncCopiarVetor(vVetor, vVetorQuickSort);

	vInicio            =  clock();
	FncOrdenarPorQuickSortRecursivo(vVetorQuickSort, 0, vTamanho - 1,vQuantidadeDeComparacoes, vQuantidadeDeTrocas);
	vFim               =  clock();
	vTempoMiliSegundos =  (vFim - vInicio);
	vTempoFormatado    =  String((int(vTempoMiliSegundos/3600000))) + "h" + String((int(vTempoMiliSegundos/60000))%60) + "min" + String((int(vTempoMiliSegundos/1000))%60) + "s," + String(vTempoMiliSegundos%1000);

	vItem              =  lvwRelatorioDeOrdenacao->Items->Add();
	vItem->Caption     =  "Algoritmo de ordena��o por QuickSort";
	vItem->SubItems    -> Add("n.Log n");

	vItem->SubItems    -> Add(vQuantidadeDeTrocas);
	vItem->SubItems    -> Add(vQuantidadeDeComparacoes);

	vItem->SubItems    -> Add(vTempoMiliSegundos);
	vItem->SubItems    -> Add(vTempoFormatado);

	delete vVetorQuickSort;
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorQuickSortRecursivo(strVetor *pVetor, int pInicio, int pFim, int &pQuantidadeDeComparacoes, int &pQuantidadeDeTrocas)
{
	strVetor vAuxiliar;
	int      vPivo;
	int      vContadorInicio;
	int      vContadorFim;
	int      vMeio;

	vContadorInicio = pInicio;
	vContadorFim    = pFim;

	vMeio           = int((vContadorInicio + vContadorFim) / 2);
	vPivo           = pVetor[vMeio].numero;

	do{
		while (pVetor[vContadorInicio].numero < vPivo)
		{
			pQuantidadeDeComparacoes++;
			vContadorInicio++;
		}
		pQuantidadeDeComparacoes++;
		while (pVetor[vContadorFim].numero    > vPivo)
		{
			pQuantidadeDeComparacoes++;
			vContadorFim--;
		}
		pQuantidadeDeComparacoes++;

		if(vContadorInicio <= vContadorFim)
		{
            if(vContadorInicio <= vContadorFim)
			{
				vAuxiliar.numero                     = pVetor[vContadorInicio].numero;
				vAuxiliar.cor                        = pVetor[vContadorInicio].cor;
				pVetor[vContadorInicio].numero       = pVetor[vContadorFim].numero;
				pVetor[vContadorInicio].cor          = pVetor[vContadorFim].cor;
				pVetor[vContadorFim].numero          = vAuxiliar.numero;
				pVetor[vContadorFim].cor             = vAuxiliar.cor;

				Series1->ValueColor[vContadorInicio] = TColor(pVetor[vContadorInicio].cor);
				Series1->YValue[vContadorInicio]     = pVetor[vContadorInicio].numero;

				Series1->ValueColor[vContadorFim]    = TColor(pVetor[vContadorFim].cor);
				Series1->YValue[vContadorFim]        = pVetor[vContadorFim].numero;

				pQuantidadeDeTrocas++;

				Update();
				FncPausa();
            }
			vContadorInicio ++;
			vContadorFim--;
		}
	}while(vContadorFim > vContadorInicio);
	if(pInicio < vContadorFim)
	{
		FncOrdenarPorQuickSortRecursivo(pVetor, pInicio, vContadorFim, pQuantidadeDeComparacoes, pQuantidadeDeTrocas);
	}
	if(vContadorInicio < pFim)
	{
		FncOrdenarPorQuickSortRecursivo(pVetor, vContadorInicio, pFim, pQuantidadeDeComparacoes, pQuantidadeDeTrocas);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorMergeSort()
{
	int       vQuantidadeDeComparacoes = 0;
	int       vQuantidadeDeTrocas = 0;
	strVetor  *vVetorMergeSort;
	clock_t   vInicio;
	clock_t   vFim;
	clock_t   vTempoMiliSegundos;
	TListItem *vItem;
	String    vTempoFormatado;

	EvResetarGrafico(NULL);

	vVetorMergeSort    =  new (strVetor[vTamanho]);

	FncCopiarVetor(vVetor, vVetorMergeSort);

	vInicio            =  clock();

	FncOrdenarPorMergeSortRecursivo(vVetorMergeSort, 0, vTamanho - 1,vQuantidadeDeComparacoes, vQuantidadeDeTrocas);
	vFim               =  clock();
	vTempoMiliSegundos =  (vFim - vInicio);
	vTempoFormatado    =  String((int(vTempoMiliSegundos/3600000))) + "h" + String((int(vTempoMiliSegundos/60000))%60) + "min" + String((int(vTempoMiliSegundos/1000))%60) + "s," + String(vTempoMiliSegundos%1000);

	vItem              =  lvwRelatorioDeOrdenacao -> Items -> Add();
	vItem->Caption     =  "Algoritmo de ordena��o por MergeSort";
	vItem->SubItems    -> Add("n.Log n");

	vItem->SubItems    -> Add(vQuantidadeDeTrocas);
	vItem->SubItems    -> Add(vQuantidadeDeComparacoes);

	vItem->SubItems    -> Add(vTempoMiliSegundos);
	vItem->SubItems    -> Add(vTempoFormatado);

	delete vVetorMergeSort;
}
//---------------------------------------------------------------------------
void __fastcall TFrmAnaliseDeAlgoritmosDeOrdenacao::FncOrdenarPorMergeSortRecursivo(strVetor *pVetor, int pInicio, int pFim, int &pQuantidadeDeComparacoes, int &pQuantidadeDeTrocas)
{
   int      vMetadeTamanho;
   int      vContadorInicio;
   int      vContadorTemporario;
   int      vContadorFim;
   int      vContadorDeTransferencia;
   strVetor *vVetorAuxiliar;

   if (pInicio != pFim )
   {
		vMetadeTamanho      = (pInicio + pFim)/2;
		FncOrdenarPorMergeSortRecursivo(pVetor, pInicio, vMetadeTamanho, pQuantidadeDeComparacoes, pQuantidadeDeTrocas);
		FncOrdenarPorMergeSortRecursivo(pVetor, vMetadeTamanho + 1, pFim, pQuantidadeDeComparacoes, pQuantidadeDeTrocas);

		vContadorInicio     = pInicio;
		vContadorFim        = vMetadeTamanho + 1;

		vContadorTemporario = 0;
		vVetorAuxiliar      = new strVetor[pFim - pInicio + 1];

		while(vContadorInicio < vMetadeTamanho + 1 || vContadorFim < pFim + 1)
		{
			if (vContadorInicio == vMetadeTamanho + 1)
			{
				vVetorAuxiliar[vContadorTemporario].numero         = pVetor[vContadorFim].numero;
				vVetorAuxiliar[vContadorTemporario].cor            = pVetor[vContadorFim].cor;
				vContadorFim++;
				vContadorTemporario++;
			}
			else
			{
				if (vContadorFim == pFim + 1)
				{
					vVetorAuxiliar[vContadorTemporario].numero     = pVetor[vContadorInicio].numero;
					vVetorAuxiliar[vContadorTemporario].cor        = pVetor[vContadorInicio].cor;
					vContadorInicio++;
					vContadorTemporario++;
				}
				else
				{
					pQuantidadeDeComparacoes++;
					if (pVetor[vContadorInicio].numero <= pVetor[vContadorFim].numero)
					{
						vVetorAuxiliar[vContadorTemporario].numero = pVetor[vContadorInicio].numero;
						vVetorAuxiliar[vContadorTemporario].cor    = pVetor[vContadorInicio].cor;
						vContadorInicio++;
						vContadorTemporario++;
					}
					else
					{
						vVetorAuxiliar[vContadorTemporario].numero = pVetor[vContadorFim].numero;
						vVetorAuxiliar[vContadorTemporario].cor    = pVetor[vContadorFim].cor;
						vContadorFim++;
						vContadorTemporario++;
                        pQuantidadeDeTrocas++;
					}
				}
			}
		}
		for(vContadorDeTransferencia = pInicio; vContadorDeTransferencia <= pFim; vContadorDeTransferencia++)
		{
			if ((pVetor[vContadorDeTransferencia].numero != vVetorAuxiliar[vContadorDeTransferencia - pInicio].numero) && (pVetor[vContadorDeTransferencia].cor != vVetorAuxiliar[vContadorDeTransferencia - pInicio].cor))
			{
				pVetor[vContadorDeTransferencia].numero            = vVetorAuxiliar[vContadorDeTransferencia - pInicio].numero;
				pVetor[vContadorDeTransferencia].cor               = vVetorAuxiliar[vContadorDeTransferencia - pInicio].cor;
				Series1 -> ValueColor[vContadorDeTransferencia]    = TColor(pVetor[vContadorDeTransferencia].cor);
				Series1 -> YValue[vContadorDeTransferencia]        = pVetor[vContadorDeTransferencia].numero;
				FncPausa();
				Update();
			}
		}
		delete vVetorAuxiliar;
   }
}

