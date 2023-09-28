//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code 
        int n=grid.size();
        int m=grid[0].size();
        int row[4]={1,0,-1,0};
        int col[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(i==0||j==0||i==n-1||j==m-1)
              {
                  if(grid[i][j]==1)
                  {
                      q.push({i,j});
                      grid[i][j]=-1;
                  }
              }
          }
        }
          while(!q.empty()){
              int r=q.front().first;
              int c=q.front().second;
              q.pop();
              for(int i=0;i<4;i++){
                  if(r+row[i]>=0&&r+row[i]<n&&c+col[i]>=0&&c+col[i]<m&&grid[r+row[i]][c+col[i]]==1){
                      q.push({r+row[i],c+col[i]});
                      grid[row[i]+r][c+col[i]]=-1;
                    }
              }
              
          }
          int ans=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(grid[i][j]==1)
                        ans++;
              }
          }
          return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends