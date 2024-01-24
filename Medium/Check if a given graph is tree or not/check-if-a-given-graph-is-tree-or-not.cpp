//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
   bool isCyclic(vector<vector<int>>& adjList,int node,vector<bool>& visited,int n,int p)
  {
      visited[node]=true;
      for(auto x:adjList[node])
      {
          if(x==p)continue;
          if(!visited[x])
          {
              if(isCyclic(adjList,x,visited,n,node))return true;
          }
          else if(x!=p)return true;
      }
      return false;
  }
  bool checkCyclic(vector<vector<int>>& adjList,int n,vector<bool> visited,int& connectedcomponents)
  {
      
      for(int i=0;i<n;i++)
      {
          if(!visited[i]){
              connectedcomponents++;
              if(isCyclic(adjList,i,visited,n,-1))return true;
          }
          
      }
      return false;
  }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<vector<int>> adjList(n);
        for(auto x:adj)
        {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        int connectedcomponents=0;
        if(checkCyclic(adjList,n,visited,connectedcomponents))return 0;
        if(connectedcomponents>1)return 0;
        return 1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends