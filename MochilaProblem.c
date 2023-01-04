#include <stdio.h>
#include <stdlib.h>
struct product
{
   int peso;
   int valor;
}Prod;

//AVISO: DESCONSIDERAR ESSE MEU CODIGO, EU FIZ COM A SAMIRIS, MAS COMO FALTO GENUINIDADE DA MINHA PARTE NO DELA ESTOU FAZENDO ESSE POR EXERCICIO
int main()
{
    FILE *fp = fopen("Mochila.txt","r");//Txt qualquer // Any txt file
    char str[30];
    int x[9000], l = 0,h=0;
    int QtdItens, Capacidad,Capacidad2=0,val2 = 0;
    int ContItens = 0,par = ContItens;
    struct product Prod[9000];
    printf("Digite o nome do arquivo: ");
    scanf("%s",str);
    if (!(fp = fopen(str,"r"))){ //Caso ocorra algum erro na abertura do arquivo
        printf("Erro! Impossivel abrir o arquivo!\n");
        return 0;
    }
   /*--Caso ocorra algum erro na abertura do arquivo
   if (!fp){ 
        printf("Erro! Impossivel abrir o arquivo!\n");
        return 0;
    }
    ----*/

    // Imprime conteudo do arquivo
    while(fscanf(fp,"%i",&x[l]) == 1){
                //printf("%d\n", x[l]);
                if(l == 1)Capacidad = x[l];
                if(l == 2)QtdItens = x[l];
                if(l>2){
                   par++;
                   if(par > 1){
                    Prod[ContItens].peso = x[l-1];
                    Prod[ContItens].valor = x[l];
                    ContItens++;
                    par = 0;
                   }


                }
                 if(l > (QtdItens*2)+2)
                {
                    if(x[l] == 1)
                    {
                        Capacidad2 = Capacidad2 +Prod[h].peso;
                        val2 = val2 + Prod[h].valor;

                    }
                    h++;

                }


                l++;
    }


     int i, element,element2, j;
     for (i = 1; i < QtdItens; i++){
            element = Prod[i].peso;
            element2 = Prod[i].valor;
            j = i - 1;
            while (j >= 0 && Prod[j].peso > element) {
                Prod[j + 1].peso = Prod[j].peso;
                Prod[j + 1].valor = Prod[j].valor;
                j = j - 1;
            }
            Prod[j + 1].peso = element;
            Prod[j + 1].valor = element2;
    }
    int WheightSum = 0, ValSum = 0;
    h=0;
    while(WheightSum < Capacidad &&(( Prod[h].peso +WheightSum )< Capacidad) && (Prod[h].peso < Capacidad) )
    {
        WheightSum = WheightSum + Prod[h].peso;
        ValSum = ValSum + Prod[h].valor;
        h++;
    }

        if(((ValSum == val2 && WheightSum > Capacidad2)|| ValSum > val2) && WheightSum <= Capacidad)
        {
            printf("Solucao otima.");
        }else
        if(ValSum <= val2 && Capacidad2 <= Capacidad && Capacidad2 >= WheightSum)
        {
            printf("Solucao viavel mas nao otima.");
        }
        if(Capacidad2 > Capacidad)
        {
            printf("Solucao inviavel.");
        }


      fclose(fp);

    return 0;
}
