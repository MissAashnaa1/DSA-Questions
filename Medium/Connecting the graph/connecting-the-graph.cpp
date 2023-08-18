//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findParent(vector<int>&parent,int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findParent(parent,parent[u]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        int paru=findParent(parent,u);
        int parv=findParent(parent,v);
        if(rank[u]<rank[v]){
            parent[paru]=parv;
            
        }
        else if(rank[v]<rank[u]){
            parent[parv]=paru;
        }
        else{
            rank[v]++;
            parent[paru]=parv;
        }
    }
    
    int Solve(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>rank(V,0);
        vector<int>parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        // vector<bool>vis(V,false);
        int count=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            // vis[u]=true;
            // vis[v]=true;
            int paru=findParent(parent,u);
            int parv=findParent(parent,v);
            if(paru==parv)
            count++;
            else{
                unionSet(u,v,parent,rank);
                // ans+=wt;
            }
            
        }
        int k=0;
        for(int i=0;i<V;i++){
            if(parent[i]==i)
            k++;
        }
        //edges required k-1 to connect k
        if(--k>count)
            return -1;
        else return k;
        
        
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends