//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
 public:
   vector<string> ans;
    void dfs(int i, int j, string str, vector<vector<int>> &mat, vector<vector<bool>> &visited, int end) 
    {
        if (i == end - 1 && j == end - 1) 
        {
            ans.push_back(str);
            return;
        }
        
        // Directions: Right, Down, Left, Up
        int r[] = {0, 1, 0, -1};
        int c[] = {1, 0, -1, 0};
        string directions = "RDLU";
    
        // Explore all 4 possible directions
        for (int k = 0; k < 4; k++) 
        {
            int nr = i + r[k];
            int nc = j + c[k];
    
            if (nr >= 0 && nr < end && nc >= 0 && nc < end && mat[nr][nc] == 1 && !visited[nr][nc]) 
            {
                visited[nr][nc] = true;
                dfs(nr, nc, str + directions[k], mat, visited, end);
                visited[nr][nc] = false;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &mat) 
    {
        int m = mat.size();  // number of rows
        int n = mat[0].size(); // number of columns
    
        // Check if the start or end cell is blocked
        if (mat[0][0] == 0 || mat[m - 1][n - 1] == 0) 
        {
            return ans;
        }
    
        // Initialize visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
    
        // Start DFS from the top-left corner
        visited[0][0] = true;
        dfs(0, 0, "", mat, visited, m);
    
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends