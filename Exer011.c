#include<stdio.h>
double a=0.0, M[12][12];
int r;
int main() {
     scanf(" %c",&r);
    for(int l = 0; l < 12; l++){
    	for(int c = 0; c < 12; c++){
    	  scanf("%lf ",&M[l][c]);
    	  if((l < c && l < 5)&&l+c<11){
    	      a+=M[l][c];
    	  }
    	    
    	}
  
    }	
 
    
   if(r=='S'){
    printf("%.1lf\n", a);
   }else
      if(r=='M'){
        a = a/30.0;
        printf("%.1lf\n", a);
      }	
 
    return 0;
}
