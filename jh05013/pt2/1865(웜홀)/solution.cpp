#include <cstdio>
#define INF 987654321

using namespace std;

int main(){
    int tc, n, m, w, t, e[6000][3], dist[501], before[501];
    scanf("%d", &tc);
    while(tc--){
        int yes = 0;
        scanf("%d %d %d", &n, &m, &w);
        for(int i = 0; i < m; i++) scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
        for(int i = m; i < 2*m; i++) e[i][0] = e[i-m][1], e[i][1] = e[i-m][0], e[i][2] = e[i-m][2];
        for(int i = 2*m; i < 2*m + w; i++){
            scanf("%d %d %d", &e[i][0], &e[i][1], &t);
            e[i][2] = -t;
        }
        for(int i = 1; i < n + 1; i++) dist[i] = INF;
        dist[1] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < (2*m + w); j++){
                if(dist[e[j][0]] == INF) continue;
                if(dist[e[j][1]] > dist[e[j][0]] + e[j][2]) dist[e[j][1]] = dist[e[j][0]] + e[j][2];
            }
        }
        //확인하기 전에 모든 경로 저장하기
        for(int i = 1; i < n + 1; i++) before[i] = dist[i];
        for(int i = 0; i < (2 * m + w); i++){
            if(dist[e[i][0]] == INF) continue;
            if(dist[e[i][1]] > dist[e[i][0]] + e[i][2]) dist[e[i][1]] = dist[e[i][0]] + e[i][2];
        }
        for(int i = 1; i < n + 1; i++){
            if(dist[i] != before[i]) {
                yes = 1;
                break;
            }
        }
        if(yes) printf("YES\n");
        else printf("NO\n");
    }
}