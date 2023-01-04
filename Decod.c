#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
/*---Find the explanation of the exercise on ImageExercises DecodPart1, 2 and 3
*/
int BinToDec(char *h);
void TirandoCharExtra(char *h,int x);
void Rotacionanco(char *h, int b);
int main()
{
    FILE *fp;
    char str[30];
    char x[5000];
    printf("Digite o nome do arquivo: ");
    scanf("%s",str);

    printf("\n--------------------\n");
    printf("Mensagem codificada:\n");
    printf("--------------------\n");
    if (!(fp = fopen(str,"r"))){//Caso ocorra algum erro na abertura do arquivo
        return 0;
    }
    int dec;
    int blocos=0;

    //for(int cont = 0; cont < 900; cont++){
        fgets(x,5000,fp);
       // if(ferror(fp)  ||  feof(fp)) break;
    //}
    //for(int cont = 0; cont < strlen(x); cont++){
       // printf("%c",x[5]);
    //}

    dec = BinToDec(x);
    //printf("%d\n",dec);
    for(int cont = 0; cont < strlen(x); cont++){
         printf("%c", x[cont]);
    }
    printf("\n");

    printf("----------------------\n");
    printf("Mensagem decodificada:\n");
    printf("----------------------\n");
    // printf("\n--Sem a %d posicao--\n",dec);
     TirandoCharExtra(x, dec);

    // printf("\n--Separando em blocos e retirando os binarios--\n");


    //printf("\n--Rotacionando a esquerda 5 pos--\n");
    blocos = 0;
    Rotacionanco(x,blocos);

    //printf("\n--Refletindo cada bloco--\n");
    blocos=0;
    int refle = 0;
    char auxx[1];
    for(int cont = 5; cont< strlen(x);cont++){
        if(x[cont] != '\0'){
         // if(blocos%2 == 0 && blocos !=0)printf("-");
            if(refle%2 == 0){
                auxx[0] =  x[cont];
                x[cont] = x[cont+1];
                 x[cont+1] =  auxx[0];

            }
               //printf("%c", x[cont]);
               blocos++;
               refle++;

         }
     }
//    printf("\n--Permutar os blocos--\n");

    blocos=0;
    refle = 0;
    int metade = (strlen(x))/2;
   // printf("%d\n", metade);
    int ultimo = strlen(x)-1;
    int Penul =strlen(x)-2;
    for(int cont = 5; cont< strlen(x);cont++){

       // if(x[cont] != '\0'){
          if(cont <= metade){
          if(refle > 3){
                    refle = 0;

               }
            if(refle< 1){
                auxx[0] =  x[cont];
                x[cont] =  x[Penul];
                x[Penul] =  auxx[0];
                auxx[1] = x[cont+1];
                x[cont+1] = x[ultimo];
                x[ultimo] =  auxx[1];
            }
          }
               printf("%c", x[cont]);

               //blocos++;
               refle++;
               ultimo--;
               Penul--;
               if(strlen(x) % 2 != 0 && cont == strlen(x)-1)x[cont]='\0';
               
         //}
     }

    printf("\n");
        //printf("%c\n",x[strlen(x)]);
       // printf("%d",strlen(x));
    fclose(fp);
    return 0;
}

void Rotacionanco(char *h, int b){
    int aux, rot = 5;
    for(int cont = 5; cont<strlen(h);cont++){
        if(h[cont] != '\0'){
         // if(b%2 == 0 && b !=0)printf("-");
           if(h[cont] == '#'){
                aux = 32;
                }else
                    if((int)h[cont]==65){
                        aux=86;
                }else
                    if((int)h[cont]==66){
                        aux=87;
                }else
                    if((int)h[cont]==67){
                        aux=88;
                }else
                    if((int)h[cont]==68){
                        aux=89;
                }else
                    if((int)h[cont]==69){
                        aux=90;
                }else
                    if((int)h[cont]==97){
                        aux=118;
                }else
                    if((int)h[cont]==98){
                        aux=119;
                }else
                    if((int)h[cont]==99){
                        aux=120;
                }else
                    if((int)h[cont]==100){
                        aux=121;
                }else
                    if((int)h[cont]==101){
                        aux=122;
                }else{
                    aux = (int)h[cont]-rot;
                }
                h[cont] = (char)aux;
           }
           b++;
         }*/
}
void TirandoCharExtra(char *h,int x){
    for(int cont = 0; cont < strlen(h); cont++){
        if(h[cont] != '\0'){
           if(cont >= x+4)h[cont] = h[cont+1];
        }
     }
     
}
int BinToDec(char *h){
	int result = 0;
	
	for (int cont = 0, x = 4; x >= 0; x--, cont++){

		if(h[x] == '1')result = result + pow(2, cont);

	}
	
	return result;

}
