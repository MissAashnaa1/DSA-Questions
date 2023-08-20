class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
            m[nums[i]]++;
        int ans=0;
        for(auto it:m)
            {
                ans+=it.second*(it.second-1)/2;
            }
        return ans;
    }
};