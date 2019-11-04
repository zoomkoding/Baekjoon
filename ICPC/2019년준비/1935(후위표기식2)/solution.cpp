#include <cstdio>
#include <stack>
using namespace std;
int arr[101], n, cnt;
char s[101];
int main(){
    scanf("%d", &n);
    scanf("%s", s);
    stack<double> st;
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        if(c <= 'Z' && c >= 'A')st.push(arr[c-'A']);
        else {
            double y = st.top(); st.pop();
            double x = st.top(); st.pop();
            if(c == '*')st.push(x*y);
            else if(c == '+')st.push(x+y);
            else if(c == '-')st.push(x-y);
            else st.push(x/y);
        }
    }
    printf("%.2f", st.top());
}