#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    while (scanf("%d", &n) != 1){
        while (getchar() != '\n');
    }
    while (scanf("%d", &m) != 1){
        while (getchar() != '\n');
    }

    int **matrix = (int **)malloc(n * sizeof(int *));

    if (matrix == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        
        if (matrix[i] == NULL) {
            return 1;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            while (scanf("%lf", &matrix[i][j]) != 1){
                while (getchar() != '\n');
            }
        }
    }

    if (n > 1) {
        double *temp = matrix[0];
        matrix[0] = matrix[n - 1];
        matrix[n - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        double sum = 0.0;

        for (int j = 0; j < m; j++) {
            double a = matrix[i][j]; 
            sum += (1.0 - a + a * a) / 6.0;
        }

        sum += 5.0;
    }
    
    return 0;
}