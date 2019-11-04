#include <cstdio>
#include <queue>
using namespace std;
int nxt, n, src, dst, arr[10001], c[4], t[4] = {1000, 100, 10, 1};
int main(){
    scanf("%d", &n);
    for(int i = 2; i < 10001; i++){
        if(arr[i])continue;
        for(int j = i*2; j < 10001; j+=i)arr[j] = 1;
    }
    while(n--){
        scanf("%d %d", &src, &dst);
        int cnt[10001] = {0,};
        queue<int> q;
        q.push(src);
        cnt[src] = 1;
        while(!q.empty()){
            int front = q.front(), fc = cnt[front], temp = front; 
            q.pop();
            for(int i = 0; i < 4; i++) c[i] = temp / t[i], temp -= c[i] * t[i];
            for(int i = 0; i < 4; i++){
                front -= c[i] * t[i];
                for(int j = 0; j < 10; j++){
                    if(i == 0 && j == 0)continue;
                    nxt = front + j * t[i];
                    if(cnt[nxt] || arr[nxt])continue;
                    cnt[nxt] = fc + 1;
                    if(nxt == dst)break;
                    q.push(nxt);
                }
                if(nxt == dst)break;
                front += c[i] * t[i];
            }
            if(nxt == dst)break;
        }
        if(cnt[dst] == 0)printf("Impossible\n");
        else printf("%d\n", cnt[dst] - 1);
    }
    
}