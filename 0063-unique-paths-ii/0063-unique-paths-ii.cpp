class Solution {
    int helper(int m,int n,int i,int j,vector<vector<int>>&dp, vector<vector<int>>grid){
        if(i>m||j>n)
            return 0;
        if(grid[i][j]==1)
            return dp[i][j]=0;
        if(i==m&&j==n){
            return dp[i][j]=1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int way1=0;
        int way2=0;
        if(i<m)
            way1=helper(m,n,i+1,j,dp,grid);
        if(j<n)
            way2=helper(m,n,i,j+1,dp,grid);
        return dp[i][j]=way1+way2;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
         int i=0;
         int j=0;
        dp[m-1][n-1]=0;
         helper(m-1,n-1,i,j,dp,Grid);
         return dp[0][0];

    }
};