class Solution {
    int helper(int i,int j,int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0||i>m||j<0||j>n)
            return 1e7;
        else if(i==m)
            return dp[i][j]=matrix[i][j];
        else if(dp[i][j]!=-1)
            return dp[i][j];
        
        int downleft=matrix[i][j]+helper(i+1,j-1,m,n,matrix,dp);
        int down=matrix[i][j]+helper(i+1,j,m,n,matrix,dp);
        int downright=matrix[i][j]+helper(i+1,j+1,m,n,matrix,dp);
           return dp[i][j]=min(downleft,min(down,downright));
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     int downleft=matrix[0][i]+helper(1,i-1,m-1,n-1,matrix,dp);
        //     int down=matrix[0][i]+helper(1,i,m-1,n-1,matrix,dp);
        //     int downright=matrix[0][i]+helper(1,i+1,m-1,n-1,matrix,dp);
            
        //     dp[0][i]=min(downleft,min(down,downright));
            
        //      ans=min(ans,dp[0][i]);
        // }
        // return ans;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[0][j]=matrix[0][j];
                    continue;
                }
                int upleft=1e7;
                int up=1e7;
                int upright=1e7;
                if(j>0)
                    upleft=matrix[i][j]+dp[i-1][j-1];
                    up=matrix[i][j]+dp[i-1][j];
                if(j<n-1)
                    upright=matrix[i][j]+dp[i-1][j+1];
                     dp[i][j]=min(upleft,min(up,upright));
            }
        }
        // int ans=1e7;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};