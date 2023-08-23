class Solution {
    // Recursion
    // int rec(int m,int n,int i,int j){
    //     if(i==m&&j==n){
    //         return 1;
    //     }
    //     int way1=0;
    //     int way2=0;
    //     if(i<m){
    //         way1=rec(m,n,i+1,j);
    //     }
    //     if(j<n){
    //         way2=rec(m,n,i,j+1);
    //     }
    //     return way1+way2;
    // }
    int helper(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i>m||j>n)
            return 0;
        if(i==m&&j==n){
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int way1=0;
        int way2=0;
        if(i<m)
            way1=helper(m,n,i+1,j,dp);
        if(j<n)
            way2=helper(m,n,i,j+1,dp);
        return dp[i][j]=way1+way2;
    }
public:
    int uniquePaths(int m, int n) {
        
        // int ans=rec(m-1,n-1,0,0);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=0;
        int ans=helper(m-1,n-1,0,0,dp);

        return ans;
    
    }
};