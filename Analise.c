#include <stdio.h>
#include <stdlib.h>

int main()
{//...
    FILE *fp = fopen("analise.txt", "r");//Open my file named "analise"
    //char str[30];//variable to read a input in case the name of the file above was not given
    int Sequec = 0,*PWUnordered,*auxx,ContSeg2 = 0,*vetMatL2,*vetMatL1,ContaVetDiff = 1, **M, y= 0, cont = 0, *P, aux, *PAux, ContRepetid = 0, *PWithoutDuplicate,PwCont2 = 0, PwCont = 0;
    
  //  printf("Digite o nome do arquivo: ");
  //  scanf("%s",str);
    if (!(fp = fopen(str,"r"))){ //In case of any error 
        printf("Erro! Impossivel abrir o arquivo!\n");
        return 0;
    }  
    int tamanho; 
    fscanf(fp,"%i",&tamanho);                	      
    	       		
    	       PAux = (int *) malloc(tamanho * sizeof(int *));//Vet auxiliar para ordenar
    	       auxx = (int *) malloc(tamanho * sizeof(int *));//Vet auxiliar para pegar os elementos desordenados porem sem repetidos
    	         P = (int *) malloc(tamanho * sizeof(int *));	//Vetor principal	
    while((fscanf(fp,"%i",&y)) == 1){//Lendo a primeira linha do arquivo
    		P[cont] = y;
    		cont++;
    }
    fclose(fp);      //FECHA O ARQUIVO
    
    for(int l = 0; l < tamanho; l++){
      for(int c = l+1 ; c < tamanho; c++){
      		if(P[l] == P[c]){//Quero um vetor sem elementos repetidos n + 1 exemplo: 1 1 5 3 2 1 5 6 5 5 resultando 1 5 3 2 1 5 6 5 essa contavetdiff soma para ver quantos estao assim, para posteriormente eu retira-los do vetor. Ele NÃO BUSCA REMOVER REPETIDOS EM TD O VETOR, mas sim repetidos em sequencia
      			l++;	
      		}else{
      			l++;
      			ContaVetDiff++;
      			break;
      		}
    		
    	}
    }

     for(int l = 0; l < tamanho; l++){//Atribuindo o vetor original ao vetor auxiliar para tirar os repetidos, porem sem ordenar
      			 	
      			*(auxx+l) = *(P+l);
    }
    for(int l = 0; l < tamanho; l++){
     	for(int c = l+1; c < tamanho; c++){
      			if(auxx[l] == auxx[c]){//Somando os repetidos para remover essa quantia da soma total de elementos
      				l++;
      				ContRepetid++;	
	      				
      			}
		
      	}      	
      				 	
     }
     PWUnordered = (int *) malloc((tamanho-ContRepetid) * sizeof(int *));//Alocando meu vetor auxiliar nao ordenado com a quantia total do meu vetor original - a quantidade de repetidos, resultando em um vetor sem repetidos
     for(int l = 0; l < tamanho; l++){
  	
  			
     	for(int c = l+1; c < tamanho; c++){
      			if(*(auxx+l) ==  auxx[c]){
      				
      				l++;
      				      			     				
      			}else{
      				PWUnordered[PwCont2] = *(auxx+l);//Colocando os elementos nao ordenados porem sem repetições no meu vetor
      				PwCont2++;
      				l++;      				
      			}     			     					
      	}
      	if(l == tamanho-1){
  		PWUnordered[PwCont2] = auxx[l];//como ele incrementa meu l sempre que encontra um repetido, caso meus ultimos elementos sejam repetidos, ele nao vai pegar, por isso quando ele estiver no ultimo elemento, ele vai atribuir a ultima posição do meu vetor 	
  		
  	}
      	    						 	
     }
    for(int l = 0; l < tamanho; l++){
      			*(PAux+l) = *(P+l);//Alocando a outro auxiliar, porem dessa vez para ordenalos
      			 	
    }	
    for(int l = 0; l < tamanho; l++){
      for(int c = l+1 ; c < x; c++){
      		if(PAux[l] > PAux[c]){//Ordenação
      			aux = *(PAux+l);
      	
      			*(PAux+l) = PAux[c];
      			
      			PAux[c] = aux;	
      		}
    		
    	}
    }
    ContRepetid = 0;//Para nao criar mais variaveis vou reutiliza-la. Para que ela não venha com a quantia realizada anteriormente, preciso zera-la
     for(int l = 0; l < tamanho; l++){
     	for(int c = l+1; c < tamanho; c++){
      			if(PAux[l] == PAux[c]){//Retirando os repetidos, porem dessa vez ordenando-os
      				l++;
      				ContRepetid++;	
	      				
      			}
		
      	}      	
      				 	
     }

     PWithoutDuplicate = (int *) malloc((tamanho-ContRepetid) * sizeof(int *));//alocando meu vetor de elementos ordenados, mas sem repetições
     for(int l = 0; l < x; l++){
  	
  			
     	for(int c = l+1; c < tamanho; c++){
      			if(*(PAux+l) ==  PAux[c]){
      				
      				l++;     				      			     			
      			}else{
      				PWithoutDuplicate[PwCont] = *(PAux+l);
      				PwCont++;
      				l++;     				
      			}
      			     					
      	}
      	if(l == tamanho-1){
  		PWithoutDuplicate[PwCont] = PAux[l]; 	
  		
  	}
      	    						 	
     }
    vetMatL1 = (int *) malloc(ContaVetDiff* sizeof(int *));//Essa vai ser a linha dos meus segmentos
    vetMatL2 = (int *) malloc(ContaVetDiff* sizeof(int *));//Essa a linha das quantidades
    //vou atribui-las as colunas da matriz
     
   for(int c = 0; c < PwCont2+1; c++){
    	for(int h = 0; h < PwCont+1; h++){
    		if(PWUnordered[c] == PWithoutDuplicate[h]){
    			vetMatL1[ContSeg2] = h+1;//Colocando meu segmento de acordo com o elemento da matriz(nao ordenada), sem as repetições(repetições seguidas, por exemplo: 1 1 2 3 1 2 3 3 4 3) retirando as repetições seguidas fica 1 2 3 1 2 3 4 3, ou seja, nao retiro as repetições do vetor inteiro, mas sim das repetições seguidas.
    			ContSeg2++;
    			break;		
    		}			
    	}
      	 	  	  				 	
     }
   ContSeg2=0;
   int p = 0, cc = 0;      
   for(int c = 0; c < PwCont2+1; c++){//Somar a quantidade de vezes que o elemento aparece sequencialmente
    	for(int h = p; h < tamanho; h++){
    		cc = h;
    		while(PWUnordered[c] == P[cc] && p < tamanho && cc < tamanho){
    			Sequec =Sequec+1;//Somando os pesos
    			p++;
    			cc++;
    					
    		}	
    			vetMatL2[ContSeg2] = Sequec;
    			ContSeg2++;
    			Sequec = 0;
    			
    			break;    		    					
    	}
      	 	  	  				 	
   }
    M = (int **) malloc(2 * sizeof(int *)); 
    for (int i = 0; i < 2; ++i)M[i] = (int *) malloc (ContSeg2 * sizeof (int));//acolando as colunas referentes a minha matriz, com o numero de seguimentos encontrados
 
    for (int i = 0; i < 2; ++i){
     	for (int l = 0; l < ContSeg2; ++l){
     		if(i == 0 && &vetMatL1[l] != NULL)M[i][l] = vetMatL1[l];
     	    	if(i == 1 && &vetMatL2[l] != NULL)M[i][l] = vetMatL2[l];	     		     		    	
     	}
     
     }
      printf("Matriz:\n");		
      for (int i = 0; i < 2; ++i){
     	for (int l = 0; l < ContSeg2; ++l){
     		printf("%d ",M[i][l]);	     		     		
     	}
     	printf("\n");
     
     }   
   return 0;
}
