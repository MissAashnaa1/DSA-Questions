class Solution {
    void helper( set<vector<int>>&s,int k,int ind,int sum,vector<int>ans,int number){
        if(sum==0&&ind==k){
            s.insert(ans);
            return;
        }
        if(sum<0||ind>k)
            return;
        for(auto i=number;i<=9;i++)
            {
                //take
                ans.push_back(i);
                helper(s,k,ind+1,sum-i,ans,i+1);
                ans.pop_back();
                helper(s,k,ind,sum,ans,i+1);
            }
    }
public:
    vector<vector<int>> combinationSum3(int k, int sum) {
        
        set<vector<int>>s;
        vector<int>v;
        helper(s,k,0,sum,v,1);
        vector<vector<int>>ans; 
        
        for(auto it:s)
            ans.push_back(it);
        
        return ans;
        
    }
};