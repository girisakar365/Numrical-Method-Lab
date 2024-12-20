#include <stdio.h>
#include <math.h>

#define f(x) (x*x*x -  4*x + 1)
#define g(x) (3*x*x - 4)
#define ERR 0.0001

float nr(float x){
    return x - f(x)/g(x);
}

int main(){
    float x0,x1,x2;
    do{
        printf("Enter inital guess: ");
        scanf("%f", &x0);
    }while (g(x0) == 0);

    do{
        x1 = nr(x0);
        x2 = x0 - x1;
        x0 = x1;
    }

    while(fabs(x2) > ERR);

    printf("Root is %f\n", x0);

    return 0;

}