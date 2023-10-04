class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int ans=0;
        int g=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            g+=nums[i];   
            
            if(g==goal){
                ans++;
            }
            if(m.find(g-goal)!=m.end()){
                ans+=m[g-goal];
            }
        m[g]++;
        }
    return ans;
    }
};