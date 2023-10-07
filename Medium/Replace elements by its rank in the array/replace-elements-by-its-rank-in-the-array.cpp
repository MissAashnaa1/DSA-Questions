//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &nums, int n){
    //2 loops
    //
    vector<int>u=nums;
    sort(nums.begin(),nums.end());
    int ii=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(mp.find(nums[i])==mp.end()){
            mp.insert({nums[i],++ii});
        }
    }
    vector<int>v;
    for(auto it: u){
        v.push_back(mp[it]);
    }
    return v;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends