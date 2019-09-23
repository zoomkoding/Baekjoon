#include <cstdio>

char s[102];
int arr['Z'-'A'+1];

int main(){
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++)arr[s[i] - 'a'] ++;
    for(int i = 0; i < 'Z'-'A' + 1; i++)printf("%d ", arr[i]);
}