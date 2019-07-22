#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;
int n, front = 50000, back = 50000, arr[100000];
string c; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c.compare("push_back") == 0) cin >> arr[back++];
        
        else if(c.compare("push_front") == 0) cin >> arr[--front];
        
        else if(c.compare("pop_front") == 0){
            if(front != back) cout << arr[front++] << '\n';
            else cout << "-1" << '\n';
        }
        else if(c.compare("pop_back") == 0){
            if(front != back) cout << arr[--back] << '\n';
            else cout << "-1" << '\n';
        }
        else if(c.compare("size") == 0){
            cout << back - front <<'\n';
        }
        else if(c.compare("empty") == 0){
            if(back == front) cout << "1" << '\n';
            else cout << "0" << '\n';
        }
        else if(c.compare("front") == 0){
            if(front != back) cout << arr[front] << '\n';
            else cout << "-1" << '\n';
        }
        else if(c.compare("back") == 0){
            if(back != front)cout << arr[back-1] << '\n';
            else cout << "-1" << '\n';
        } 
    }
}