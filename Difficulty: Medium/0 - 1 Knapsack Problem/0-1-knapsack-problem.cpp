//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  private:
    int rec(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& mem) {
        if(i>=val.size()) return 0;
        if(mem[i][W]!=-1) return mem[i][W];
        int take=0;
        if(W>=wt[i])
            take=val[i]+rec(i+1,W-wt[i],wt,val,mem);
        int not_take=rec(i+1,W,wt,val,mem);
        return mem[i][W]=max(take,not_take);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        vector<vector<int>> mem(val.size()+1, vector<int>(W+1,-1));
        return rec(0,W,wt,val,mem);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends