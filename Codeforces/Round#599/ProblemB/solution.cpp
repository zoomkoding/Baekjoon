#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t, n;
char s1[10001], s2[10001];
int main(){
    scanf("%d", &t);
    while(t--){
        int x[2], cnt = 0, valid = 1;
        scanf("%d %s %s", &n, s1, s2);
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i])continue;
            else {
                if(cnt == 2){
                    valid = 0;
                    break;
                }
                x[cnt++] = i;
            }
        }
        if(valid){
            if(cnt == 1)valid = 0;
            else if(cnt == 2) {
                if(s1[x[0]] == s1[x[1]] && s2[x[0]] == s2[x[1]]);
                else valid = 0;
            }
        }
        if(valid)printf("YES\n");
        else printf("NO\n");
    }
}