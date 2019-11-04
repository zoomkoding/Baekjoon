#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
long long q, n, k;

int main(){
    scanf("%lld", &q);
    while(q--){
        scanf("%lld %lld", &n, &k);
        char s[1000002];
        scanf("%s", s);
        int search = 0, to = -1, sw = 0;
        for(int i = 0; i < n; i++){
            if(k == 0)break;
            if(search == 0 && s[i] == '0')continue;
            else if(search == 0 && s[i] == '1'){
                search = 1;
                to = i;
            }
            else if(search == 1 && s[i] == '0'){
                if(i - to <= k){
                    swap(s[to], s[i]);
                    k -= i - to; 
                    if(i - to > 1)to ++;
                    else to = i;
                }
                else {
                    swap(s[i - k], s[i]);
                    k -= k;
                    break;
                }
            }
        }
        printf("%s\n", s);
    }
    
}