#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int w, n;
int main(){
    scanf("%d %d", &w, &n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = arr[i];
        if(sum >= w)continue;
        for(int j = i + 1; j < n; j++){
            sum += arr[j];
            if(sum >= w){
                sum -= arr[j];
                continue;
            }
            for(int k = j + 1; k < n; k++){
                sum += arr[k];
                if(sum >= w){
                    sum -= arr[k];
                    continue;
                }
                for(int l = k + 1; l < n; l++){
                    sum += arr[l];
                    if(sum == w){
                        printf("YES");
                        return 0;
                    }
                    sum -= arr[l];
                }
                sum -= arr[k];
            }
            sum -= arr[j];
        }
    }
    printf("NO");
}