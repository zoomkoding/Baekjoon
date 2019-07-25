#include <cstdio>
#include <string>
using namespace std;

int d[2] = {-1, 1}, num[10], temp, n, m, cnt, from100;
string s;

int main(){
    scanf("%d %d", &n, &m);
    from100 = n > 100 ? n - 100 : 100 - n;
    for(int i = 0; i < m; i++){
        scanf("%d", &temp);
        num[temp] = 1;
    }
    if(m == 10){
        printf("%d", from100);
        return 0;
    }
    while(1){
        for(int i = 0; i < 2; i++){
            if(n+cnt*d[i] < 0) continue;
            s = to_string(n+cnt*d[i]);
            for(int i = 0; i < s.size(); i++){
                if(num[s[i]-'0']) {
                    s[0] = '-';
                    break;
                }
            }
            if(s[0]!= '-'){
                if(cnt + s.size() < from100)printf("%lu", cnt + s.size());
                else printf("%d", from100);
                return 0;
            }
        }
        cnt++;
    }
}