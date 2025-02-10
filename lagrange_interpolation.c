#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n], X, Y = 0, L;
    printf("Enter the data points:\n");
    for(int i = 0; i < n; i++){
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    printf("Enter the value of X: ");
    scanf("%lf", &X);

    for(int i = 0; i < n; i++){
        L = 1;
        for(int j = 0; j < n; j++){
            if(j != i){
                L *= (X - x[j]) / (x[i] - x[j]);
            }
        }
        Y += y[i] * L;
    }
    
    printf("The value of Y at X = %.2lf is %.2lf\n", X, Y);
    return 0;

}