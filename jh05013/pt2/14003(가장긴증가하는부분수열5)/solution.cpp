#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, arr[1000001], p[1000001], cnt;
vector<int> ans, print;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    ans.push_back(arr[1]);
    for(int i = 2; i <= n; i++){
        if(ans[cnt] < arr[i]){
            ans.push_back(arr[i]), cnt++;
            p[i] = cnt;
        }
        else{
            int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[pos] = arr[i];
            p[i] = pos;
        } 
    }

    printf("%d\n", cnt + 1);
    for(int i = n; i >= 1 && cnt >= 0; i--){
        if(p[i] == cnt){
            print.push_back(arr[i]);
            cnt--;
        }
    }
    for(int i = print.size() - 1; i >= 0; i--){
        printf("%d ", print[i]);
    }
}
