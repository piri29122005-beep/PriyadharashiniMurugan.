#include <stdio.h>

int main() {
    long long N;
    scanf("%lld", &N);

    int evenSum = 0, oddSum = 0;

    while (N > 0) {
        int digit = N % 10;

        if (digit % 2 == 0)
            evenSum += digit;
        else
            oddSum += digit;

        N /= 10;
    }

    int result = evenSum - oddSum;
    if (result < 0)
        result = -result;

    printf("%d", result);

    return 0;
}