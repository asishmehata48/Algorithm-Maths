#include<stdio.h>
#include<math.h>
#define f(x) (a3*x*x*x*x + a2*x*x + a1*x + a0)
#define fd(x) (3*a3*x*x*x + 2*a2*x + a1)
float a0, a1, a2, a3;
int main(){
    float x0,x1, fx0, fdx0, E, ER;
    int i = 0;
    printf("Enter the coefficient of a3, a2, a1, a0: \n");
    scanf("%f%f%f%f", &a3, &a2, &a1, &a0);
    printf("Enter initial guess and E \n");
    scanf("%f%f", &x0, &E);
    while(1)
    {
        fx0 = f(x0);
        fdx0 = fd(x0);
        x1 = x0 - (fx0/fdx0);
        ER = (x1 - x0)/x1;
        if(fabs(ER) < E)
        {
            printf("Root = %f\n", x1);
            break;
        }
        x0 = x1;
        i= i+1;
        if(i ==50)
        break;
    }
    getchar();
}