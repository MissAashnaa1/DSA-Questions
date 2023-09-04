//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
        void func(vector<vector<int>>adl, int ind, vector<bool>&vis){
            vis[ind] = true;
            for(int i=0;i<adl[ind].size();i++){
                if(!vis[adl[ind][i]]){
                    func(adl,adl[ind][i], vis);
                }
            }
            return;
        }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adl(V);
        vector<bool>vis(V,false);
        
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(u!=v && adj[u][v]==1){
                    adl[u].push_back(v);
                    
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                func(adl,i,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends