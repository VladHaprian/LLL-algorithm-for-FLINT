#include <stdio.h>
#include <math.h>


// Gram-SchimdtAlgortihm used on LLL algorithm

double a[3][3] = {
    {1.0, 2.0, 1.0},
    {0.0, 1.0, 2.0},
    {1.0, 2.0, 0.0}
};
// any column of a is a vector. a is the original basis

double r[3][3], q[3][3];

int main(void) {
    int k, i, j;
    for (k=0; k<3; k++){
      r[k][k]=0; // equivalent to sum = 0
      for (i=0; i<3; i++)
        r[k][k] = r[k][k] + a[i][k] * a[i][k]; // rkk = sqr(a0k) + sqr(a1k) + sqr(a2k) 
      r[k][k] = sqrt(r[k][k]);  // ||a||
      printf("\nR%d%d: %lf ",k,k,r[k][k]);
	  
      
      for (i=0; i<3; i++) {
          q[i][k] = a[i][k]/r[k][k];
          printf("q%d%d: %lf ",i,k,q[i][k]);
		
      }
     
      for(j=k+1; j<3; j++) {
        r[k][j]=0;
        for(i=0; i<3; i++) r[k][j] += q[i][k] * a[i][j];
        printf("\nR%d%d: %lf \n",k,j,r[k][j]);
		
        
        for (i=0; i<3; i++) 
			a[i][j] = a[i][j] - r[k][j]*q[i][k];
        
        for (i=0; i<3; i++)
				printf("a%d: %lf ",j,a[i][j]);
			
      }
}

    
    return 0;
}
