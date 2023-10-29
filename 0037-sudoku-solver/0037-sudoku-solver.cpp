#include <vector>
#include <cmath>

class Solution {
public:
    bool notClash(int i, int j, vector<vector<char>>& board, char num, int n) {
        for (int k = 0; k < n; k++) {
            // Row check
            if (board[i][k] == num)
                return false;
            // Column check
            if (board[k][j] == num)
                return false;
        }
        
        // Check in the small 3x3 matrix
        int s = sqrt(n);
        int startRow = i - i % s;
        int startCol = j - j % s;
        
        for (int r = startRow; r < startRow + s; r++) {
            for (int c = startCol; c < startCol + s; c++) {
                if (board[r][c] == num)
                    return false;
            }
        }
        
        return true;
    }

    bool solveBoard(vector<vector<char>>& board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (notClash(i, j, board, num, n)) {
                            board[i][j] = num;
                            if (solveBoard(board, n))
                                return true;
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        
        return true; // Board is filled
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solveBoard(board, n);
    }
};