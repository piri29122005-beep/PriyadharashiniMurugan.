#include <stdio.h>

int main() {
    int n;
   
    if (scanf("%d", &n) != 1) return 0;

    
    int freq[101] = {0};
    int max_freq = 0;

    for (int i = 0; i < n; i++) {
        int mark;
        scanf("%d", &mark);
        freq[mark]++;
        
      
        if (freq[mark] > max_freq) {
            max_freq = freq[mark];
        }
    }

  
    int first = 1;
    for (int i = 0; i <= 100; i++) {
        if (freq[i] == max_freq) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i);
            first = 0;
        }
    }

    return 0;
}
