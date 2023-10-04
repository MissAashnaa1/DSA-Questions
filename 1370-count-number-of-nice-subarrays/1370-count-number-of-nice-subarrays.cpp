class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0;
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                odd++;
            }
            m[odd]++;
            if(odd==k){
                ans++;
            }
            if(m.find(odd-k)!=m.end()){
                ans+=m[odd-k];
            }
        }
    return ans;
    }
};