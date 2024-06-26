//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool check(int x,int y,int m,int n){
        return x<n && x>=0 && y<m && y>=0;
    }
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int>row{-1,1,0,0};
        vector<int>col{0,0,1,-1};
        for(int i = 0 ;i <n;i++){
            for(int j =0 ;j<m;j++){
                if(matrix[i][j] == 0){
                    for(int k=0;k<4;k++){
                        if(check(i+row[k],j+col[k],m,n)){
                            ans = ans + matrix[i+row[k]][j+col[k]];
                        }
                    }
                }
            }
        }
        return ans;
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
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends