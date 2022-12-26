 
 #include <stdio.h>
 #include <stdlib.h>

 
 
 
int main()
{

FILE *xxx;
    char str[900];
    char cifra[5000];
    /*printf("Digite o nome do arquivo de entrada: ");
    scanf("%s",str);*/
    xxx = fopen("DecodCesar.txt","r");
    if (!xxx){ //Caso ocorra algum erro na abertura do arquivo
        printf("Erro! Impossivel abrir o arquivo!\n");
        return 0;
    }
    
  
    
    
     // Imprime conteudo do arquivo
     for(int x = 0; x<5;x++){
     	 fscanf(xxx,"%c",&cifra[0]);
     	 printf("%c\n",cifra[x]);
     }
     fclose(xxx);
     
}
