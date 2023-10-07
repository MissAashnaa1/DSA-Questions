class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
    int n=nums.size();
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