#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int n, t, temp, num[11], arr[10001];
int main(){
    scanf("%d", &t);
    while(t--){
        int ans = 0;
        vector<int> nums;
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            arr[num[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(arr[num[i]] == 1){
                nums.push_back(num[i]);
                continue;
            }
            ans ++;
            int x = num[i] % 1000, y = num[i] - x / 100 * 100, z = num[i] - num[i] % 10;
            for(int j = 0; j < 10; j++){
                int temp[3];
                temp[0] = x + j * 1000, temp[1] = y + j * 100, temp[2] = z + j;
                for(int k = 0; k < 3; k++){
                    if(!arr[temp[k]]){
                        arr[temp[k]] ++;
                        nums.push_back(temp[k]);
                        break;
                    }
                }
            }
            arr[num[i]]--;
        }
        printf("%d\n", ans);
        for(int i = 0; i < n; i++){
            if(nums[i] / 10 == 0)printf("000");
            else if(nums[i] / 100 == 0)printf("00");
            else if(nums[i] / 1000 == 0)printf("0");
            printf("%d\n", nums[i]);
        }

    }
}