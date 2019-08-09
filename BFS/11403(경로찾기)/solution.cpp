#include <cstdio>
#include <queue>
using namespace std;
int n, arr[100][100], visited[100];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)scanf("%d", &arr[i][j]);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][k] && arr[k][j]) arr[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)printf("%d ", arr[i][j]);
        printf("\n");
    }

}