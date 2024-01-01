//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
        // Code here.
         bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            int rem = nums[i] % k;
            if(rem == 0 || m.find(k - rem) == m.end()){
                m[rem]++;
            }
            else{
                m[k - rem]--;
                if(m[k - rem] == 0) m.erase(k - rem);
            }
        }
        return m[0] % 2 == 0 && m.size() == 1;
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends