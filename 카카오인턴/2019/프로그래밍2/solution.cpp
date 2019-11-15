#include <string>
#include <vector>

using namespace std;
int arr[100001];
vector<vector<int>> v;
vector<int> solution(string s) {
    vector<int> answer;
    int num = 0;
    int finish = 1;
    int index = -1;
    for(int i = 1; i < s.length() - 1; i++){
        if(s[i] == '{'){
            index ++;
            finish = 0;
            v.push_back(vector<int>());
        }
        else if(s[i] == '}'){
            finish = 1;
            v[index].push_back(num);
            num = 0;
        }
        else if(s[i] == ','){
            if(finish)continue;
            else {
                v[index].push_back(num);
                num = 0;
            }
        }
        else num = num * 10 + s[i] - '0';
    }
    for(int i = 1; i <= v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(v[j].size() == i){
                for(int k = 0; k < v[j].size(); k++){
                    int temp = v[j][k];
                    if(arr[temp])continue;
                    arr[temp] = 1;
                    answer.push_back(temp);
                }
            }
        }
    }
    return answer;
}