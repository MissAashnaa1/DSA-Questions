class Solution {
    bool isSafe(int row, int col, vector<string> &board, int n) { // TC: O(n)
        // check for same row
        int x = row;
        int y = col;
        while(y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            y--;
        }

        // check for digonals

        // check for LU diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }
        // check for LD diagonal
        x = row;
        y = col;
        while(x < n && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }
    void solve(int ii,int jj,vector<string>&board,vector<vector<string>>&ans){
        int n=board.size();
        if(jj==n)
        {   ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){

            if(isSafe(i,jj,board,n)){
                board[i][jj]='Q';
                solve(i,jj+1,board,ans);
                board[i][jj]='.';
            }

        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>board(n,string(n,'.'));
   
        solve(0,0,board,ans);
         
        return ans;
    }
};