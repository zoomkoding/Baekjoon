#include <cstdio>
#include <cstring>
int ans, n, sn, arr[26], cmp[26];
char s[11];
int main(){
    scanf("%d %s", &n, s);
    sn = strlen(s);
    for(int i = 0; i < sn; i++)arr[s[i] - 'A']++;
    for(int i = 0; i < n - 1; i++){
        scanf("%s", s);
        int add = 0, sub = 0;
        int cn = strlen(s), cmp[26] = {0,}, valid = 1;
        for(int j = 0; j < cn; j++){
            int temp = s[j] - 'A';
            cmp[temp]++;
        }
        for(int j = 0; j < 26; j++){
            cmp[j] -= arr[j];
            if(cmp[j] > 1 || cmp[j] < -1){
                valid = 0;
                break;
            }
            if(cmp[j] == -1){
                if(sub == 1){
                    valid = 0;
                    break;
                }
                sub = 1;
            }
            if(cmp[j] == 1){
                if(add == 1){
                    valid = 0;
                    break;
                }
                add = 1;
            }
        }
        if(valid)ans++;
    }
    printf("%d", ans);
}