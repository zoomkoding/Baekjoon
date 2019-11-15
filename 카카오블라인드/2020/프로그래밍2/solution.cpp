#include <string>
#include <vector>
#include <stack>
#define pii pair<int, int>
using namespace std;

string p;
int n;
pii correct(int begin, int end){
    stack<int> s; 
    int result = 1;
    int o = 0, x = 0;
    for(int i = begin; i <= end; i++){
        if(p[i] == ')') {
            o++;
            if(s.empty()) result = 0;
            else s.pop();
        }
        else {
            s.push(1); x++;
        }
        if(o == x) return pii(i, result);
    }
    return pii(begin, 1);
}

string whatever(int begin, int end){
    string result = "";
    if(begin == end) return "";
    pii r = correct(begin, end);
    int x1 = begin, y1 = r.first, x2 = r.first + 1, y2 = end;
    string s2 = "";
    if(x2 >= n || y2 >= n)s2 = "";
    else s2 = whatever(x2, y2);
    if(r.second)return p.substr(x1, y1 - x1 + 1) + s2;
    result = "(" + s2 + ")";
    for(int i = x1 + 1; i <= y1 - 1; i++){
        if(p[i] == '(') result += ")";
        else result += "(";
    }
    return result;
}

string solution(string _p) {
    p = _p, n = p.length();
    return whatever(0, n-1);
}