#include <string>
#include <vector>

using namespace std;
int arr[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < arr1.size(); i++){
        for(int j = n - 1; j >= 0; j--){
            if(arr1[i] == 0)break;
            arr[i][j] += arr1[i] % 2;
            arr1[i] /= 2;
        }
    }
    
    for(int i = 0; i < arr2.size(); i++){
        for(int j = n - 1; j >= 0; j--){
            if(arr2[i] == 0)break;
            arr[i][j] += arr2[i] % 2;
            arr2[i] /= 2;
        }
    }
    for(int i = 0; i < n; i++){
        string s = "";
        for(int j = 0; j < n; j++){
            if(arr[i][j])s+= '#';
            else s += ' ';
        }
        answer.push_back(s);
    }
    return answer;
}