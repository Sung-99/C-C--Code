/****************
LAED1 - Projeto – Parte I

Aluna: Samyris Alves Rodrigues (20203008799)
	   Vitor Hugo Mota Soares (20213010530)

Data: 11/11/2022
****************/

/******************************************************************

//DESCONSIDERAR ESSE CODIGO, SERÁ ENVIADO PELO RUN CODES DA SAMYRIS

*********************************************************************/
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
	int N;
	char arq[100];
	printf("Digite o nome do arquivo: ");
	scanf("%s", arq);
	fp = fopen(arq, "r"); // Abre arquivo texto para leitura
	if (!fp)
	{
		printf("Erro na abertura do arquivo.\n");
		return 0;
	}

	// Salva N - Número de elementos do vetor
	// Salva vetor que tem tamnho igual a N
	fscanf(fp, "%d", &N); // leitura a partir do texto, lê o conteúdo até encontrar um espaço
	// int *numElemen = &N;
	// cout << "num de itens é " << *numElemen;

	int vetor[N]; // vetor[N] recebido
	int num = 0;
	int c;
	while (!feof(fp))
	{ // Enquanto não chegar ao final do arquivo
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
		if (vetorOrdenado[i] != vetorOrdenado[i - 1]) // lê vetor ordenado e quando for diferente do anterior então salva novo tipo de segmento e coloca no fim desse vetor
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
	vector<int> num_elemen; // 2ª linha da matriz
	vector<int> tipo_vetor; // 1ª linha da matriz
	int aux;
	for (int i = 0; i < N; i++) // percorro vetor
	{
		int tam_tipo_seg = tipo_seg.size();	   // run codes não aceita dentro do for colocar j<tipo_seg.size(), por isso salvei o valor de tipo_seg.size() no inteiro tam_tipo_seg
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
	// exibe 1ª linha da matriz com os tipos do vetor
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
		{//tipo_seg_final[0]=0	//tipo_seg_final[1]=128		//Então os tipos é o indice [i] +1
			if (tipo_seg_final[i] == tipo_seg[j])
			{
				tipo_seg_final[i] = j + 1;
				// cout << tipo_seg_final[i] << " ";
			}
		}
	}
	/*cout << "Matriz:" << endl;
	for (int i = 0; i < tam_tipo_vetor; i++)

	{
		for (int j = 0; j < tam_tipo_seg; j++)
		{
			if (tipo_vetor[i] == tipo_seg[j])
			{
				cout << tipo_seg_final[i] << " ";
			}
		}
	}

	cout << endl;
	// exibe 2ª linha da matriz, com a contagem dos elementos seguidos
	for (auto y : num_elemen)
	{
		cout << y << " ";
	}
	cout << endl;
*/
	//struct timeval t;

  TipoLista lista;
  TipoItem item;
  //int vetor[MAX];
  //TipoApontador p;
  //int i, j, k, n;
  //float  tamanho=0;
//   gettimeofday(&t,NULL);
//   srand((unsigned int)t.tv_usec);
  FLVazia(&lista);


  int CH;
  CH = 0;
  /*Insere cada chave na lista */
  for (int i = 0; i < tam_tipo_vetor; i++)
    {
      CH++;
      item.Chave = CH;
      item.NumElementos = num_elemen[i];
      item.PontoMedio = tipo_seg_final[tam_tipo_seg/2];
      item.tipo_Segmento = tipo_seg_final[i];
      Insere(item, &lista);
     // tamanho++;
      // printf("Inseriu: %d \n", item.Chave);
    }
     int res=0;

    int tamm = 5;
    int VetPadrao[] = {1,3,2,3,1};
    res = compara(lista, VetPadrao, tamm);
    if(res == 1)
      {
        printf("Resultado: Padrao encontrado.");
      }else
        {
            printf("Resultado: Padrao nao encontrado.");
        }

	fclose(fp);
	return 0;

}

