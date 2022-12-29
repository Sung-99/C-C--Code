#include <stdio.h>
#include <stdlib.h>


 /*-- A imagem para melhor entendimento do exercicio vai estar logo abaixo, na pasta de imagensExercicios com o nome FindbestBox*/ 

int main()
{
    FILE *fp;
    char str[30];
    int x[80][80], limite,soma,posx,posy, maxx=0;
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s",str);
    if (!(fp = fopen(str,"r"))){ //Caso ocorra algum erro na abertura do arquivo
        printf("Erro! Impossivel abrir o arquivo!\n");
        return 0;
    }


    // Imprime conteudo do arquivo
    fscanf(fp,"%d",&limite);
    for(int l = 1; l <= limite; l++){
       for(int c = 1; c < l + 1; c++){
            fscanf(fp,"%i",&x[l][c]);
       }
    }

    maxx = x[1][1];
    if(limite == 1){
                maxx = x[1][1];
                posx =1;
                posy =1;
    }else{
        for(int l = 1; l <= limite; l++){

            for(int c = 1; c < l + 1; c++){

                for(int l2 = 1; l2 < l; l2++){
                    for(int c2 = 1; c2 < l2 + 1 ; c2++){
                        if(l2 == 1 && c2 == 1){
                         soma = x[l][c] + x[l2][c2];
                        }else{
                         soma = soma + x[l2][c2];
                        }

                    }

                }
                if(l>1){
                    if(soma > maxx){
                                maxx =soma;
                                posx =l;
                                posy =c;
                    }
                }

            }
        }

    }
    printf("Resposta: fileira %i, caixa %i.",posx,posy);

    fclose(fp);
    return 0;
}
