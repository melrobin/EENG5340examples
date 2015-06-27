#include <iostream>
#include <stdio.h>
using namespace std;
//SUBROUTINE DGEMV(TRANS,M,N,ALPHA,A,LDA,X,INCX,BETA,Y,INCY)
//      SUBROUTINE DGESVD( JOBU, JOBVT, M, N, A, LDA, S, U, LDU, VT, LDVT,
//           $                   WORK, LWORK, INFO )
//DOUBLE PRECISION function ddot	(	integer 	N,
//double precision, dimension(*) 	DX,
//integer 	INCX,
//double precision, dimension(*) 	DY,
//integer 	INCY 
//)		
//
extern "C"
{
   void dgemv_(char *,int *,int*,double*,double *,int*,double*,int*,double*,double*,int*);
   void dgesvd_(char *,char*,int*,int*,double*,int*,double*,double*,int*,double*,int*,double*,int*,int*);
   double ddot_(int*,double*,int*,double*,int*);
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
   double alpha=1.0,beta=0.0,*y,*A,*x;
   int incx=1,incy=1,m=3,n=2,lda,info;
   int lwork=-1,ldu=m,ldvt=n;
   A=new double[m*n];
   double s[n],*U,*VT,old_work[1],*work,*b;  
   lda=m;
   x=new double[m];
   b=new double[m];
   y=new double[m];
   U=new double[m*m];
   VT=new double[n*n]; 
   double *z=new double[n];
   //x+2y=-4
   //-3x+4y=7
   //-.3x-2y=-6
   //Find least squares solution
   //   1  2
   //  -3  4
   // -.3 -2
   //
   // -4
   // 7
   // -6 
   A[0]=1.0;
   A[1]=-3.0;
   A[2]=-.3;
   A[3]=2;
   A[4]=4;
   A[5]=-2;

   b[0]=-4;
   b[1]=7;
   b[2]=-6;
//   SUBROUTINE DGEMV(TRANS,M,N,ALPHA,A,LDA,X,INCX,BETA,Y,INCY)
//   dgemv_("N",&m,&n,&alpha,A,&lda,x,&incx,&beta,y,&incy);
//   for (int i=0;i<m;i++)
//     cout << y[i] << endl;
   dgesvd_("A","A",&m,&n,A,&lda,s,U,&ldu,VT,&ldvt,old_work,&lwork,&info);
   lwork=(int)old_work[0];
   work = new double[lwork];
   dgesvd_("A","A",&m,&n,A,&lda,s,U,&ldu,VT,&ldvt,work,&lwork,&info);
  for (int i=0;i<n;i++)
      cout << s[i] << endl;
   print_matrix("U",m,m,U,ldu);
//   cout << endl;
//   print_matrix("VT",n,n,VT,ldvt);
   cout << endl;
   cout << "********************" << endl;
   double *temp_u=new double[m];
   for (int i=0;i<n;i++)
    {
      for (int j=0;j<m;j++)
       {
         temp_u[j]=U[i*m+j];
       //  cout << temp_u[j]<< " ";
       }
     // cout << endl;   
    z[i]=ddot_(&m,b,&incx,temp_u,&incx)/s[i];
    } 
   dgemv_("T",&n,&n,&alpha,VT,&ldvt,z,&incx,&beta,y,&incy); 
   for (int i=0;i<n;i++)
       cout << y[i] << endl;
   return(0);
}

