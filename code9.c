#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    
    if (scanf("%100s", s) != 1) return 0;
    
    int len = strlen(s);
    
    int freq[26] = {0}; 
    char firstRepeated = '\0';
    
    
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'A'; 
        freq[index]++;
        
       
        if (freq[index] == 2) {
            firstRepeated = s[i];
            break; 
        }
    }
    
   
    if (firstRepeated != '\0') {
        printf("%c\n", firstRepeated);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
