#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    char A[1001], B[1001];
    scanf("%s", A);
    scanf("%s", B);
    int i = 0;
    char result[1001];
    while (A[i] && B[i] && A[i] == B[i]) {
        result[i] = A[i];
        i++;
    }

    result[i] = '\0';

    if (i == 0)
        printf("-1");
    else
        printf("%s", result);


    
    return 0;
}