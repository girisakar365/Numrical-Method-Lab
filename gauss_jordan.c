#include <stdio.h>

int main() {
    int n;
    float ratio, a[10][11], x[10];
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the elements of augmented matrix: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Applying Gauss-Jordan Elimination
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            if(i != j) {
                ratio = a[i][j] / a[j][j];
                for(int k = 0; k < n + 1; k++) {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }

    // Obtaining the solution
    for(int i = 0; i < n; i++) {
        x[i] = a[i][n] / a[i][i];
    }

    printf("The solution is: \n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}
