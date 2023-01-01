#include<stdio.h>
/*---Recursion excercise Greater commom divisor--*/
int mdc(int a, int b){
 if(a > b){
	if(b == 1){
	    if(a %)
	    return mdc(a,b);
	}
 }

}

int main() {

	int a, b, resultado;
	
	printf("Digite 2 numeros inteiros: ");
	scanf("%d",&a);
	scanf("%d",&b);
	
	resultado = mdc(a, b);
	
	
	printf("Resultado: %d\n", resultado);
	return 0;
}
