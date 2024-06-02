class Solution {
public:
    vector<vector<string>> result;
     int N;
    bool isValid(vector<string>& board, int row, int col) {
        // Check upward
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check left diagonal upward
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check right diagonal upward
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void solve(vector<string>&board,int row,int &count){
       if(row>=N){
           // result.push_back(board);
           count++;
           return; 
       }
        
        for(int col=0;col<N;col++){
            if(isValid(board,row,col)){
                board[row][col]='Q';
                solve(board,row+1,count);
                 board[row][col]='.';
                
            }
        }
    }
    int totalNQueens(int n) {
         N=n;
        vector<string>board(n,string(n,'.'));
        int count=0;
        solve(board,0,count); //row=0
        return count;
    }
};