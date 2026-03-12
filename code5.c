#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int products[100];
    int duplicateCount = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &products[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (products[i] == products[j] && products[i] != -1) {
                duplicateCount++;
                products[j] = -1;
            }
        }
    }
    printf("%d\n", duplicateCount);

    return 0;
}
