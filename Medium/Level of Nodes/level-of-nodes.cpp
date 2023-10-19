//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   
    // bool dfs(vector<bool>&vis,vector<int> adj[],int level,int &ans,int X,int index){
    //     vis[index]=true;
    //     if(index==X){
    //             ans=level;
    //             return true;
    //         }
    //     for(auto it: adj[index]){
            
    //         if(vis[it]==false){
    //             if(dfs(vis,adj,level+1,ans,X,it)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool>vis(V,false);
	   // int ans=-1;
	   // dfs(vis,adj,0,ans,X,0);
	   queue<pair<int,int>>q;
	   q.push({0,0});
	   while(q.size()){
	       pair<int,int>t=q.front();
	       int node=t.first;
	       int level=t.second;
	       q.pop();
	        if(node==X){
	            return level;
	        }
	        vis[node]=true;
	       for(auto it : adj[node]){
	           if(vis[it]==false){
	               q.push({it,level+1});
	           }
	       }
	   }
	   
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends