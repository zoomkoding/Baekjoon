#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int t, a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        int m = min(a, b), infinite = 0;
        for(int i = 2; i <= m; i++){
            if(a % i == 0 && b % i == 0){
                infinite = 1;
                break;
            }
        }
        if(infinite)printf("Infinite\n");
        else printf("Finite\n");
    }
}