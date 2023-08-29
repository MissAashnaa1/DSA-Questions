class Solution {
    void helper(vector<int>nums,set<int>s,vector<int>ds,vector<vector<int>>&ans,int ind){
        if(ind==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(i)==s.end()){
                s.insert(i);
                ds.push_back(nums[i]);
                helper(nums,s,ds,ans,ind+1);
                s.erase(s.find(i));
                ds.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<int>s;
        vector<int>ds;
        vector<vector<int>>ans;
        helper(nums,s,ds,ans,0);
        return ans;
    }
};