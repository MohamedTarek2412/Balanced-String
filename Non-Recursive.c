#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int longestBalancedNonRecursive(char *s) {
    int n = strlen(s), maxLen = 0;

    for (int i = 0; i < n; i++) {
        int count[128] = {0}, distinct = 0;
        for (int j = i; j < n; j++) {
            if (count[s[j]] == 0) {
                distinct++;
            }
            count[s[j]]++;

            if (distinct > 2) 
                break;

            if (distinct == 2) {
                int vals[2], idx = 0;
                for (int k = 0; k < 128; k++) {
                    if (count[k] > 0) vals[idx++] = count[k];
                    if (idx == 2) break;
                }
                if (vals[0] == vals[1]) maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int main() {
    char s[100];
    
    printf("Enter the string: ");
    scanf("%s", s);
    
    printf("Result: %d\n", longestBalancedNonRecursive(s));

    return 0;
}