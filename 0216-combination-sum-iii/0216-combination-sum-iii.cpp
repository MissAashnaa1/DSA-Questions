class Solution {
    void helper( vector<vector<int>>&v,int k,int ind,int sum,vector<int>ans,int number){
        if(sum==0&&ind==k){
            v.push_back(ans);
            return;
        }
        if(sum<0||ind>k)
            return;
        for(auto i=number;i<=9;i++)
            {
                //take
                
                ans.push_back(i);
                helper(v,k,ind+1,sum-i,ans,i+1);
                ans.pop_back();
                helper(v,k,ind,sum,ans,i+1);
            }

    }
public:
    vector<vector<int>> combinationSum3(int k, int sum) {
        
        
        vector<int>v;
        vector<vector<int>>ans; 
        helper(ans,k,0,sum,v,1);
        int n=ans.size();
        vector<vector<int>>res;
        int i=0;
        sort(ans.begin(),ans.end());
        while(i<n){
            if(i+1==n||ans[i]!=ans[i+1])
                res.push_back(ans[i]);
            i++;
        }
        
         return res;
        // return ans;
    }
};