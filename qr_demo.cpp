#include <iostream>
//Need function prototypes for QR decomposition
// SUBROUTINE DGEQRF( M, N, A, LDA, TAU, WORK, LWORK, INFO )
//  SUBROUTINE DORGQR( M, N, K, A, LDA, TAU, WORK, LWORK, INFO )
extern "C"
{
   void dgeqrf_(int*,int*,double *,int *,double *,double *,int *,int *);
   void dorgqr_(int*,int*,int*,double*,int*,double*,double*,int*,int*);
}
int main()
{
  double A[6]={1,2,3,2,3,4},b[3]={3,5,9},tau[2],*work,new_work[1];
  double A1[6]={1,2,3,2,3,4};
  int lda=3,m=3,n=2,info,lwork=-1,two=2;
  dgeqrf_(&m,&n,A,&lda,tau,new_work,&lwork,&info);
  std::cout << "info from this call is " << info << std::endl;
  std::cout << "optimal value of the dimension of work is " << new_work[0] << std:: endl;
  lwork=int(new_work[0]);
  work = new double[lwork];
  dgeqrf_(&m,&n,A,&lda,tau,work,&lwork,&info);
  dorgqr_(&m,&m,&two,A,&lda,tau,work,&lwork,&info);
  if (!info)
    for (int i=0;i<9;i++)
      std::cout <<A[i]<< std:: endl;
  else
    std::cout <<"Something is amiss.  Don't trust yourself\n";
 
 return(0);
}

