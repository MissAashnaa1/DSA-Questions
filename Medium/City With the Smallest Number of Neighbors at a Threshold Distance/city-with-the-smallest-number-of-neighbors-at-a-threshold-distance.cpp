//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
    vector<vector<int>>dis(n,vector<int>(n,1e8));
    
    for(auto it :edges)
    {
        dis[it[0]][it[1]]=it[2];
        dis[it[1]][it[0]]=it[2];
        
    }
    for(int i=0;i<n;i++)
        dis[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int cityNum=0;
    int mincities=INT_MAX;
        for(int i=0;i<n;i++){
            int city=0;
            for(int j=0;j<n;j++){
                if (dis[i][j]<=distanceThreshold&&i!=j){
                    city++;
                }
            }
            if(city<=mincities){
                cityNum=i;
                mincities=city;
                
            }
        }
            return cityNum;        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends