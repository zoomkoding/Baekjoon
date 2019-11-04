#include <cstdio>
int arr[5001][2], num, nxt, p, n;
char s[5001];
int main(){
    scanf("%s", s);
    p = s[0] - '0';
    if(p != 0)arr[0][0] = 1;
    for(int i = 1; s[i] != '\0'; i++){
        n++;
        num = s[i] - '0';
        if(num)arr[i][0] = (arr[i-1][0]+arr[i-1][1]) % 1000000;
        nxt = p * 10 + num; 
        if(!nxt)break;
        if(nxt > 9 && nxt < 27)arr[i][1] = arr[i-1][0] % 1000000;
        p = num;
    }
    printf("%d", (arr[n][0] + arr[n][1]) % 1000000);
}