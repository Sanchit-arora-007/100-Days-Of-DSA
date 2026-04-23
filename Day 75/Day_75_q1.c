#include <stdio.h>

#define MAX 1000
#define HASH_SIZE 20001

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int hash[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        hash[i] = -2;
    }

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int key = sum + 10000;

        if (hash[key] == -2) {
            hash[key] = i;
        } else {
            int len = i - hash[key];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}