//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    
        int minimumCostPath(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        pq.push({grid[0][0], {0, 0}});
            // helper(m,n,grid,dp)
            
            while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int sum = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be min).
            // if (row == n - 1 && col == m - 1)
            //     return sum;
           
            int dr[4]={1,0,-1,0};
            int dc[4]={0,1,0,-1};
            for (int i = 0; i < 4; i++)
            {
                // row - 1, col
                // row, col + 1
                // row - 1, col
                // row, col - 1
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    
                    int newEffort = sum + grid[newr][newc];

                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends