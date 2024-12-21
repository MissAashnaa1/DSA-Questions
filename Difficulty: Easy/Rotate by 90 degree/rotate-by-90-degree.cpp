//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        if(n == 1) return;
        
        vector<vector<int>> mat2(n, vector<int>(n, 0));
        
        float mid = (float)(n-1)/2;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                float nx = (i - mid);
                float ny = (j - mid);
                
                float nx2 = (-1*ny);
                float ny2 = nx;
                
                nx2 += mid;
                ny2 += mid;
                
                nx2 = (int)(nx2);
                ny2 = (int)(ny2);
                
                // cout << i << " " << j << " " << nx2 << " " << ny2 << endl;
                
                mat2[nx2][ny2] = mat[i][j];
                
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat[i][j] = mat2[i][j];
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends