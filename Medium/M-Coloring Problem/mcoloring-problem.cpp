//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool safe(bool graph[101][101],int col,vector<int>&color,int node,int n ){
        for(int i=0;i<n;i++){
            if(i!=node&&graph[node][i]==1&&color[i]==col)
                return false;
        }
        return true;
    }
    bool help(bool graph[101][101],int m,int n,int i,vector<int>&color){
        if(i==n)
        return true;
        for(int col=1;col<=m;col++){
            color[i]=col;
            if(safe(graph,col,color,i,n)){
                
                if(help(graph,m,n,i+1,color))
                    return true;
                
            }
            
               
        }
        color[i]=0;
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n,0);
        return help(graph,m,n,0,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends