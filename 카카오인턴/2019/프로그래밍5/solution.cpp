#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    long long l = 0, r = 10000000000;
    while(l <= r){
        long long mid = (l + r) / 2;
        int cnt = 0;
        int valid = 1;
        for(int i = 0; i < stones.size(); i++){
            if(stones[i] - mid > 0)cnt = 0;
            else{
                cnt++;
                if(cnt >= k){
                    valid = 0;
                    break;
                }
            } 
        }
        if(valid){
            l = mid + 1;
            answer = mid;
        }
        else r = mid - 1;
    }
    return answer + 1;
}