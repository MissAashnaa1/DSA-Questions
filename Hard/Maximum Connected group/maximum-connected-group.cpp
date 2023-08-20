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
    void unionSet(int u,int v,vector<int>&parent,vector<int>&size){
        int paru=findParent(parent,u);
        int parv=findParent(parent,v);
        if(paru==parv)
            return;
        if(size[u]<size[v]){
            parent[paru]=parv;
            size[parv]+=size[paru];
        }
        else {
            parent[parv]=paru;
            size[paru]+=size[parv];
        }
        
        
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        vector<int>parent(n*n);
        vector<int>size(n*n,1);
        for(int i=0;i<n*n;i++)
            parent[i]=i;
            int dx[4]={0,1,0,-1};
            int dy[4]={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int row=i;
                    int col=j;
                    
                    for(int k=0;k<4;k++){
                        int newrow=dx[k]+row;
                        int newcol=dy[k]+col;
                        if(newcol>=0&&newcol<n&&newrow>=0&&newrow<n&&grid[newrow][newcol]==1)
                           { 
                               
                            int node=row*n+col;
                            int adjnode=newrow*n+newcol;
                            unionSet(node,adjnode,parent,size);
                           }
                        }
                    }
                }
            }
            int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int row=i;
                    int col=j;
                    unordered_set<int>s;
                    for(int k=0;k<4;k++){
                        int newrow=dx[k]+row;
                        int newcol=dy[k]+col;
                        if(newcol>=0&&newcol<n&&newrow>=0&&newrow<n&&grid[newrow][newcol]==1)
                           { 
                            // int node=row*n+col;
                            
                            int adjnode=newrow*n+newcol;
                            s.insert(findParent(parent,adjnode));
                           }
                        }
                    int temp=1;
                    for(auto it:s){
                        temp+=size[it];
                    }
                    ans=max(ans,temp);
                    }
                    
                }
                
            }//if all the cells are 1
            
            if(ans==0){
                int k=0;
                for(int i=0;i<n*n;i++)
                    k=max(k,size[i]);
                    
                    return k;
            }
            return ans;
         
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends