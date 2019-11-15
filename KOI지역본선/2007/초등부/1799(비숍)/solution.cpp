#include <cstdio>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, c, temp, arr[2][55], t[2], ans[2], no[11][11];
int d[4][2] = { {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
void find(int color, int index, int cnt){
    if(cnt > ans[color])ans[color] = cnt;
    //현재 상황에서 놓을 수 있는 애들 다 찾아주기
    for(int k = index; k < t[color]; k++){
        int x = arr[color][k] / 10, y = arr[color][k] % 10;
        if(no[x][y])continue;
        no[x][y]++;
        for(int i = 0; i < 4; i++){
            for(int j = 1; j < n; j++){
                int nx = x + d[i][0] * j, ny = y + d[i][1] * j;
                if(nx >= n || ny >= n || nx < 0 || ny < 0)break;
                no[nx][ny]++;
            }
        }
        find(color, k + 1, cnt + 1);
        no[x][y]--;
        for(int i = 0; i < 4; i++){
            for(int j = 1; j < n; j++){
                int nx = x + d[i][0] * j, ny = y + d[i][1] * j;
                if(nx >= n || ny >= n || nx < 0 || ny < 0)break;
                no[nx][ny]--;
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if(!(n % 2))c = !c;
        for(int j = 0; j < n; j++){
            scanf("%d", &temp);
            if(temp)arr[c][t[c]++] = i * 10 + j;
            c = !c;
        }
    }
    for(int i = 0; i < 2; i++)find(i, 0, 0);
    printf("%d", ans[0] + ans[1]);
}