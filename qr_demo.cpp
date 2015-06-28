#include <iostream>
#include <stdio.h>
//Need function prototypes for QR decomposition
// SUBROUTINE DGEQRF( M, N, A, LDA, TAU, WORK, LWORK, INFO )
//  SUBROUTINE DORGQR( M, N, K, A, LDA, TAU, WORK, LWORK, INFO )
//   /*SUBROUTINE DGESV( N, NRHS, A, LDA, IPIV, B, LDB, INFO ) */
extern "C"
{
   void dgeqrf_(int*,int*,double *,int *,double *,double *,int *,int *);
   void dorgqr_(int*,int*,int*,double*,int*,double*,double*,int*,int*);
   void dgesv_(int *,int *,double *,int *,int *,double *,int*,int *);
   void dgemv_(char *,int *,int*,double*,double *,int*,double*,int* ,double *,double*,int*);
}
  void print_matrix( char* desc, int m, int n, double* a, int lda ) 
{
      int i, j;
       printf( "\n %s\n", desc );
          for( i = 0; i < m; i++ ) {
                 for( j = 0; j < n; j++ ) printf( " %10.6f", a[i+j*lda] );
                  printf( "\n" );
          }
 }
 
int main()
{
  double A[6]={1,2,3,2,3,4},b[3]={3,5,9},tau[2],*work,new_work[1];
  double A1[6]={1,2,3,2,3,4};
  int lda=3,m=3,n=2,info,lwork=-1,two=2,inx=1;
  double R[n*n],Q[m*m],zero=0.; //Look at appropriate dimensions of Q and R
  dgeqrf_(&m,&n,A,&lda,tau,new_work,&lwork,&info); //Workspace query
 // std::cout << "info from this call is " << info << std::endl;
 // std::cout << "optimal value of the dimension of work is " << new_work[0] << std:: endl;
  lwork=int(new_work[0]);//We now have the optimal length for work
  work = new double[lwork];//Declare this array
  dgeqrf_(&m,&n,A,&lda,tau,work,&lwork,&info); //Find R and the tau factors
  int i,j;
  for (j=0;j<n;j++)
     for (i=0;i<=j;i++)
          R[i+j*n]=A[i+j*m];
  dorgqr_(&m,&m,&two,A,&lda,tau,work,&lwork,&info); //For this problem Q is M by N
  //print_matrix("R",n,n,R,n);
 //of course A now contains Q after DORGQR
 double alpha=1.0;
  double y[n];
  int  ipiv[n];
  dgemv_("T",&m,&n,&alpha,A,&m,b,&inx,&zero,y,&inx); //y=Q^Tb
  dgesv_(&n,&inx,R,&n,ipiv,y,&n,&info);
  std::cout << info << std::endl;
  if (!info)
  {  
    std::cout << "The solution vector is" << std::endl;
    for (i=0;i<n;i++)
      std::cout <<y[i]<< std:: endl;
  }
  else
    std::cout <<"Something is amiss.  Don't trust yourself\n";
 return(0);
}

