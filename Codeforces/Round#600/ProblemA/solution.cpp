#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
int k, n, a[100001], b[100001];
int main(){
    scanf("%d", &k);
    while(k--){
        int dif = 0, valid = 1, start = 0, end = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)scanf("%d", &b[i]);
        for(int i = 0; i < n; i++){
            if(start == 0 && dif != a[i] - b[i]){
                start = 1;
                dif = a[i] - b[i];
                if(dif > 0){
                    valid = 0;
                    break;
                }
            }
            else if(start == 1 && a[i] - b[i] == 0){
                end = 1;
                dif = 0;
            }
            else if(start == 1 && a[i] - b[i] != dif){
                valid = 0;
                break;
            }
        }
        if(valid)printf("YES\n");
        else printf("NO\n");
    }
}