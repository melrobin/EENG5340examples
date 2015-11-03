#include <stdio.h>
#include <stdlib.h>
typedef struct _grad_return_type
{
  double x1,x2;
}  GRAD_RETURN_TYPE;
 
GRAD_RETURN_TYPE grad(double x1,double x2)
{
  GRAD_RETURN_TYPE temp;
  temp.x1=2.*x1;
  temp.x2=2.*(x2-2);
  return(temp);
}
double f(double x1,double x2)
{
  return(x1*x1+(x2-2)*(x2-2));
}
int main(int argc, char *argv[])
{
   double x0_x,x0_y,alpha;
   int niters,i;
   if (argc < 5)
    {
        printf("Not enough parameters....bye bye! \n");
        exit(0);
    }

   niters=atoi(argv[1]);
   alpha=atof(argv[2]);
   x0_x=atof(argv[3]);
   x0_y=atof(argv[4]);
   GRAD_RETURN_TYPE *theGradient;
   theGradient=(GRAD_RETURN_TYPE *)malloc(sizeof(GRAD_RETURN_TYPE));
   printf("x1\tx2\tf(x1,x2)\n"); 
   for (i=0;i<niters;i++)
     {
       *theGradient=grad(x0_x,x0_y);
       x0_x-=alpha*theGradient->x1;
       x0_y-=alpha*theGradient->x2;
       printf("%f\t%f\t%f\n",x0_x,x0_y,f(x0_x,x0_y));
     } 
   return(0);
}

