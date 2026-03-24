#include <stdio.h>
#
void sortString(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char s1[51], s2[51];
    
    scanf("%s", s1);
    scanf("%s", s2);
    
   
    if(strlen(s1) != strlen(s2)) {
        printf("NO");
        return 0;
    }
    
    sortString(s1);
    sortString(s2);
    
    if(strcmp(s1, s2) == 0)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}