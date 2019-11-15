#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size(), m = moves.size();
    vector<queue<int>> q(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0)continue;
            q[j + 1].push(board[i][j]);
        }
    }
    stack<int> st;
    for(int i = 0; i < m; i++){
        int slot = moves[i];
        if(!q[slot].empty()){
            int item = q[slot].front(); q[slot].pop();
            if(st.empty()){
                st.push(item);
            }
            else{
                if(st.top() == item){
                    st.pop();
                    answer += 2;
                }
                else st.push(item);
            }
        }
    }
    return answer;

}