#include <cstdio>
#include <string.h>
int arr[1000], cnt, n1, n2;
int main(){
    char s1[1002], s2[1002];
    scanf("%s %s", s1, s2);
    n1 = strlen(s1), n2 = strlen(s2);
    for(int i = 0; i < n1; i++)arr[s1[i]]++;
    for(int i = 0; i < n2; i++){
        if(arr[s2[i]])arr[s2[i]]--, cnt++;
    }
    printf("%d", n1 + n2 - cnt * 2);
}