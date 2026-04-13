#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 100

int table[MAX];
int m;

void init() {
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;
}

void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

void search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}