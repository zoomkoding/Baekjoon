#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
long long t, x, y;
int prime[100001];
int main(){
    for(int i = 2; i  < 100001; i++){
        if(prime[i])continue;
        for(int j = i + i; j < 100001; j++){
            prime[j] = 1;
        }
    }
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &x, &y);
        long long temp = x - y;
        if(temp == 1)printf("NO\n");
        else printf("YES\n");
        
    }
}