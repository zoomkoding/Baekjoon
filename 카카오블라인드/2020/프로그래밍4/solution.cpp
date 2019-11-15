#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    int qc = queries.size();
    vector<int> answer(qc);
    for(int i = 0; i < qc; i++){
        int asum = 0;
        int cnt = 0;
        string q = queries[i];
        int qn = q.length(), wc = words.size();
        int begin, end;
        if(q[0] == '?'){
            end = qn - 1;
            for(int j = 0; j < qn; j ++){
                if(q[j] != '?'){
                    begin = j;
                    break;
                }
            }
        }
        else {
            begin = 0;
            for(int j = qn - 1; j >= 0; j--){
                if(q[j] != '?'){
                    end = j;
                    break;
                }
            }
        }
        for(int j = begin; j <= end; j++){
            asum += q[j];
        }
        
        for(int j = 0; j < wc; j++){
            int bsum = 0;
            string word = words[j];
            int wn = word.length();
            if(qn!=wn)continue;
            for(int k = begin; k <= end; k++){
                bsum += word[k];
            }
            if(bsum != asum)continue;
            int same = 1;
            for(int k = begin; k <= end; k++){
                if(q[k] != word[k]){
                    same = 0;
                    break;
                }
            }
            if(same) cnt ++;
        }
        answer[i] = cnt;
    }
    return answer;
}