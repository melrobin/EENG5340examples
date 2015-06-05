#include <stdio.h>
#include <stdlib.h>


//      SUBROUTINE CAXPY(N,CA,CX,INCX,CY,INCY)
//      *     .. Scalar Arguments ..
//            COMPLEX CA
//                  INTEGER INCX,INCY,N
//                  *     ..
//                  *     .. Array Arguments ..
//                        COMPLEX CX(*),CY(*)
typedef struct mycomplex
{
    float real;
    float imag;
} COMPLEX;
extern void caxpy_(int *,COMPLEX *,COMPLEX *,int *,COMPLEX *,int *);
extern void cgesv_(int *,int *,COMPLEX *,int *,int *,COMPLEX *,int *,int *);
/*subroutine cgesv	(	integer 	N,
integer 	NRHS,
complex, dimension( lda, * ) 	A,
integer 	LDA,
integer, dimension( * ) 	IPIV,
complex, dimension( ldb, * ) 	B,
integer 	LDB,
integer 	INFO 
) */
	
int main()
{
   COMPLEX *x,*y,a,*A;
   int i,j,N=4,info,lda=2,ipiv[4],ldb=2,N2=2,nrhs=1;
   A=(COMPLEX *)calloc(N,sizeof(struct mycomplex));
   y=(COMPLEX *)calloc(N2,sizeof(struct mycomplex));
   for (i=0;i<4;i++)
   {   
      A[i].real=3.5*i;
      A[i].imag=i+.5;
   }
   y[0].real=2.5;
   y[0].imag=-3.2;
   y[1].real=-23;
   y[1].imag=7;
   cgesv_(&N2,&nrhs,A,&lda,ipiv,y,&ldb,&info);
   if (info)
     printf("You did something wrong in the parameters...please check that!\n");
   else
     {
       printf("We have a valid solution...just don't know if it's right or not\n");
       for (i=0;i<N2;i++)
         printf("%f+j%f\n",y[i].real,y[i].imag);
     }  
    return(0);
}
