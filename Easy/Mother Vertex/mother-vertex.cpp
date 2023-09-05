//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{   void dfs(set<int>&s,int i,vector<int>adj[],vector<bool>&vis){
        s.insert(i);
        vis[i]=true;
        for(auto it:adj[i]){
            if(s.find(it)==s.end()){
                dfs(s,it,adj,vis);
            }
        }
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>vis(V,false);
	    
	    for(int i=0;i<V;i++){
	        set<int>s;
	        if(!vis[i])
	        dfs(s,i,adj,vis);
	        if(s.size()==V)
	            return i;
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends