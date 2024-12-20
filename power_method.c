#include <stdio.h>
#include <math.h>

#define Error 0.001


int main(){
    float var, lmd_old = 0, lmd_new;

    int m, n;

    printf("Enter the order of matrix: ");
    scanf("%d %d", &m, &n);

    float A[m][n], x[m], y[m];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Enter the value for A[%d][%d]: ",i,j);
            scanf("%f", &A[i][j]);
        }
    }

    printf("Order of matrix x: %d\n",m);

    for(int i = 0; i < m; i++){
        printf("Enter the value of x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    do{

        for (int i = 0; i < m; i++) {
            y[i] = 0;
            
            for (int j = 0; j < n; j++) {
                y[i] += A[i][j] * x[j];
                if(lmd_new < fabs(y[i])){
                    lmd_new = fabs(y[i]);
                }
            }
        }


        for(int i = 0; i < m; i++){
            x[i] = y[i]/lmd_new;
        }

        var = fabs(lmd_old - lmd_new);
    
        lmd_old = lmd_new;

    }

    while(var > Error);

    printf("Eigen Value: %f\n", lmd_new);
    
    printf("Eigen Vector:\n");

    for(int i = 0; i < m; i++){
        printf("%f\n", x[i]);
    }

    return 0;
}