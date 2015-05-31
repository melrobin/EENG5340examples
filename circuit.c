#include <stdio.h>

/*SUBROUTINE DGESV( N, NRHS, A, LDA, IPIV, B, LDB, INFO ) */
void dgesv_(int *,int *,double *,int *,int *,double *,int*,int *);
int main()
{
  FILE *fp;
  int i,info,lda=5,ldb=5,N=5,NRHS=1,ipiv[5];
  double A[25],b[5];
  fp=fopen("matrix.txt","r");
  for (i=0;i<25;i++)
    fscanf(fp,"%lf",&A[i]);
  for (i=0;i<5;i++)
    fscanf(fp,"%lf",&b[i]);
  dgesv_(&N,&NRHS,A,&lda,ipiv,b,&ldb,&info);
  printf("Return status: %d\n",info);
  for (i=0;i<N;i++)
    printf("%f\n",b[i]);
  return(0);
}

