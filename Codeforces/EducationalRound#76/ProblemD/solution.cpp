#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int t, n, arr[200001], m, ps[200001], tm, p, s;

int main(){
    scanf("%d", &t);
    while(t--){
        //maxp은 최대힘
        int maxp = 0, ans = 1;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
        scanf("%d", &m);

        //ps[i]는 하루에 i까지 상대할때 쓸 수 있는 최대힘
        for(int i = 0; i < m; i++){
            scanf("%d %d", &p, &s);
            if(p > ps[tm + s])ps[tm + s] = p;
            if(s > maxp)maxp = s;
        }

        //PREFIX SUM
        for(int i =  tm + maxp - 1; i >= tm; i --){
            if(ps[i] < ps[i + 1])ps[i] = ps[i + 1];
        }

        //하루 최대치를 찾는 중...
        int M = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            cnt++;
            if(M < arr[i])M = arr[i];
            if(ps[tm + cnt] >= M)continue;
            else {
                if(cnt == 1){
                    ans = -1;
                    break;
                }
                cnt = 0, M = 0, i--;
                ans ++;
            }
        }
        printf("%d\n", ans);
        
        //어레이 초기화에 필요한 시간을 줄이기 위해 어레이의 남은 부분을 사용하기로했다.
        //tm = 바로 이전 테스트 케이스까지 해서 사용한 어레이 index 
        tm += maxp + 1;
    }
}