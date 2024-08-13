class Solution {
public:
    void helper(vector<vector<int>>&v,vector<int>ans,int index,vector<int>arr,int target){
        if(target==0){
            v.push_back(ans);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index&&arr[i]==arr[i-1]){
                continue;
            }
             if(arr[i]>target){
                break;
            }
            ans.push_back(arr[i]);
            helper(v,ans,i+1,arr,target-arr[i]);
            ans.pop_back();
        }
        // return;
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        helper(v,ans,0,candidates,target);
        return v;
    }
};