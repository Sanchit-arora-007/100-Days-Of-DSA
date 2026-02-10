#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    int left = 0, right = strlen(s) - 1, isPalindrome = 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
