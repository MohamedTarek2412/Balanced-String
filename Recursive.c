#include <stdio.h>
#include <string.h>

int isBalanced(char *s, int l, int r) {
    int count[128] = {0}, distinct = 0;

    for (int i = l; i <= r; i++) {
        if (count[(char)s[i]] == 0) distinct++;
        count[(char)s[i]]++;
    }

    if (distinct != 2) return 0;

    int vals[2], idx = 0;
    for (int i = 0; i < 128; i++) {
        if (count[i] > 0) vals[idx++] = count[i];
        if (idx == 2 && vals[0] != vals[1]) return 0;
    }
    return 1;
}

int longestBalancedRecursive(char *s, int l, int r) {
    if (r - l + 1 < 2) return 0;

    if (isBalanced(s, l, r)) return r - l + 1;

    int max1 = longestBalancedRecursive(s, l, r - 1);
    int max2 = longestBalancedRecursive(s, l + 1, r);
    return max1 > max2 ? max1 : max2;
}

int main() {
    char s[100];
    
    printf("Enter the string: ");
    scanf("%s", s);
    
    printf("Result: %d\n", longestBalancedRecursive(s, 0, strlen(s) - 1));

    return 0;
}