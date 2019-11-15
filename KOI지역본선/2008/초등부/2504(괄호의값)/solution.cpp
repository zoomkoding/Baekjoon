#include <cstdio>
#include <stack>
using namespace std;
char s[31];
stack<int> st;
int main(){
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        if(c == '(')st.push(-1);
        else if(c == '[')st.push(-2);
        else if(c == ')'){
            int sum = 0;
            while(1){
                if(st.empty()){
                    printf("0");
                    return 0;
                }
                int top = st.top(); st.pop();
                if(top == -2){
                    printf("0");
                    return 0;
                }
                else if(top != -1)sum += top;
                else break;
            }
            if(sum == 0)st.push(2);
            else st.push(sum * 2);
        }
        else{
            int sum = 0;
            while(1){
                if(st.empty()){
                    printf("0");
                    return 0;
                }
                int top = st.top(); st.pop();
                if(top == -1){
                    printf("0");
                    return 0;
                }
                else if(top != -2)sum += top;
                else break;
            }
            if(sum == 0)st.push(3);
            else st.push(sum * 3);
        }
    }
    int ans = 0;
    while(!st.empty()){
        if(st.top() < 0){
            ans = 0;
            break;
        }
        ans += st.top();
        st.pop();
    }
    printf("%d", ans);
}