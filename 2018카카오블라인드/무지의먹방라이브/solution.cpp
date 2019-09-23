#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int pos = -1, n = food_times.size();
    while(k >= 0){
        int t = -1;
        for(int i = 1; i < n; i++){
            if(food_times[(pos + i)%n] != 0){
                t = (pos + i)%n;
                break;
            }
        }
        if(t == -1)return -1;
        pos = t;
        food_times[pos]--;
        k--;
    }
    
    return pos + 1;
}