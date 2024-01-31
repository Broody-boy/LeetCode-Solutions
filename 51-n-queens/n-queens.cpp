class Solution {
public:


    void helper(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &lr, vector<int> &ld, vector<int> &ud){
        int n = board.size();

        if(col == n){
            ans.push_back(board);
        }

        for(int row = 0; row < n; row++){
            if(lr[row] == 0 && ld[row + col] == 0 && ud[n-1 + row-col] == 0){

                lr[row] = 1;
                ld[row + col] = 1; 
                ud[n-1 + row-col] = 1;

                board[row][col] = 'Q';
                helper(col + 1, board, ans, lr, ld, ud);
                board[row][col] = '.';

                lr[row] = 0;
                ld[row + col] = 0; 
                ud[n-1 + row-col] = 0;
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board;

        vector<int> lr(n, 0);
        vector<int> ld(2*n-1, 0);
        vector<int> ud(2*n-1, 0);

        string s;
        for(int i = 0; i < n; i++) s.push_back('.'); // or direct: string s(n, '.');

        for(int i = 0; i < n; i++) board.push_back(s);

        helper(0, board, ans, lr, ld, ud);

        return ans;
    }
};