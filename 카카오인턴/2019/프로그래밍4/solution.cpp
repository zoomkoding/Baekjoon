#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> m;
long long find(long long x){
    long long temp = m.find(x) -> second;
    if(temp == m.end() -> second)return m[x] = x + 1;
    return m[x] = find(temp);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i = 0; i < room_number.size(); i++){
        long long x = room_number[i];
        answer.push_back(find(x) - 1);
    }
    return answer;
}