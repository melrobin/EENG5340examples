#include <iostream>
#include <stdio.h>
using namespace std;
//SUBROUTINE DGEMV(TRANS,M,N,ALPHA,A,LDA,X,INCX,BETA,Y,INCY)
//      SUBROUTINE DGESVD( JOBU, JOBVT, M, N, A, LDA, S, U, LDU, VT, LDVT,
//           $                   WORK, LWORK, INFO )
extern "C"
{
   void dgemv_(char *,int *,int*,double*,double *,int*,double*,int*,double*,double*,int*);
   void dgesvd_(char *,char*,int*,int*,double*,int*,double*,double*,int*,double*,int*,double*,int*,int*);
}
void print_matrix( char* desc, int m, int n, double* a, int lda ) {
        int i, j;
        printf( "\n %s\n", desc );
        for( i = 0; i < m; i++ ) {
                for( j = 0; j < n; j++ ) printf( " %10.6f", a[i+j*lda] );
                printf( "\n" );
        }
}
int main()
{
   double alpha=1.0,beta=0.0,*y,*A,*x,s[3],*U,*VT,old_work[1],*work;  
   int incx=1,incy=1,m=4,n=3,lda,info,lwork=-1,ldu=4,ldvt=3;
   A=new double[m*n];
   lda=m;
   x=new double[m];
   y=new double[m];
   U=new double[m*m];
   VT=new double[n*n]; 
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
//      SUBROUTINE DGESVD( JOBU, JOBVT, M, N, A, LDA, S, U, LDU, VT, LDVT,
//           $                   WORK, LWORK, INFO )
   dgesvd_("A","A",&m,&n,A,&lda,s,U,&ldu,VT,&ldvt,old_work,&lwork,&info);
   cout << "The optimal value of work is " << old_work[0]<< endl;
   cout << info << endl;
   lwork=(int)old_work[0];
   work = new double[lwork];
   dgesvd_("A","A",&m,&n,A,&lda,s,U,&ldu,VT,&ldvt,work,&lwork,&info);
   for (int i=0;i<3;i++)
      cout << s[i] << endl;
   print_matrix("U",m,m,U,ldu);
   cout << endl;
   print_matrix("VT",n,n,VT,ldvt);
   return(0);
}

