//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    std::vector<int> shortestPath(std::vector<std::vector<int>>& edges, int N, int M, int src) {
        std::vector<std::vector<int>> adjlist(N, std::vector<int>());
        for (auto& edge : edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        std::vector<int> distance(N, -1);
        distance[src] = 0;
        std::queue<int> queue;
        queue.push(src);
        while (!queue.empty()) {
            for (int node : adjlist[queue.front()]) {
                if (distance[node] == -1) {
                    distance[node] = distance[queue.front()] + 1;
                    queue.push(node);
                }
            }
            queue.pop();
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends