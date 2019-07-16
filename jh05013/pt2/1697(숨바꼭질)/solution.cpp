#include <cstdio>
#include <queue>

using namespace std;

int arr[500000];
int cand[3];
int n, k, x, c;

int main(){
    queue<int> q;
    scanf("%d %d", &n, &k);
    q.push(n);
    if(n == k) {
        printf("0");
        return 0;
    }
    while(!q.empty()){
        x = q.front(); q.pop();
        c = arr[x];
        cand[0] = x - 1, cand[1] = x + 1, cand[2] = 2 * x;
        for(int i = 0; i < 3; i++){
            int current = cand[i];
            if(current == k){
                printf("%d", c + 1);
                return 0;
            }
            if(current <= 0 || current > 500000)continue;
            if(arr[current] == 0){
                arr[current] = c + 1;
                q.push(current);
            }
            
        }
    }
}