class Solution {
public:

    void helper(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
        
        int n = board.size();

        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1 + col - row] == 0){
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n-1 + col - row] = 1;

                board[row][col] = 'Q';
                helper(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';

                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board;

        string s;
        for(int i = 0; i < n; i++) s.push_back('.'); // or direct: string s(n, '.');

        for(int i = 0; i < n; i++) board.push_back(s);


        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);

        helper(0, board, ans, leftRow, upperDiagonal, lowerDiagonal);

        return ans;
    }
};