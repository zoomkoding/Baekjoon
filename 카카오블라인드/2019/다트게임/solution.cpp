#include <string>

using namespace std;
int score[3], ptr = -1;
//점수, 보너스, 옵션
int solution(string dr) {
    int answer = 0;
    for(int i = 0; i < dr.length(); i++){
        if(dr[i] == '1'){
            ptr ++;
            if(dr[i + 1] == '0'){
                score[ptr] = 10;
                i++;
            }
            else score[ptr] = 1;
        }
        else if(dr[i] >= '0' && dr[i] <= '9'){
            ptr++;
            score[ptr] = dr[i] - '0';
        }
        else if(dr[i] == 'D')score[ptr] = score[ptr] * score[ptr];
        else if(dr[i] == 'T')score[ptr] = score[ptr] * score[ptr] * score[ptr];
        else if(dr[i] == '*'){
            if(ptr == 0)score[ptr] = score[ptr]*2;
            else score[ptr] = score[ptr]*2, score[ptr-1] = score[ptr-1]*2;
        }
        else if(dr[i] == '#'){
            score[ptr] = -score[ptr];
        } 
        printf("%d %d %d\n", score[0], score[1], score[2]);
        answer = score[0] + score[1] + score[2];
    }
    return answer;
}