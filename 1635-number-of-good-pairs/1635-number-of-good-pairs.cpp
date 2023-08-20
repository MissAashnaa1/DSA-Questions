class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        
        int ans=0;
        for(auto it:nums)
            {
                ans+=m[it];
                m[it]++;
            }
        return ans;
    }
};