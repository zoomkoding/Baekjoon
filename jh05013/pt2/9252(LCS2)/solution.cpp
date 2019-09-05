#include <iostream>
#include <string>
#include <vector>
using namespace std;
int ans, n, arr[1001][1001], pos1[1001], pos2[1001];
string s1, s2;

int main(){
    cin >> s1 >> s2;
    n = s1.length();
    for(int i = 0; i < n; i++){
        char c = s1[i];
        int val = n;
        for(int j = 0; j < n; j++){
            if(s2[j] == c){
                val = j; break;
            }
        }
        arr[0][i] = val;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++)arr[i][j] = n;
        for(int j = i; j < n; j++){
            int prev = n;
            char c = s1[j];
            for(int k = 0; k < j; k++){
                if(arr[i-1][k] < prev)prev = arr[i-1][k];
            }
            int val = n;
            for(int k = prev + 1; k < n; k++){
                if(s2[k] == c){
                    ans = i + 1, val = k; break;
                }
            }
            arr[i][j] = val;
        }
    }
    pos1[ans] = n, pos2[ans] = n;
    for(int i = ans - 1; i >= 0; i--){
        pos2[i] = -1;
        for(int j = 0; j < pos1[i+1]; j++){
            if(arr[i][j] == n)continue;
            if(pos2[i+1] <= arr[i][j])continue;
            if(pos2[i] < arr[i][j])pos1[i] = j, pos2[i] = arr[i][j];
        }
    }
    cout << ans << '\n';
    for(int i = 0; i < ans; i++)cout << s1[pos1[i]];
}