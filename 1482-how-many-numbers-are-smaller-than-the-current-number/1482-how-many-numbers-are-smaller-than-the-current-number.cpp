class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            m[nums[i]]++;

        }
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            for(auto it : m){
                if(it.first<nums[i]){
                        v[i]+=it.second;
                }
            }
        }
        return v;
    }
};