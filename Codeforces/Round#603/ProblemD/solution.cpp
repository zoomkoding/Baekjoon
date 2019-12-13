#include <cstdio>
char s[51];
int ans, n, m, t, par[26], visited[26];
int find(int x) {
    if (x == par[x])return x;
    return par[x] = find(par[x]);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < 26; i++)par[i] = i;
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; s[j] != '\0'; j++){
            visited[s[j] - 'a'] = 1;
            if(s[j + 1] == '\0')break;
            int p1 = find(s[j] - 'a'), p2 = find(s[j + 1] - 'a');
            if(p1 == p2)continue;
            else par[p1] = p2;
        }
    }
    for(int i = 0; i < 26; i++){
        if(visited[i] == 0)continue;
        if(par[i] == i)ans++;
    }
    printf("%d", ans);
}