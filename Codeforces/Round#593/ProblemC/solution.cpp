#include <cstdio>
#include <string>
#include <map>
using namespace std;
int d, m, k, n, v1, v2, x, y;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int main(){
    map<string, int> ob;
    map<string, int> visited;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &v1, &v2);
        ob.insert(make_pair(to_string(v1 - 1) + ',' + to_string(v2 - 1), 1));
    }
    int cnt = 0;
    while(1){
        // printf("현재 %d %d\n", x, y);
        cnt++;
        visited.insert(make_pair(to_string(x) + ',' + to_string(y), 1));
        //직진시 위치
        int tempx = x + dir[d][0], tempy = y + dir[d][1];
        //직진이 불가할 경우(벽에 부딪혔을 때, 장애물에 부딪혔을 때, 이미 방문한 점을 만났을 때)
        if(tempx >= n || tempy >= m || tempx < 0 || tempy < 0 || ob.find(to_string(tempx) + ',' + to_string(tempy)) != ob.end() || visited.find(to_string(tempx) + ',' + to_string(tempy)) != visited.end()){
            d = (d + 1) % 4;
            tempx = x + dir[d][0], tempy = y + dir[d][1];
            //돌렸는데도 불가한 경우
            if(tempx >= n || tempy >= m || tempx < 0 || tempy < 0 || ob.find(to_string(tempx) + ',' + to_string(tempy)) != ob.end() || visited.find(to_string(tempx) + ',' + to_string(tempy)) != visited.end())break;
            //돌려서 가능하면 달려
            else x = tempx, y = tempy;
        }
        //직진이 가능한 경우는 그냥 달려
        else x = tempx, y = tempy;
    }
    // printf("%d", cnt);
    if(cnt == n * m - k)printf("Yes");
    else printf("No");
}