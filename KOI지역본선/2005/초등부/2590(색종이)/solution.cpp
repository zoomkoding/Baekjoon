#include <cstdio>
int p[7], q[601][7][7], sum; 
int valid(int t, int x, int y, int cnt){
    if(q[t][x][y] != 0 || x + cnt > 7 || y + cnt > 7)return 0;
    for(int i = x; i < x + cnt; i++){
        for(int j = y; j < y + cnt; j++){
            if(q[t][i][j] != 0)return 0;
        }
    }
    for(int i = x; i < x + cnt; i++){
        for(int j = y; j < y + cnt; j++)q[t][i][j] = cnt;
    }
    return 1;
}

int find(int x){
    if(sum == 0)return x - 1;
    for(int i = 1; i < 7; i++){
        for(int j = 1; j < 7; j++){
            for(int k = 6; k >= 1; k--){
                if(!p[k])continue;
                if(!valid(x, i, j, k))continue;
                p[k]--, sum--;
                if(sum == 0)return x;
            }
        }
    }
    return find(x + 1);
}

int main(){
    for(int i = 1; i < 7; i++){
        scanf("%d", &p[i]);
        sum += p[i];
    }
    printf("%d\n", find(1));
}