#include <string>
#include <vector>

using namespace std;
int dp[1001], t, s;
int solution(string command, vector<string> buttons, vector<int> scores) {
    int n = command.length(), m = buttons.size();
    for(int i = 0; i < n; i++){
        //이전값에서 하나 더한게 일단 최대값으로 설정
        if(i == 0)dp[i] = 1;
        else dp[i] = dp[i - 1] + 1;

        //스킬 사용시 점수 최대값을 구하는 중
        for(int j = 0; j < m; j++){
            t = buttons[j].length();
            s = i - t + 1;
            if(s < 0)continue;
            int valid = 1;
            for(int k = 0; k < t; k++){
                if(command[s + k] != buttons[j][k]){
                    valid = 0;
                    break;
                }
            }
            if(valid){
                //스킬 쓰기 전 위치가 0보다 작으면 그냥 스킬 쓴 값으로 업데이트
                if(s - 1 < 0){
                    if(dp[i] < scores[j])dp[i] = scores[j];
                }
                //스킬 쓰기 전 위치가 0보다 크거나 같다면 스킬 값과 그 전 위치의 dp값으로 업데이트
                else {
                    if(dp[i] < dp[s - 1] + scores[j])dp[i] = dp[s - 1] + scores[j];
                }
            }
        }
    }
    return dp[n - 1];
}
