class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        //lambda function use
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b)
        {
            return m[a]==m[b]?a>b:(m[a]<m[b]);
        });
        return nums;
    }
};