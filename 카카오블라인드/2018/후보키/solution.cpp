#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n, m, cnt;

int solution(vector<vector<string>> relation) {
    n = relation.size(), m = relation[0].size();
    queue<vector<int>> q;
    for(int i = 0; i < m; i++){
        vector<int> v;
        v.push_back(i);
        q.push(v);
    }

    while(!q.empty()){
        vector<int> front = q.front(); q.pop();
        int check = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = 0; k < front.size(); k++){
                    if(relation[i][front[k]].compare(relation[j][front[k]]) != 0) break;
                    if(k == front.size() - 1){
                        check = 1;
                        for(int i = 0; i < front.size(); i++){
                            cout << relation[i][front[k]] << " " << relation[j][front[k]] << endl;
                        }
                    }
                }
            }
        }
        if(check){
            cnt ++;
            for(int i = 0; i < front.size(); i++){
                printf("%d ", front[i]);
            }
            printf("\n");
        }
        else{
            for(int i = front[front.size()-1] + 1; i < m; i++){
                vector<int> v = front;
                v.push_back(i);
                q.push(v);
            }
        }
    }
    return cnt;
}