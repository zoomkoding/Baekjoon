#include <string>
#include <vector>
#include <map>
using namespace std;
int n;
string cache[31];


int solution(int cacheSize, vector<string> cities) {
    map<string, int> cnt;
    int answer = 0;
    for(int i = 0; i < cities.size(); i++){
        for(int j = 0; j < cities[i].length(); j++){
            if(cities[i][j] >= 'a')cities[i][j] = cities[i][j] - 'a' + 'A';
        }
    }

    for(int i = 0; i < cities.size(); i++){
        int exist = 0;
        for(int j = 0; j < n; j++){
            if(cache[j].compare(cities[i]) == 0){
                cnt[cities[i]] = i;
                exist = 1;
                break;
            }
        }
        if(exist) answer += 1;
        else {
            answer += 5;
            if(n < cacheSize){
                cache[n++] = cities[i];
                cnt[cities[i]] = i;
            }
            else{
                int del = 0;
                for(int j = 0; j < n; j++){
                    if(cnt[cache[j]] < cnt[cache[del]]) del = j;
                }
                cache[del] = cities[i];
                cnt[cities[i]] = i;
            }
        }

    }
    return answer;
}