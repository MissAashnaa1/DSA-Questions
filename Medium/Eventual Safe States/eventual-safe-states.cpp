//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    //  bool dfs(vector<int> adj[],vector<int>&vis,vector<int>&dfvis,int start,vector<int>&check){
    //     vis[start]=1;
    //     dfvis[start]=1;
    //     for(auto nbr: adj[start]){
    //         if(vis[nbr]==0){
                
    //             if(dfs(adj,vis,dfvis,nbr,check))
    //             return true;
    //         }
    //         else if(dfvis[nbr]==1)
    //         return true;
                
    //     }
    //     check[start]=1;
    //     dfvis[start]=0;
    //     return false;
    // }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // vector<int>vis(V,0);
        // vector<int>dfsvis(V,0);
        // vector<int>check(V,0);
        // for(int i=0;i<V;i++){
        //     if(!vis[i])
            
        // dfs(adj,vis,dfsvis,i,check);
        
            
        // }
        // vector<int>ans;
        // for(int i=0;i<V;i++){
        //     if(check[i]==1)
        //     ans.push_back(i);
        // }
        // return ans;
        vector<int>adj2[V];
        vector<int>indegree(V);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[i]++;
                adj2[it].push_back(i);
            }
        }
        queue<int>q;
        vector<int>v;
        for(int i=0;i<V;i++)
            if(indegree[i]==0)
            q.push(i);
            
            while(q.size()){
                int node=q.front();
                q.pop();
                v.push_back(node);
                for(int nbr:adj2[node])
                {
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
            sort(v.begin(),v.end());
            return v;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends