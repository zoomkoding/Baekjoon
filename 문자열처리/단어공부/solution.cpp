#include <iostream>
#include <string>

using namespace std;
int arr[30], MAX, MAX_i, MAX_C;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int temp =  s[i] <= 'Z' ? s[i] - 'A' : s[i] - 'a';
        arr[temp] ++;
        if(arr[temp] > MAX)MAX_i = temp, MAX = arr[temp], MAX_C = 0;
        else if(arr[temp] == MAX)MAX_C = 1;
    }
    if(MAX_C)cout << '?';
    else cout << char(MAX_i + 'A');
}