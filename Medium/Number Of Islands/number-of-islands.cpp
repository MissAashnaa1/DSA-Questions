//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int>rank(n*m,0);
        vector<int>parent(n*m);
        for(int i=0;i<n*m;i++){
            parent[i]=i;
        }
        int delRow[4]={0,1,0,-1};
        int delCol[4]={1,0,-1,0};
        vector<bool>vis(n*m,false);
        vector<int> ans;
        int count=0;
        for(auto it : operators){
            int row=it[0];
            int col=it[1];
            int node=row*m+col;
            if(vis[node]==1){
               ans.push_back(count); 
               continue;
            }
                
                vis[node]=1;
                count++;
                for(int i=0;i<4;i++){
                    int newRow=row+delRow[i];
                    int newCol=col+delCol[i];
                    if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m){
                        int adjNode=newRow*m+newCol;
                        if(vis[adjNode]==1)
                        {
                            if(findParent(parent,adjNode)!=findParent(parent,node))
                            {   unionSet(adjNode,node,parent,rank);
                                count--;
                            }
                        }
                        
                        
                    }
                }
            ans.push_back(count); 
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends