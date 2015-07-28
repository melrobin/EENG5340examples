#include <stdio.h>
#include <fftw3.h>
#include <math.h>
int main(void)
{
  int i,N=10;
  fftw_complex *in,*out,*out2;
  fftw_plan my_plan,your_plan;
  /*  Note that this is not like MATLAB's fft in the sense that you can say Yf=fft(x,N); */
  in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  out2 = (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*N);

  for (i=0;i<N;i++)
   {
      in[i][0]=sin(i);
      printf("%f\n",in[i][0]);
      in[i][1]=0.;
   }
  
  my_plan=fftw_plan_dft_1d(N,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
  your_plan=fftw_plan_dft_1d(N,out,out2,FFTW_BACKWARD,FFTW_ESTIMATE);
  fftw_execute(my_plan);
   fftw_execute(your_plan);
  printf("\nOutput\n");
  for (i=0;i<N;i++)
     printf("%f+j%f\n",out2[i][0]/N,out2[i][1]/N);

  fftw_destroy_plan(my_plan);
  fftw_destroy_plan(your_plan);
  fftw_free(in);
  fftw_free(out);
  fftw_free(out2);
  return(0);
}

