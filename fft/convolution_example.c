#include <stdio.h>
#include <fftw3.h>
#include <math.h>
int main(void)
{
  int i,N,Nx=4,Ny=4;
  fftw_complex *in,*out,*out2,*x,*h,*Xf,*Hf,*y,*Yf;
  fftw_plan conv1_plan,conv2_plan,conv3_plan;
  /*  Note that this is not like MATLAB's fft in the sense that you can say Yf=fft(x,N); */
  N=Nx+Ny-1;
  Xf = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  Hf = (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*N);
  Yf = (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*N);
 
/* First allocate the input and output arrays */
  x=(fftw_complex*)fftw_malloc(sizeof(fftw_complex)*N);
  h=(fftw_complex*)fftw_malloc(sizeof(fftw_complex)*N);
  y=(fftw_complex*)fftw_malloc(sizeof(fftw_complex)*N);
/* Create data */
  for (i=0;i<Nx;i++)
   {
      x[i][0]=2*i;
      x[i][1]=0.;
   }
  for (i=0;i<Ny;i++)
   {
      h[i][0]=2./(i+1);
      h[i][1]=0.;
   }
  /* Find the FFT of x and h */
  conv1_plan=fftw_plan_dft_1d(N,x,Xf,FFTW_FORWARD,FFTW_ESTIMATE);
  fftw_execute(conv1_plan);
  conv2_plan=fftw_plan_dft_1d(N,h,Hf,FFTW_FORWARD,FFTW_ESTIMATE);
  fftw_execute(conv2_plan);
  /*for (i=0;i<N;i++)
    printf("%f\t%f\t%f\n",h[i][0],Hf[i][0],Hf[i][1]); */
  for (i=0;i<N;i++)
   {
    Yf[i][0]=Xf[i][0]*Hf[i][0]-Xf[i][1]*Hf[i][1]; 
    Yf[i][1]=Xf[i][0]*Hf[i][1]+Hf[i][0]*Xf[i][1];
   }
  /*for (i=0;i<N;i++)
    printf("%f\t%f\n",Yf[i][0],Yf[i][1]); */
  conv3_plan=fftw_plan_dft_1d(N,Yf,y,FFTW_BACKWARD,FFTW_ESTIMATE);
  for (i=0;i<N;i++)
     printf("%f\t%f\n",y[i][0],y[i][1]);

  fftw_destroy_plan(conv1_plan);
  fftw_destroy_plan(conv3_plan);
  fftw_destroy_plan(conv2_plan);
  fftw_free(x);
  fftw_free(y);
  fftw_free(h);
  return(0);
}

