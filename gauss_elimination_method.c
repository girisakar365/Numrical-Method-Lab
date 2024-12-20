#include <stdio.h>

int main(){

    int n;
    float ratio;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float a[n][n+1], x[n];
    printf("Enter the elements of agumented matrix: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            scanf("%f", &a[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j){
                ratio = a[j][i]/a[i][i];
                for(int k=0; k<n+1; k++){
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        x[i] = a[i][n]/a[i][i];
    }

    printf("The solution is: \n");

    for(int i=0; i<n; i++){
        printf("x%d: %f\n",i+1, x[i]);
    }

    return 0;

}