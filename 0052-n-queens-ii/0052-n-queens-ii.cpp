class Solution {
    void solve(int &ans,int i,int n,vector<int>&ld,vector<int>&rd
    ,vector<int>&ur){
        if(i==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(!ur[j]&&!rd[(n-1)-i+j]&&!ld[i+j]){
                // board[i][j]='Q';
                ur[j]=rd[(n-1)-i+j]=ld[i+j]=1;
                solve(ans,i+1,n,ld,rd,ur);
                ur[j]=rd[(n-1)-i+j]=ld[i+j]=0;
                // board[i][j]='.';
            }

        }
    }
public:
    int totalNQueens(int n) {
        vector<int>upperRow(n,0);
        vector<int>ld(2*n-1,0);
        vector<int>rd(2*n-1,0);
        // vector<string>board(n,string(n,'.'));
        int ans=0;
        solve(ans,0,n,ld,rd,upperRow);
        return ans;
    }
};