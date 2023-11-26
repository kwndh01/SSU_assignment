#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a >= b) ? a : b;
}

void compare(int A[], int rows, int cols, int a, int b) {
    if (a == 3 || b == 3) {
        return;
    }
    if (A[(a + 1) * cols + b] >= A[a * cols + (b + 1)]) {
        printf("(%d,%d) -> ", a + 2, b + 1);
        compare(A, rows, cols, a + 1, b);
    } else {
        printf("(%d,%d) -> ", a + 1, b + 2);
        compare(A, rows, cols, a, b + 1);
    }
}

void MatrixPath(int n) {
    int **memory = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        memory[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter Elements\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d Element: \n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &memory[i][j]);
        }
    }

    int **c = (int **)malloc((n + 1) * sizeof(int *));
    for (int i =0; i<=n; i++){
        c[i] = (int *)malloc((n+1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        c[i][0] = 0;
    }
    for (int j = 1; j <= n; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = memory[i - 1][j - 1] + max(c[i-1][j], c[i][j - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        free(memory[i]);
    }
    free(memory);

    int **revC = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        revC[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        revC[i][n] = 0;
    }
    for (int i = 0; i < n; i++) {
        revC[n][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            revC[i][j] = c[n - i][n - j];
        }
    }
    printf("%d\n", c[n][n]);
    printf("(1,1) -> ");
    compare((int *)revC, n + 1, n + 1, 0, 0);
    printf("(%d,%d)\n", n, n);

    for (int i = 0; i <= n; i++) {
        free(revC[i]);
        free(c[i]);
    }
    free(revC);
    free(c);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    MatrixPath(n);
    return 0;
}
