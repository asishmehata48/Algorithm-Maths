#include <stdio.h>

int main()
{
    int n, i;
    float a = 0, b = 0, x[10], y[10], sx = 0, sy = 0, sxy = 0, sxz = 0;
    
    printf("Enter the number of points\n");
    scanf("%d", &n);
    
    // Input validation
    if (n > 10 || n <= 0) {
        printf("Error: Number of points should be between 1 and 10\n");
        return 1;
    }
    
    printf("Enter the value of x and fx\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }
    
    for(i = 0; i < n; i++)
    {
        sx = sx + x[i];
        sy = sy + y[i];
        sxy = sxy + x[i] * y[i];
        sxz = sxz + x[i] * x[i];
    }
    
    // Calculate slope (b) and intercept (a)
    float denominator = (n * sxz) - (sx * sx);
    
    // Check for division by zero
    if (denominator == 0) {
        printf("Error: Cannot fit line - division by zero\n");
        return 1;
    }
    
    b = ((n * sxy) - (sx * sy)) / denominator;
    a = (sy / n) - (b * sx / n);
    
    printf("Fitted line is: y = %f + %fx\n", a, b);
    
    return 0;
}