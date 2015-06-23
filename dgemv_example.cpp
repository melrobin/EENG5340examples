#include <iostream>

using namespace std;
//SUBROUTINE DGEMV(TRANS,M,N,ALPHA,A,LDA,X,INCX,BETA,Y,INCY)
extern "C" void dgemv_(char *,int *,int*,double*,double *,int*,double*,int*,double*,double*,int*);

int main()
{
   double alpha=1.0,beta=0.0,*y,*A,*x;  
   int incx=1,incy=1,m=4,n=3,lda;
   A=new double[m*n];
   lda=m;
   x=new double[m];
   y=new double[m];
   A[0]=1.0;
   A[1]=-1.0;
   A[2]=1.0;
   A[3]=5.05;
   A[4]=-1.0;
   A[5]=21.0;
   A[6]=.0323;
   A[7]=.05;
   A[8]=-11.2;
   A[9]=1.0;
   A[10]=-7.2;
   A[11]=1.0;
   x[0]=.75;
   x[1]=1./3;
   x[2]=4.;
   x[3]=-2;
//   SUBROUTINE DGEMV(TRANS,M,N,ALPHA,A,LDA,X,INCX,BETA,Y,INCY)
   dgemv_("N",&m,&n,&alpha,A,&lda,x,&incx,&beta,y,&incy);
   for (int i=0;i<m;i++)
     cout << y[i] << endl;
   return(0);
}

