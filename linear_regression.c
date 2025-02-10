#include <stdio.h>

int main(){
    int n, i;
    float x[10], y[10], sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    printf("The linear regression equation is: y = %.2f + %.2fx\n", a, b);

    return 0;
}