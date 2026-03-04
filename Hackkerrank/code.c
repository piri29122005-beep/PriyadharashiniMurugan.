// 9 ATM PIN Validation
// Problem
// Submissions
// Leaderboard
// Discussions
// Bank ATM validates PIN by checking if the sum of even-positioned digits equals sum of odd-positioned digits(1-based indexing from left i.e.Digits index start with 1). Task: Read PIN, check if sum of digits at odd positions (1,3,5...) equals sum at even positions (2,4,6...). If sum is equal then Print "VALID" otherwise print "INVALID".

// Input Format

// A line contains ATM Pin N.

// Constraints

// 11 ≤ N ≤ 9999999

// Output Format

// "VALID" or "INVALID"

// Sample Input 0

// 3234
// Sample Output 0

// VALID
// Explanation 0

// 3234 ODD index(1,3) digits sum:3+3 EVEN index(2,4) digits sum:2+4 Here ODD digits sum is equal to Even digits sum, so the output is "VALID"
int main(){
    char pin [20];
    scanf ("%s",pin);
    int odd_sum = 0,even_sum = 0;
    for(int i = 0;i < strlen(pin); i++){
        int digit = pin[i] - "0";
        if((i+1)%2==1){
            odd_sum += digit;
        }
        else{
            even_sum += digit;
        }
    }
    if(odd_sum == even_sum){
        printf("VALID");
    }else{
        printf("INVALID");
    }
    return 0;
}