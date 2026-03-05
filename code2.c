int isPrime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 0;
}
int main() {
    int start, end;
    int count = 0;
    scanf("%d %d", &start, &end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    printf("Primes: %d", count);
    return 0;
}