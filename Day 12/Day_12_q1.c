#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int i, j;
    int symmetric = 1;

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m != n) {
        symmetric = 0;
    } else {
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(matrix[i][j] != matrix[j][i]) {
                    symmetric = 0;
                    break;
                }
            }
            if(symmetric == 0)
                break;
        }
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
