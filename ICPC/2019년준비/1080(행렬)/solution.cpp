#include <cstdio>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n, m, cnt, arr[2][51][51];
int main(){
    scanf("%d %d", &n, &m);
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)scanf("%1d", &arr[k][i][j]);
        }
    }
    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < m - 2; j++){
            if(arr[0][i][j] == arr[1][i][j])continue;
            cnt++;
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    arr[0][i+k][j+l] = !arr[0][i+k][j+l];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[0][i][j] != arr[1][i][j]){
                cnt = -1;
                break;
            }
        }
    }
    printf("%d", cnt); 
}
