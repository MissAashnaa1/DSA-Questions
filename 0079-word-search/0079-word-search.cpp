class Solution {
bool rec(vector<vector<char>> &board,int r,int c,string word,int index){
        if(index==word.length())
            return true;
        int row=board.size();
        int col=board[0].size();
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            
                int newr=dr[i]+r;
                int newc=dc[i]+c;
                if(newr>=0&&newc>=0&&newr<row&&newc<col&&board[newr][newc]==word[index]){   
                    board[newr][newc]='.';
                    if(rec(board,newr,newc,word,index+1)==true)
                        return true;
                  board[newr][newc]=word[index];
                }
            
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();

        //zero mark krdenge taki vpis na jye and dx dy vli chiz
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    
                    board[i][j]='.';
                    if(rec(board,i,j,word,1))
                        return true;
                    board[i][j]=word[0];
                }
            }
        }
        return false;
    }
};