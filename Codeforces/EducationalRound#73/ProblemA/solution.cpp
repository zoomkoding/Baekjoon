#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int t, n, s[101];
int main(){
    scanf("%d", &t);
    while(t--){
        priority_queue<int> pq;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &s[i]);
            pq.push(-s[i]);
        }
        int valid = 0;
        while(!pq.empty()){
            int cur = -pq.top(); pq.pop();
            if(cur == 2048){
                valid = 1;
                break;
            }
            if(pq.empty())break;
            int next = -pq.top();
            if(cur == next){
                pq.pop();
                pq.push(-cur*2);
                if(cur*2 == 2048){
                    valid = 1;
                    break;
                }
            }
        }
        if(valid)printf("YES\n");
        else printf("NO\n");
    }
    
}