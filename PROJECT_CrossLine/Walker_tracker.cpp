/****************
LAED1 - Projeto - Parte III

Aluna: Samyris Alves Rodrigues (20203008799)
	   Vitor Hugo Mota Soares (20213010530)

Data: 06/12/2022
****************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <sys/time.h>
#define MAX 10

using namespace std;

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  int Chave;
  int tipo_Segmento;
  int NumElementos;
  int PontoMedio;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;

} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================== */
void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}
int compara(TipoLista Lista,int Veet[] ,int x)
{
  TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  int  confere=0;
  while (Aux != NULL)
    {
        int vamo = 0;
        while((Aux -> Item.tipo_Segmento) != Veet[vamo] && vamo < x)
           {

               vamo++;
               Aux = Aux -> Prox;
               if(Aux == NULL)return 0;
           }


        for(int contador = 0; contador < x; contador++)
        {
           if((Aux -> Item.tipo_Segmento) == Veet[contador])
           {
               confere++;
               Aux = Aux -> Prox;
               if(confere == x)return 1;
           }else{
                confere = 0;
                break;
           }
        }
    }

    return 0;

}

/* ========================================================================== */

int main(int argc, char *argv[])
{
	FILE *fp;
	int L;
	char arq[100];
	printf("Digite o nome do arquivo: ");
	scanf("%s", arq);
	fp = fopen(arq, "r"); // Abre arquivo texto para leitura
	if (!fp)
	{
		printf("Erro na abertura do arquivo.\n");
		return 0;
	}
fscanf(fp, "%d", &L);
for (int i=0;i<L;i++){
	int N;
	// Salva N - N�mero de elementos do vetor
	// Salva vetor que tem tamnho igual a N
	fscanf(fp, "%d", &N); // leitura a partir do texto, l� o conte�do at� encontrar um espa�o
	// int *numElemen = &N;
	// cout << "num de itens � " << *numElemen;

	int vetor[N]; // vetor[N] recebido
	int num = 0;
	int c;
	while (num<N)
	{ // Enquanto n�o chegar ao final do arquivo
		fscanf(fp, "%d", &c);
		vetor[num] = c;
		// printf("vetor[%d] = %d\n", num, c);
		num++;
	}

	// Salvar os valores do vetor para ordenar em vetor ordenado para saber tipo de segmento depois
	vector<int> vetorOrdenado(N);
	for (int i = 0; i < N; i++)
	{
		vetorOrdenado[i] = vetor[i];
		// cout << vetorOrdenado[i] << endl;
	}
	sort(vetorOrdenado.begin(), vetorOrdenado.end()); // ordena vetor recebido e salva em vetor ordenado
	// for (auto y : vetorOrdenado)
	// {
	// 	 cout << y << endl;
	// }

	// Vejo tipo de segmentos no vetor ordenado
	vector<int> tipo_seg;
	tipo_seg.push_back(vetorOrdenado[0]); // tipo de segmento 1 recebe o primeiro valor do vetor ordenado
	for (int i = 1; i < N; i++)
	{
		if (vetorOrdenado[i] != vetorOrdenado[i - 1]) // l� vetor ordenado e quando for diferente do anterior ent�o salva novo tipo de segmento e coloca no fim desse vetor
		{
			tipo_seg.push_back(vetorOrdenado[i]); // tipo_seg[0]=0
												  // tipo_seg[1]=128
												  // tipo_seg[2]=255
		}
	}
	// for (auto y : tipo_seg)
	// {
	// 	 cout << y << endl;
	// }

	// Vejo tipo de segmento do vetor recebido e quantos numeros tem
	int cont = 1;
	vector<int> num_elemen; // 2� linha da matriz
	vector<int> tipo_vetor; // 1� linha da matriz
	int aux;
	for (int i = 0; i < N; i++) // percorro vetor
	{
		int tam_tipo_seg = tipo_seg.size();	   // run codes n�o aceita dentro do for colocar j<tipo_seg.size(), por isso salvei o valor de tipo_seg.size() no inteiro tam_tipo_seg
		for (int j = 0; j < tam_tipo_seg; j++) // percorro tipos de segmentos para saber qual segmento o elemento do vetor pertence
		{
			if (vetor[i] == tipo_seg[j])
			{
				aux = tipo_seg[j];
				if (i == N - 1)
				{
					if (vetor[i] == vetor[i - 1])
					{

						tipo_vetor.push_back(aux);
						num_elemen.push_back(cont);
					}
					else
					{
						cont = 1;
						tipo_vetor.push_back(aux);
						num_elemen.push_back(cont);
					}
				}
				else if (vetor[i] == vetor[i + 1])
				{
					cont++;
				}
				else
				{
					tipo_vetor.push_back(aux);
					num_elemen.push_back(cont);
					cont = 1;
				}
			}
		}
	}
	// exibe 1º linha da matriz com os tipos do vetor
	int tam_tipo_vetor = tipo_vetor.size();
	int tam_tipo_seg = tipo_seg.size();
	int tipo_seg_final[tam_tipo_vetor];

	// atribuo os tipos do vetor, por exemplo 0 0 0, aparece tipo 0; 128 128 aparece tipo 128 para tipo_seg_final que vou usar
	for (int i = 0; i < tam_tipo_vetor; i++)
	{
		tipo_seg_final[i] = tipo_vetor[i];
	}
	for (int i = 0; i < tam_tipo_vetor; i++)
	{
		for (int j = 0; j < tam_tipo_seg; j++)
		{//tipo_seg_final[0]=0	//tipo_seg_final[1]=128		//Ent�o os tipos � o indice [i] +1

			
				if (tipo_seg_final[i] == 0)
				{
					tipo_seg_final[i] = 0 + 1;
			
				}
				else if (tipo_seg_final[i] == 128)
				{
					tipo_seg_final[i] = 1 + 1;
			
				}
				else if (tipo_seg_final[i] == 255)
				{
					tipo_seg_final[i] = 1 + 2;
			
				}

		}
	}
	vector<char> ansC;
	char aChar;
	for(int i=0;i<tam_tipo_vetor;i++){
		aChar = '0'+tipo_seg_final[i];
		ansC.push_back(aChar);
	}
	string str(ansC.begin(),ansC.end());
	string faixa=("1313131313131");
	if(str.find(faixa)!=string::npos){
		cout << "Resultado: Pista com faixa de pedestres"<<endl;
		fclose(fp);
		return 0;
	}
		
}
		cout << "Resultado: Pista sem faixa de pedestres";
		fclose(fp);
		return 0;
}


