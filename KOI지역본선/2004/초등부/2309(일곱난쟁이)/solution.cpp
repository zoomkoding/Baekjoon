#include <cstdio>
#include <algorithm>
using namespace std;
int arr[9], sum;
int main(){
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);   
        sum += arr[i];
    }
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(sum - arr[i] - arr[j] == 100){
                arr[i] = -1, arr[j] = -1;
                sort(arr, arr+9);
                for(int k = 2; k < 9; k++)printf("%d\n", arr[k]);
                return 0;
            }
        }
    }
}