#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

int partition(int A[], int p, int r, int mav) {
    int x = A[r];
    if (mav != 0) {
        x = mav;
    }
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            int temp = A[++i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[r];
    A[r] = A[i + 1];
    A[i + 1] = temp;
    return i + 1;
}

int select(int A[], int p, int r, int i) {
    while (p < r) {
        int q = partition(A, p, r, 0);
        int k = q - p + 1;
        if (i == k) {
            return A[q];
        } else if (i < k) {
            r = q - 1;
        } else {
            p = q + 1;
            i -= k;
        }
    }
    return A[p];
}

void heapify(int A[], int k, int n) {
    int left = 2 * k + 1;
    int right = 2 * k + 2;
    int smaller;

    if (left < n && A[left] < A[k]) {
        smaller = left;
    } else {
        smaller = k;
    }

    if (right < n && A[right] < A[smaller]) {
        smaller = right;
    }

    if (smaller != k) {
        int temp = A[smaller];
        A[smaller] = A[k];
        A[k] = temp;
        heapify(A, smaller, n);
    }
}

void buildHeap(int A[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(A, i, n);
    }
}

void heapSort(int A[], int n) {
    buildHeap(A, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        heapify(A, 0, i);
    }
}

int linearSelect(int A[], int p, int r, int i) {
    int n = r - p+1;
    if (n <= 5) {
        return select(A, p, r, i);
    } else {
        int inv = (n - 1) / 5 + 1;
        int (*group)[5] = (int (*)[5])malloc(inv * 5 * sizeof(int));
        int *middle = (int *)malloc(inv * sizeof(int));
        int remainder;

        for (int j = 0; j < n; j++) {
            int left = j / 5;
            int right = j % 5;
            group[left][right] = A[j];
            if(j == n-1){
            	remainder  = right;
            	
            }
        }

        for (int j = 0; j < inv-1; j++) {
            heapSort(group[j], 5);
            middle[j] = group[j][2];
        }
        if(remainder != 0){
        	heapSort(group[inv-1], remainder);
        	middle[inv-1] = group[inv-1][remainder/2];
        } else{
        	heapSort(group[inv-1], 5);
        	middle[inv-1] = group[inv-1][2];
        }

        int primeMiddle = linearSelect(middle, 0, inv - 1, inv / 2);
        
        int q = partition(A, p, r, primeMiddle);
        if (q == i) {
        	free(group);
        	free(middle);
            return A[q];
        } else if (q > i) {
            int *next = (int *)malloc(q * sizeof(int));
            for (int j = 0; j < q; j++) {
                next[j] = A[p + j];
            }
            int result = linearSelect(next, 0, q - 1, i);
            free(next);
            free(group);
            free(middle);
            return result;
        } else {
            int *next = (int *)malloc((r - q) * sizeof(int));
            for (int j = 0; j < r - q; j++) {
                next[j] = A[q +1 + j];
            }
            int result = linearSelect(next, 0, r - q - 1, i - q -1);
            free(next);
            free(group);
            free(middle);
            return result;
        }
    }
}

int main() {
    struct timeval mytime;
    long startTime, endTime;
    long timeValue;
    int algorithm;
    int cycle;
    printf("Select algorithm (1/2): ");
    scanf("%d", &algorithm);
    printf("cycle: ");
    scanf("%d", &cycle);
    srand((unsigned)time(NULL));
    gettimeofday(&mytime, NULL);
    startTime = mytime.tv_sec * 1000000 + mytime.tv_usec;
    for (int at = 0; at < cycle; at++) {
        int* value = (int *)malloc(100000 * sizeof(int));
        for (int k = 0; k < 100000; k++)
            value[k] = rand() % 100; 
        int result;
        if (algorithm == 1) {
            result = select(value, 0, 99999, 50000);
        } else {
            result = linearSelect(value, 0, 99999, 50000);
        }
        printf("Result = %d\n", result);
        free(value);
    }
    gettimeofday(&mytime, NULL);
    endTime = mytime.tv_sec * 1000000 + mytime.tv_usec;
    timeValue = endTime - startTime;
    printf("Time: %.6f seconds\n", timeValue / 1000000.0);
    return 0;
}



