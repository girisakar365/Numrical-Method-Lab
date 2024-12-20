#include <stdio.h>
#include <math.h>

#define ERR 0
#define f(x) ( x*x - 4*x - 10 )


float mid(float x_1, float x_2){
    return (x_1 + x_2) / 2;
}

_Bool bracketing_condition(float x_1, float x_2){
    return f(x_1) * f(x_2) < 0;
}

_Bool finding_root(float x_1, float x_2, float x_m){
    return fabs(f(x_1) - f(x_2)) <= ERR || fabs(x_m) <= ERR;
}

int main(){
    float x_1, x_2, x_m;

    do {
        printf("Enter the value of x_1: ");
        scanf("%f", &x_1);
        printf("Enter the value of x_2: ");
        scanf("%f", &x_2);

        if (!bracketing_condition(x_1, x_2)){
            printf("The values of x_1 & x_2 do not satisfy the bracketing condition. Please enter the values again.\n");
        }    
    }   

    while (!bracketing_condition(x_1, x_2));

    printf("\nx_1\t\tx_2\t\tx_m\t\tf(x_1)\t\tf(x_2)\t\tf(x_m)\n");

    do{
        x_m = mid(x_1, x_2);

        printf("%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",x_1, x_2, x_m, f(x_1),f(x_2),f(x_m));

        if (bracketing_condition(x_1, x_m)){
            x_2 = x_m;
        } 
        
        else{
            x_1 = x_m;
        }

    }

    while (!finding_root(x_1, x_2, x_m));

    printf("The root of the equation is: %.3f\n", x_m);

    return 0;

}