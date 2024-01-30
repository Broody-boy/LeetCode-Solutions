class Solution {
public:

    bool isSafe(int row, int col, vector<string> board){

        int n = board.size();

        for(int c = 0; c <= col; c++){
            if(board[row][c] == 'Q') return false;
        }

        int r = row;
        int c = col;
        while(r >= 0 && c >=0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;
        while(r < n && c >=0){
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;

    }

    void helper(int col, vector<string> &board, vector<vector<string>> &ans){
        int n = board.size();

        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                helper(col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board;

        string s;

        for(int i = 0; i < n; i++){
            s.push_back('.');
        }

        for(int i = 0; i < n; i++)
            board.push_back(s);

        helper(0, board, ans);

        return ans;
    }
};