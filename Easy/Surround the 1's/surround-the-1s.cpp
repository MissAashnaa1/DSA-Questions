//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int dx[8]={-1,0,1,0,-1,-1,1,1};
        int dy[8]={0,1,0,-1,-1,1,-1,1};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                int zero=0;    
                    for(int k=0;k<8;k++){
                        int newrow=i+dx[k];
                        int newcol=j+dy[k];
                        
                        if(newrow>=0&&newrow<n&&newcol>=0&&newcol<m&&grid[newrow][newcol]==0){
                            zero++;
                        }
                        
                        
                    }
                   if(zero>0&&zero%2==0){
                     ans++;
                    } 
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends