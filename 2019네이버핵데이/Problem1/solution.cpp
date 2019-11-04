#include <string>
#include <vector>
using namespace std;

int solution(vector<int> grade) {
    int answer = 0, n = grade.size();
    for(int i = 0; i < n; i++){
        int min = 101;
        for(int j = i + 1; j < n; j++){
            if(grade[j] < min)min = grade[j];
        }
        if(grade[i] > min)answer += grade[i] - min;
    }
    return answer;
}