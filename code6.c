#include <stdio.h>

int main() {
    int n, score;
    int max_even = -1; 

  
    if (scanf("%d", &n) != 1) return 0;

   
    for (int i = 0; i < n; i++) {
        scanf("%d", &score);
        
        if (score % 2 == 0) {
            
            if (score > max_even) {
                max_even = score;
            }
        }
    }


    printf("%d\n", max_even);

    return 0;
}
