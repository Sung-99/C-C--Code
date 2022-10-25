#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct product
{
   int peso;
   int valor;
}Prod;

int main()
{
    FILE *fp = fopen("Mochila.txt","r");
  //  char str[30];
    char x[5000];
    int   contStrucProd=0, cont = contStrucProd;
    int QuantdProd;
    int casosEscolher=0, contador = casosEscolher;
    struct product Prod[900];
    int EscolhaMochi[900];
    int pesoMochi;
    /*printf("Digite o nome do arquivo: ");
    scanf("%s",str);
    if (!(fp = fopen(str,"r"))){//Caso ocorra algum erro na abertura do arquivo
        return 0;
    }*/
    if (!fp){//Caso ocorra algum erro na abertura do arquivo
            printf("erro");
        return 0;
    }
    int aux;
    while ((pointer = fgets(x, sizeof(x), fp)) != NULL){// Enquanto não chegar ao final do arquivo
                if(cont == 2)QuantdProd = atoi(x);
                if(cont ==1)pesoMochi = atoi(x);
                if(cont > 2 && cont <= QuantdProd+3){//Preciso armazenar esses(a partir da posição 4 até a qtd de itens + o começo pra pegar todos) items em uma struct
                    /*------Link: Stack overflow how to split a string in two pieces------*/

                    char * p;
                    char strcopy[16];
                    char piece1[5] = ""
                    ,piece2[5] = "";
                    strcpy(strcopy, x);
                    p = strtok (strcopy," "); // call the strtok with str as 1st arg for the 1st time.
                    if (p != NULL) // check if we got a token.
                    {
                        strcpy(piece1,p); // save the token.
                        p = strtok (NULL, " "); // subsequent call should have NULL as 1st arg.
                        if (p != NULL) // check if we got a token.
                            strcpy(piece2,p); // save the token.
                        }
                    Prod[contStrucProd].peso = atoi(piece1);

                    Prod[contStrucProd].valor = atoi(piece2);

                    contStrucProd++;


                }


       cont++;
    }
    fclose(fp);

   /* for(int contando = 0; contando < QuantdProd; contando++){
        printf("%d ", Prod[contando].peso);
        printf("%d\n", Prod[contando].valor);
    }*/


    return 0;
}




