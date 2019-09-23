#include <string>
#include <vector>

using namespace std;

int arr[102][102][2], n;
//기둥 0
int insert_gidung(int x, int y){
    if(arr[x][y][1]){
        arr[x][y][0] = 1;
        return 1;
    } 
    if(x - 1 >= 0 && arr[x - 1][y][1]){
        arr[x][y][0] = 1;
        return 1;
    }
    if(y == 0){
        arr[x][y][0] = 1;
        return 1;
    }
    if(y - 1 >= 0 && arr[x][y-1][0]){
        arr[x][y][0] = 1;
        return 1;
    }
    return 0;
}
//보 1
int insert_bo(int x, int y){
    if(y - 1 >= 0 && (arr[x][y - 1][0] || arr[x + 1][y - 1][0])){
        arr[x][y][1] = 1;
        return 1;
    } 
    if(arr[x + 1][y][1] && x - 1 >= 0 && arr[x - 1][y][1]){
        arr[x][y][1] = 1;
        return 1;
    }
    return 0;
}

int erase(int x, int y, int what){
    int result = 1;
    arr[x][y][what] = 0;
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            for(int k = 0; k < 2; k++){
                if(arr[i][j][k] == 1){
                    arr[i][j][k] = 0;
                    if(k == 0){
                        if(!insert_gidung(i, j))result = 0;
                    }
                    else {
                        if(!insert_bo(i, j))result = 0;
                    }
                    arr[i][j][k] = 1;
                }
            }
        }
    }
    if(!result) arr[x][y][what] = 1;
    return result;
}


//기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
//보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
//[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]	
vector<vector<int>> solution(int _n, vector<vector<int>> build_frame) {
    n = _n;
    vector<vector<int>> answer;
    for(int i = 0; i < build_frame.size(); i++){
        int what = build_frame[i][2];
        int how = build_frame[i][3];
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        //기둥 지을때
        if(how == 1 && what == 0)insert_gidung(x, y);
        else if(how == 1 && what == 1)insert_bo(x, y);
        else erase(x, y, what);
    }
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            for(int k = 0; k < 2; k++){
                if(arr[i][j][k] == 1){
                    vector<int> arr(3);
                    arr[0] = i, arr[1] = j, arr[2] = k;
                    answer.push_back(arr);
                }
            }
        }
    }
    return answer;
}