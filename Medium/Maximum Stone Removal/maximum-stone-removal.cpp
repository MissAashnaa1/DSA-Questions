//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxrow=0,maxcol=0;
        for(auto it : stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        unordered_map<int,int>m;
        vector<int>parent(maxrow+maxcol+2);
        vector<int>rank(maxrow+maxcol+2,0);
        for(int i=0;i<maxrow+maxcol+2;i++){
            parent[i]=i;
        }
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
            unionSet(row,col,parent,rank);
            m[row]=1;
            m[col]=1;
        }
        int count=0;
        for(auto it : m){
            if(findParent(parent,it.first)==it.first)
                count++;
        }
        return n-count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends