#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int pos = 0;
bool compare(string a, string b){
    return a[pos] < b[pos];
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i = 0; i < queries.size(); i++){
        // printf("%d번째\n", i);
        int cnt = -1;
        int qn = queries[i].length();
        vector<string> word;
        for(int j = 0; j < words.size(); j++){
            if(qn == words[j].length())word.push_back(words[j]);
        }
        // printf("%zu\n", word.size());

        int begin = 0, end = word.size()-1;
        if(end == 0){
            answer.push_back(1);
            continue;
        }
        if(end == -1){
            answer.push_back(0);
            continue;
        }
        for(int k = 0; k < qn; k++){
            int b, e;
            char c = queries[i][k];
            // printf("현재 c = %c\n", c);
            pos = k;
            if(c == '?')continue;
            sort(word.begin()+begin, word.begin()+end+1, compare);
            int f1 = 0, f2 = 0;
            // printf("%d %d\n", begin, end);
            for(int j = begin; j <= end; j++){
                // printf("비교 c = %c\n", word[j][k]);
                if(c == word[j][k]){
                    if(!f1) b = j, f1 = 1;
                    else f2 = 1, e = j;
                }
            }
            if(!f1){
                cnt = 0;
                break;
            }
            else if(!f2){
                cnt = 1;
                break;
            }
            begin = b, end = e;
        }
        if(cnt == -1)cnt = end - begin + 1;
        answer.push_back(cnt);
    }
    return answer;
}