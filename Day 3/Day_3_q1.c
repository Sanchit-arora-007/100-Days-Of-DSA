#include <stdio.h>

int main() {
    int n, k, i, comparisons = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", comparisons);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d", comparisons);

    return 0;
}
