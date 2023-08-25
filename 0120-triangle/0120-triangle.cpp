class Solution {
    // int helper(vector<vector<int>>& triangle,int i,int j,int m,int n,vector<vector<int>>dp){
    //     if(i==m){
            
    //             return triangle[m][j];
            
    //     }
    //     if(i>m||j>n)
    //         return 1e7;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int down=triangle[i][j]+helper(triangle,i+1,j,m,n,dp);
    //     int downRight=triangle[i][j]+helper(triangle,i+1,j+1,m,n,dp);
    //     return min(down,downRight);

    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return helper(triangle,0,0,m-1,n-1,dp);
        vector<int>next(n,0);
        for(int i=0;i<n;i++){
            next[i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=i;j>=0;j--){
                
                int down=triangle[i][j]+next[j];
                int downRight=triangle[i][j]+next[j+1];
                curr[j]=min(down,downRight);
            }
            next=curr;
        }
        return next[0];
    }
};