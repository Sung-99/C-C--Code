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
#include <stdlib.h>


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
void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    { printf("[%d]", Aux -> Item.PontoMedio);
      Aux = Aux -> Prox;
    }
}




/* ========================================================================== */

int main(int argc, char *argv[])
{
	FILE *fp;

 //   int aux_Vet = 0;
	char arq[100];
	printf("Digite o nome do arquivo: ");
	scanf("%s", arq);
	fp = fopen(arq, "r"); // Abre arquivo texto para leitura
	if (!fp)
	{
		printf("Erro na abertura do arquivo.\n");
		return 0;
	}

    int N;

	fscanf(fp, "%d", &N); // leitura a partir do texto, lê o conteúdo até encontrar um espaço
    TipoLista lista[N];
    TipoItem item;

	//int vetor[N]; // vetor[N] recebido
	int num = 0;
	int c;
	int *vetor= (int *) malloc(1 * sizeof(int *));//Alocando meu vetor auxiliar nao ordenado com a quantia total do meu vetor original - a quantidade de repetidos, resultando em um vetor sem repetidos
	free(vetor);
	while (num < N)
	{ // Enquanto não chegar ao final do arquivo
        fscanf(fp, "%d", &c);
        int num2=0;

        int *vetor= (int *) malloc(c * sizeof(int *));//Alocando meu vetor auxiliar nao ordenado com a quantia total do meu vetor original - a quantidade de repetidos, resultando em um vetor sem repetidos
        int cc;
        while(num2 < c)
        {
            fscanf(fp, "%d", &cc);
            vetor[num2] = cc;
            //cout << "["<<  vetor[num2]  << "]" ;
            num2++;
        }

       // for(int hhh = 0; hhh < c; hhh++)cout << "["<<  vetor[hhh]  << "]" ;
		//break;
        // cout << endl;




	// Salvar os valores do vetor para ordenar em vetor ordenado para saber tipo de segmento depois
	vector<int> vetorOrdenado(c);
	for (int i = 0; i < c; i++)
	{
		vetorOrdenado[i] = vetor[i];
	}
	sort(vetorOrdenado.begin(), vetorOrdenado.end()); // ordena vetor recebido e salva em vetor ordenado

	// Vejo tipo de segmentos no vetor ordenado
	vector<int> tipo_seg;
	tipo_seg.push_back(vetorOrdenado[0]); // tipo de segmento 1 recebe o primeiro valor do vetor ordenado
	for (int i = 1; i < c; i++)
	{
		if (vetorOrdenado[i] != vetorOrdenado[i - 1]) // lê vetor ordenado e quando for diferente do anterior então salva novo tipo de segmento e coloca no fim desse vetor
		{
			tipo_seg.push_back(vetorOrdenado[i]); // tipo_seg[0]=0
												  // tipo_seg[1]=128
												  // tipo_seg[2]=255
		}
	}
	// Vejo tipo de segmento do vetor recebido e quantos numeros tem
	int cont = 1;

	vector<int> num_elemen; // 2ª linha da matriz
	vector<int> tipo_vetor; // 1ª linha da matriz
	int aux;
	for (int i = 0; i < c; i++) // percorro vetor
	{
		int tam_tipo_seg = tipo_seg.size();	   // run codes não aceita dentro do for colocar j<tipo_seg.size(), por isso salvei o valor de tipo_seg.size() no inteiro tam_tipo_seg

		for (int j = 0; j < tam_tipo_seg; j++) // percorro tipos de segmentos para saber qual segmento o elemento do vetor pertence
		{
			if (vetor[i] == tipo_seg[j])
			{
				aux = tipo_seg[j];


				if (i == c - 1)
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
    /*Calculando meu ponto medio de cada segmento*/
        int LastElement, FirstElement;
        int contt=0;
        int Arma_PMedio[tam_tipo_vetor];

        for(int ppp = 0; ppp < c; ppp++)
        {
                if(ppp == 0)FirstElement = ppp;
                if((vetor[ppp] != vetor[ppp+1]))
                {
                    LastElement = ppp;
                    Arma_PMedio[contt] = (FirstElement + LastElement)/2;
                    contt++;
                    FirstElement = ppp+1;

                }else if(ppp == c - 1)
                {
                    LastElement = ppp;
                    Arma_PMedio[contt] = (FirstElement + LastElement)/2;
                }

        }
        //for(int hhh = 0; hhh < tam_tipo_vetor; hhh++)cout <<"{"<< num_elemen[hhh] <<"}" <<"["<< tipo_seg_final[hhh]  << "]";
      //cout << tipo_seg_final[i] << " "; for(int hhh = 0; hhh < tam_tipo_vetor; hhh++)cout << "["<< Arma_PMedio[hhh]  << "]";
      //cout << endl;
      // for(int hhh = 0; hhh < tam_tipo_vetor; hhh++)if(vetor[Arma_PMedio[hhh]] == 128)
    /*----------------------------*/



   /*int vetor[MAX];
   TipoApontador p;
   int i, j, k, n;
   float  tamanho=0;
   gettimeofday(&t,NULL);
   srand((unsigned int)t.tv_usec);*/
  FLVazia(&lista[num]);



  /*Insere cada chave na lista */
    int CH;
    CH = 0;

   for (int i = 0; i < tam_tipo_vetor; i++)
    {

      CH++;
      item.Chave = CH;
      item.NumElementos = num_elemen[i];
      item.PontoMedio = Arma_PMedio[i];
      item.tipo_Segmento = tipo_seg_final[i];

      Insere(item, &lista[num]);
    }
  //  Imprime(lista[num]);
     /*----------Função para mostrar os segmentos e falar sobre os padroes
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
        }*/
    /*------Logica para conferir os pontos medios das listas e ver qual lado a curva ai-----*/

        num++;

       // cout << endl;
	}

  int Soma_Vermelho = 0;
  TipoLista pp;
  TipoApontador Auxx;
  int SomaPadra = 0;
 // 1 3 2 3 1
 // int armazena_PMedio = 0;
 // virouEsq = false, virouDir = false;

int confereGamb =0;
int newgame=0, cont_ArmaPadr = 0;
   for(int xxx = 0; xxx < N; xxx++)
     {
         pp = lista[xxx];
         Auxx = pp.Primeiro->Prox;
         while(Auxx!=NULL)

         {
            
            if(Auxx ->Item.tipo_Segmento == 1)
            {
                Auxx = Auxx ->Prox;
                if(Auxx == NULL)break;
                if(Auxx ->Item.tipo_Segmento == 3)
                {	
             		 confereGamb = 1;
             	   	Auxx = Auxx ->Prox;
                	if(Auxx == NULL)break;
                	if(Auxx ->Item.tipo_Segmento == 2)
                	{
                		confereGamb++;
                		newgame=Auxx ->Item.PontoMedio;
                		Auxx = Auxx ->Prox;
                		if(Auxx == NULL)break;
                		if(Auxx ->Item.tipo_Segmento == 3)
                		{	
                			confereGamb++;
                			Auxx = Auxx ->Prox;
                			if(Auxx == NULL)break;
                			if(Auxx ->Item.tipo_Segmento == 1)
                			{
                				Soma_Vermelho++;
                				SomaPadra++;
                				
                				
                				confereGamb = 0;
      						newgame=0;
      						cont_ArmaPadr++;//Contando os valores em que o segmento é 2(vermelho), porem dentro do padrão
                				
                				
                			}
                			break;
                		}
                		break;
                	}
                	break;
                }
                break;
            } 
            break;
         }

     }
      int Arma_PMedio[cont_ArmaPadr];
      confereGamb = 0;
      newgame=0;
   cont_ArmaPadr = 0;
       for(int xxx = 0; xxx < N; xxx++)
     {
         pp = lista[xxx];
         Auxx = pp.Primeiro->Prox;
         while(Auxx!=NULL)
         {
            
            if(Auxx ->Item.tipo_Segmento == 1)
            {
                Auxx = Auxx ->Prox;
                if(Auxx == NULL)break;
                if(Auxx ->Item.tipo_Segmento == 3)
                {	
             		 confereGamb = 1;
             	   	Auxx = Auxx ->Prox;
                	if(Auxx == NULL)break;
                	if(Auxx ->Item.tipo_Segmento == 2)
                	{
                		confereGamb++;
                		newgame=Auxx ->Item.PontoMedio;
                		Auxx = Auxx ->Prox;
                		if(Auxx == NULL)break;
                		if(Auxx ->Item.tipo_Segmento == 3)
                		{	
                			confereGamb++;
                			Auxx = Auxx ->Prox;
                			if(Auxx == NULL)break;
                			if(Auxx ->Item.tipo_Segmento == 1)
                			{
                				Soma_Vermelho++;
                				SomaPadra++;
                				
                				if(confereGamb == 3)Arma_PMedio[cont_ArmaPadr]  = newgame; //Armazenando cada elemento de newgame(considerando que esse vermelho esteja dentro da condição de que exista o padrao nesse segmento) esses elementos sendo meu ponto médio(posição).
                				confereGamb = 0;
      						newgame=0;
      						cont_ArmaPadr++;
                				
                			}
                			break;
                		}
                		break;
                	}
                	break;
                }
                break;
            } 
            break;
         }

     }
    //Avaliar se está em linha reta EXEM: diferença entre um e outro é muito pequena
    int T = 0;

    	if(SomaPadra>=10){
          if(abs(Arma_PMedio[T] - Arma_PMedio[cont_ArmaPadr/2]) <= 49)
          {

              cout << "Resultado: Pista em linha reta.";
           
          }

          if(Arma_PMedio[T] < Arma_PMedio[T+1] && (abs(Arma_PMedio[T] - Arma_PMedio[cont_ArmaPadr/2]) >= 50))
          {


              cout <<  "Resultado: Curva a esquerda.";
     

          }
          if(Arma_PMedio[T] > Arma_PMedio[T+1] && (abs(Arma_PMedio[T] - Arma_PMedio[cont_ArmaPadr/2]) >= 50))
          {
               cout <<  "Resultado: Curva a direita.";
             
          }
	

	}else
	{
		cout << "Resultado: Formato da pista nao estimado.";
	}

		
	
	
	fclose(fp);
	return 0;

}

