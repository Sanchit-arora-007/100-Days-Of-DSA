#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    int *freq = (int*)calloc(2 * MAX + 1, sizeof(int));
    int offset = MAX;

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        count += freq[prefixSum + offset];
        freq[prefixSum + offset]++;
    }

    printf("Count of zero-sum subarrays: %d\n", count);

    free(freq);
    return 0;
}