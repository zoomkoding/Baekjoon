for(int i = 0; i < n; i++){
    //     int j = n - 1;
    //     while(j >= 0 && board[i][j] == 0)j--;
    //     for(int k = j; k > 0; k--){
    //         if(board[i][k] == 0)continue;
    //         if(board[i][k] == board[i][k-1]){
    //             board[i][k-1] += board[i][k-1];
    //             j--, k--;
    //         }
    //     }
    //     for(int k = n - 1; k >= 0; k--){
    //         if(j >= 0)board[i][k] = board[i][j];
    //         else board[i][k] = 0;
    //         j--;
    //     }
    // }