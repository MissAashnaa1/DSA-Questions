//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> solve(int i,int j,int d,int n,int m,vector<vector<int>>& matrix){
        if(matrix[i][j]==0){
            if(d==0){
                if(j+1==m){
                    return {i,j};
                }
                return solve(i,j+1,d,n,m,matrix);
            }else if(d==1){
                if(i+1==n){
                    return {i,j};
                }
                return solve(i+1,j,d,n,m,matrix);
            }else if(d==2){
                if(j-1==-1){
                    return {i,j};
                }
                return solve(i,j-1,d,n,m,matrix);
            }else{
                if(i-1==-1){
                    return {i,j};
                }
                return solve(i-1,j,d,n,m,matrix);
            }
        }else{
            matrix[i][j]=0;
            if(d==0){
                if(i+1==n){
                    return {i,j};
                }
                return solve(i+1,j,1,n,m,matrix);
            }else if(d==1){
                if(j-1==-1){
                    return {i,j};
                }
                return solve(i,j-1,2,n,m,matrix);
            }else if(d==2){
                if(i-1==-1){
                    return {i,j};
                }
                return solve(i-1,j,3,n,m,matrix);
            }else{
                if(j+1==m){
                    return {i,j};
                }
                return solve(i,j+1,0,n,m,matrix);
            }
        }
    }
    
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int i=0,j=0,d=0;
        return solve(i,j,0,n,m,matrix);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends