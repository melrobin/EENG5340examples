#include <stdio.h>
#include <stdlib.h>
/* SUBROUTINE DLSODE (F, NEQ, Y, T, TOUT, ITOL, RTOL, ATOL, ITASK,
 *
 * ISTATE, IOPT, RWORK, LRW, IWORK, LIW, JAC, MF)
 * EXTERNAL F, JAC
 * INTEGER NEQ, ITOL, ITASK, ISTATE, IOPT, LRW, IWORK, LIW, MF
 * DOUBLE PRECISION Y, T, TOUT, RTOL, ATOL, RWORK
 * DIMENSION NEQ(*), Y(*), RTOL(*), ATOL(*), RWORK(LRW), IWORK(LIW)
 *
 */
extern void f_(int ,double ,double* ,double* );

extern void dlsode_(void (*)(int *,double*,double *,double *),int*,double *,double *,double *,int *,double *,double *,int *,int*,int*,double *,int*,int *,int*,void (*)(int,double ,double *,int *,int *,double *,int *),int *);
void jac(int neq,double t,double *y,int *ml,int *mu,double *pd,int *nrowpd)
{
  printf("here\n");  
}
void g(int *neq,double *t,double *y,double *ydot)
{
  double ft,eps=1e-16;
  
/* Defines unit step function 
  if (*t>=4.0)
     ft=1.0;
  else
     ft=0.0; */
/* Define sinusoidal forcing function */
  ft=cos(*t);
  ydot[0]=y[1];
  ydot[1]=ft-y[0]-3*y[1];
}
int main(int argc,char *argv[])
{
   int NEQ=2;
   int MF=10,LRW,LIW,*IWORK,IOPT=0,ITOL=1,ITASK=1,ISTATE=1;
   int i,j,Nsteps;
   double *RWORK,t,tout,ATOL,RTOL,y[2]={0,2},delta;
   FILE *fp;

   Nsteps=atoi(argv[1]);
   fp=fopen("data.txt","w");/*Our fearless data file */
   LRW = 20 + 16*NEQ;/*Set up the work arrays */
   LIW = 20;
   ATOL=RTOL=1e-3; /*Set up the tolerance*/
   IWORK=(int *)calloc(LIW,sizeof(int));/*Allocate the arrays */
   RWORK=(double *)calloc(LRW,sizeof(double));
   delta=0.1; //set up the resolution of our simulation
   t=0;
   tout=t+delta;
   fprintf(fp,"%f\t%f\t%f\n",t,y[0],y[1]); /*Write the initial conditions */ 
   for (j=0;j<Nsteps;j++) 
/* Total time base = Nsteps*delta */
   {
      dlsode_(g,&NEQ,y,&t,&tout,&ITOL,&RTOL,&ATOL,&ITASK,&ISTATE,&IOPT,RWORK, &LRW,IWORK,&LIW,jac,&MF); /*Call our ODEPACK routine */
   tout=t+delta;/*Prepare the next end point in the simulation */
   fprintf(fp,"%f\t%f\t%f\n",t,y[0],y[1]);
   /*Write the results */
  }
   return(0);
}
