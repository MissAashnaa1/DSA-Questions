//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    // toposort method
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis, st);
            }
        }
        
        st.push(node);
    }
  
    string findOrder(string dict[], int n, int k) {
        // code here
        unordered_map<int, list<int>> adj;
        for(int i=1; i<n; i++) {
            int j=0;
            int len = min(dict[i].length(), dict[i-1].length());
            while(j < len && dict[i][j] == dict[i-1][j]) {
                j++;
            }
            if(j >= len) continue;
            adj[dict[i-1][j] - 'a'].push_back(dict[i][j] - 'a');
        }
        vector<bool> vis(k, false);
        stack<int> st;
        for(int i=0; i<k; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += char(st.top() + 'a');
            st.pop();
        }
        // cout << ans << endl;
        return ans;
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends