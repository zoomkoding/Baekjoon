#include <cstdio>
#include <cstring>
int ans, n, k, arr[27];
char s[51][16];
//x는 가장 최근 값, y는 현재 총 개수
void find(int x, int y){
    if(y == k){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int valid = 1, sn = strlen(s[i]);
            
            for(int j = 4; j < sn - 4; j++){
                if(!arr[s[i][j] - 'a']){
                    valid = 0;
                    break;
                }
            }
            if(valid)cnt++;
        }
        if(cnt > ans)ans = cnt;
        return;
    }


    for(int i = x + 1; i <= 'z' - 'a'; i ++){
        if(arr[i])continue;
        arr[i] = 1;
        find(i, y + 1);
        arr[i] = 0;
    }
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%s", s[i]);
    arr['a' - 'a'] = arr['n' - 'a'] = arr['t' - 'a'] = arr['i' - 'a'] = arr['c' - 'a'] = 1;
    find(-1, 5);
    printf("%d", ans);
}