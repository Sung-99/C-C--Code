#include <stdio.h>
/* -- will not be needed a image to explain this exercise, is a simple converting decimal to bit */
void dec2bin(int dec)
{
if(dec >= 1){
 
  if(dec % 2 == 1){
        
	dec = dec/2;
	dec2bin(dec);
	printf("1");
	
	
	
   }else{
         
	 dec = dec/2;
         dec2bin(dec);
         printf("0");
         
   }

}
}



int main()
{
int num;
   
   	printf("Digite um numero inteiro: ");
        scanf("%d", &num);
	printf("Resultado: ");
	if(num == 0)printf("0");
        else{ 
		dec2bin(num);
	}
	printf("\n");
	
}
