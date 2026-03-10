#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    if(n < 1 || n > 100){
        printf("Invalid Input");
        return 0;
    }
          for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            printf("%d", j);
        }
        printf("\n");
    }

    for(int i = n-1; i >= 1; i--){
        for(int j = i; j <= n; j++){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}