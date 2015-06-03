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

int main()
{
   COMPLEX *x,*y,a,b;
   int i,j,N=5,inx=1,iny=1;
   x=(COMPLEX *)calloc(N,sizeof(struct mycomplex));
   y=(COMPLEX *)calloc(N,sizeof(struct mycomplex));
   x[0].real=x[0].imag=1.0;
   x[1].real=x[1].imag=2.0;
   x[2].real=x[2].imag=3.0;
   x[3].real=x[3].imag=4.0;
   x[4].real=x[4].imag=4.0;
   a.real=5;
   a.imag=1;
   b.real=4.0;
   b.imag=-3.2;
   caxpy_(&N,&a,x,&inx,y,&iny);
   for (i=0;i<5;i++)
      printf("%f+j%f\n",y[i].real,y[i].imag);
   return(0);
}
