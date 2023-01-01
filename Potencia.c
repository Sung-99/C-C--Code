#include<stdio.h>
/*---Power exercise with recursion---*/
int mult(int base, int exp){
 if(exp > 1){ 	
 	exp = exp - 1;
 	return mult(base,exp) * base;
 }
 return base;

}


int main() {

	int base, exp, resultado;
	
	printf("Digite a base e o expoente inteiros: ");
	scanf("%d",&base);
	scanf("%d",&exp);
	
	resultado = mult(base, exp);
	
	
	printf("Resultado: %d\n", resultado);
	return 0;
}
