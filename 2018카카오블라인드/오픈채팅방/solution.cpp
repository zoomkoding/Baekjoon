#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int cnt = 0;
    vector<vector<string>> v(record.size(), vector<string>(2));
    map<string, string> m;
    
    for(int i = 0; i < record.size(); i++){
        int space[2], k = 0;
        for(int j = 0; j < record[i].length(); j++){
            if(record[i][j] == ' '){
                space[0] = j;
                break;
            }
        }
        string command = record[i].substr(0, space[0]);
        string uid;
        if(command.compare("Leave") == 0)uid = record[i].substr(space[0] + 1, record[i].length() - space[0] - 1);
        else {
            for(int j = space[0] + 1; j < record[i].length(); j++){
                if(record[i][j] == ' '){
                    space[1] = j;
                    break;
                }
            }
            uid = record[i].substr(space[0] + 1, space[1] - space[0] - 1);
        }

        if(command.compare("Change") != 0) v[cnt][0] = command, v[cnt][1] = uid, cnt++;
        if(command.compare("Leave") != 0){
            string name = record[i].substr(space[1] + 1, record[i].length() - space[1] - 1);
            m[uid] = name;
        }
        
    }
    for(int i = 0; i < cnt; i++){
        if(v[i][0].compare("Enter") == 0)answer.push_back(m[v[i][1]] + "님이 들어왔습니다.");
        else answer.push_back(m[v[i][1]] + "님이 나갔습니다.");
        // cout << answer[i] << endl;
    }
    
    return answer;
}