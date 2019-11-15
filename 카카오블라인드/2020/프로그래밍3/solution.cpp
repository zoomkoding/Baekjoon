#include <string>
#include <vector>
using namespace std;
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int keys[4][21][21], m = key.size(), n = lock.size(), locks = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            keys[0][i][j] = key[i][j];
            keys[1][i][j] = key[m - j - 1][i];
            keys[2][i][j] = key[m - i - 1][m - j - 1];
            keys[3][i][j] = key[j][m - i - 1];
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(lock[x][y] == 0) locks++;
        }
    }
    if(locks == 0)return true;
    for(int x = - m; x < n; x++){
        for(int y = - m; y < n; y++){
            for(int k = 0; k < 4; k++){
                int cnt = 0, wrong = 0;
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < m; j++){
                        if(x + i < 0 || y + j < 0 || x + i >= n || y + j >= n) continue;
                        if(keys[k][i][j] == 1 && lock[x + i][y + j] == 0)cnt ++;
                        else if(keys[k][i][j] == 1 && lock[x + i][y + j] == 1){
                            wrong = 1;
                            break;
                        }
                    }
                    if(wrong)break;
                }
                if(cnt == locks && !wrong) return true;
            }
        }
    }
    return false;
}