class Solution {
    // int helper(vector<vector<int>>grid,int i,int j,vector<vector<int>>&dp){
    //     if(i==0&&j==0)
    //         return grid[0][0];
    //     if(i<0||j<0)
    //         return 1e8;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];


        
    //      int   up=grid[i][j]+helper(grid,i-1,j,dp);
        
    //      int   left=grid[i][j]+helper(grid,i,j-1,dp);
    //     return dp[i][j]=min(up,left);
        

    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // dp[0][0]=grid[0][0];
        // return helper(grid,m-1,n-1,dp);
        // dp[0][0]=grid[0][0];
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    curr[0]=grid[0][0];
                    continue;
                }
                    
                int up=1e7;
                int down=1e7;
                if(i>0)
                    up=grid[i][j]+prev[j];
                if(j>0)
                    down=grid[i][j]+curr[j-1];
                curr[j]=min(up,down);

            }
            prev=curr;
        }
        return prev[n-1];
    }
};