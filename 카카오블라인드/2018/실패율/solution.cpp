#include <vector>
#include <algorithm>
using namespace std;

float failrate[200002];
int onstage[200002];

bool compare(int i, int j){ 
    if(failrate[i] == failrate[j]) return i < j;
    return float(failrate[i]) > float(failrate[j]); 
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(int i = 0; i < stages.size(); i++)onstage[stages[i]]++;
    for(int i = N + 1; i > 0; i --){
        int temp =  onstage[i];
        onstage[i] += onstage[i+1];
        if(!onstage[i])failrate[i] = 0;
        else failrate[i] = float(float(temp) / float(onstage[i]));
    }
    for(int i = 0; i < N; i++)answer.push_back(i+1);
    
    sort(answer.begin(), answer.end(), compare);
    return answer;
}