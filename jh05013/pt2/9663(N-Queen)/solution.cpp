#include <cstdio>
int n, cnt, arr[14][14];
int d[4][2] = { {1, -1}, {1, 1}, {-1, 1}, {-1, -1} };

void find(int x, int y, int q){
    printf("%d\n", q);
    if(q == n){
        cnt ++;
        return;
    }
    for(int i = x; i < n; i++){
        for(int j = y; j < n; j++){
            if(arr[i][j] == 0){
                for(int k = 0; k < n; k++){
                    arr[i][k] ++;
                    arr[k][j] ++;
                }
                for(int p = 0; p < 4; p++){
                    int t = 1;
                    while(1){
                        if(i + d[p][0]*t >= n || j + d[p][1]*t >= n || i + d[p][0]*t < 0 || j + d[p][1]*t < 0) break;
                        arr[i + d[p][0]*t][j + d[p][1]*t] ++;
                        t ++;
                    }
                }
                find(i, j, q+1);
                for(int k = 0; k < n; k++){
                    arr[i][k] --;
                    arr[k][j] --;
                }
                for(int p = 0; p < 4; p++){
                    int t = 1;
                    while(1){
                        if(i + d[p][0]*t >= n || j + d[p][1]*t >= n || i + d[p][0]*t < 0 || j + d[p][1]*t < 0) break;
                        arr[i + d[p][0]*t][j + d[p][1]*t] --;
                        t ++;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    find(0, 0, 0);
    printf("%d", cnt);
}

