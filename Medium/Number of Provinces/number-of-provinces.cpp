//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
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
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>parent(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1&&i!=j){
                    int paru=findParent(parent,i);
                    int parv=findParent(parent,j);
                    if(paru!=parv)
                    unionSet(i,j,parent,rank);
                    
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            if(parent[i]==i)
                ans++;
        }
        return ans;
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