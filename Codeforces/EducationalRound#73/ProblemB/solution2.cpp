#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t;

int main(){
    cin >> t;
    while(t--){
        int valid = 1, n;
        char s1[52], s2[52];
        cin >> n >> s1 >> s2 ;
        vector<int> mx, my;
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i])continue;
            else {
                int find = 0;
                for(int j = i + 1; j < n; j++){
                    if(s2[i] == s2[j]){
                        mx.push_back(i), my.push_back(j);
                        swap(s1[i], s2[j]);
                        find = 1;
                        break;
                    }
                }
                if(find)continue;
                for(int j = i + 1; j < n; j++){
                    if(s2[i] == s1[j]){
                        mx.push_back(i), my.push_back(i);
                        swap(s1[i], s2[i]);
                        mx.push_back(j), my.push_back(i);
                        swap(s1[j], s2[i]);
                        find = 1;
                        break;
                    }
                }
                if(!find){
                    valid = 0;
                    break;
                }
            }
        }
        if(!valid){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << mx.size() << '\n';
        for(int i = 0; i < mx.size(); i++){
            cout << mx[i] + 1 << ' ' << my[i] + 1 << '\n';
        }
    }
}