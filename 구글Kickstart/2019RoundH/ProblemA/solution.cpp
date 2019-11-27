#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
int t, n, arr[100001], cnt[100001];
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        printf("Case #%d: ", k);
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            for(int j = 1; j <= arr[i]; j++)cnt[j]++;
            for(int j = 1; j < 100001; j++){
                if(j > cnt[j]){
                    printf("%d ", j - 1);
                    break;
                }
            }
        }
        printf("\n");
    }
}