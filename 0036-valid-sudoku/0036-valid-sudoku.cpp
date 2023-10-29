class Solution {
public:
bool validBox(vector<vector<char>>& board,int sr,int er,int sc,int ec){
    // 3*3
    unordered_set<char> st;
    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            if(board[i][j]=='.'){
                continue;
            }
            if(st.find(board[i][j])!=st.end()){
                return false;
            }

            st.insert(board[i][j]);
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
            // row=9
            // col=9

            // validate

            for(int row=0;row<9;row++){
                unordered_set<char> st;
                for(int col=0;col<9;col++){
                    if(board[row][col]=='.'){
                        continue;
                    }

                    if(st.find(board[row][col])!=st.end()){
                        return false;
                    }

                    st.insert(board[row][col]);
                }
            }

            for(int col=0;col<9;col++){
                unordered_set<char> st;

                for(int row=0;row<9;row++){
                    if(board[row][col]=='.'){
                        continue;
                    }

                    if(st.find(board[row][col])!=st.end()){
                        return false;
                    }

                    st.insert(board[row][col]);
                }
            }

            // validate 3*3
            for(int sr=0;sr<9;sr+=3){
                int er=sr+2;

                for(int sc=0;sc<9;sc+=3){
                    int ec=sc+2;

                    // sr,er,sc,ec

                    if(!validBox(board,sr,er,sc,ec)){
                            return false;
                    }
                }

            }
            return true;
    }
};