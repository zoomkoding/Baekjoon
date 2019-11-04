#include <string>
#include <vector>
using namespace std;
int check[100][100], cnt[100], M, sum;
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size(), m = maps[0].length();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char cur = maps[i][j];
            if(cur == '.')continue;
            for(int k = 0; k < 4; k++){
                int nx = i + d[k][0], ny = j + d[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                char next = maps[nx][ny];
                if(next == '.' || next == cur)continue;
                if(check[cur-'A'][next-'A'])continue;
                check[cur-'A'][next-'A'] = 1, cnt[cur-'A'] ++;
            }
        }
    }
    for(int i = 0; i < 'Z' - 'A' + 1; i++){
        sum += cnt[i];
        if(cnt[i] > M)M = cnt[i];
    }
    //서로 인접하다고 할꺼기 때문에 나누기 2 해줘야해
    answer.push_back(sum/2);
    answer.push_back(M);
    return answer;
}