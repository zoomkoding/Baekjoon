#include <cstdio>
#include <vector>

using namespace std;

int t, a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        vector<vector<int> > arr(a+1, vector<int>(31, 0));
        arr[0][b - a + 1]++; 
        for(int i = 0; i < a; i++){
            for(int j = 0; j < 31; j++){
                if(arr[i][j] != 0){
                    for(int k = 1; k <= j; k++)arr[i+1][k] += arr[i][j];
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < 31; i++)sum += arr[a][i];
        printf("%d\n", sum);
    }
}