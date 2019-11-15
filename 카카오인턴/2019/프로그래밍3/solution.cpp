#include <string>
#include <vector>

using namespace std;
int arr[10];
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
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
            if(valid)arr[i]++;
        }
    }
    
    for(int i = 0; i < banned_id.size(); i++){
        if(!arr[i])continue;
        if(answer == 0)answer = arr[i];
        else answer *= arr[i];
    }
    return answer;
}