#include <cstdio>
#include <algorithm>
using namespace std;
int q, n, arr[101];
int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        int team[101] = {0,};
        for(int i = 0 ; i < n; i++)scanf("%d", &arr[i]);
        sort(arr, arr + n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!team[j] || arr[i] - team[j] != 1){
                    team[j] = arr[i];
                    break;
                }
            }
        }
        for(int i = 0; i <= n; i++){
            if(team[i] == 0){
                printf("%d\n", i);
                break;
            }
        }
    }
}