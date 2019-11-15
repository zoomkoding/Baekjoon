#include <string>
#include <vector>
#include <cstring>

using namespace std;
int arr[10], dp[9][1 << 9], N, check[1 << 9];
vector<int> v[9];
//x는 ban 인덱스, y는 현재 상태
int find(int x, int y){
    if(x == N){
        if(check[y])return 0;
        else {
            check[y] = 1;
            return 1;
        }
    }
    int temp = 0;
    for(int i = 0; i < v[x].size(); i++){
        int cur = v[x][i];
        int toadd = 1 << cur;
        int sum = toadd | y;
        if(sum == y)continue;
        temp += find(x + 1, sum);
    }
    return temp;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    N = banned_id.size();
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < banned_id.size(); i++){
        int n = banned_id[i].length();
        for(int j = 0; j < user_id.size(); j++){
            if(n != user_id[j].length())continue;
            int valid = 1;
            for(int k = 0; k < user_id[j].length(); k++){
                if(banned_id[i][k] == '*')continue;
                if(banned_id[i][k] == user_id[j][k])continue;
                valid = 0;
                break;
            }
            if(valid)v[i].push_back(j + 1);
        }
    }
    answer = find(0, 0);
    return answer;
}