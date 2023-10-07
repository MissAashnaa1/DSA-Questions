class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num : nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for (auto it : mp){
            if(pq.size()<k){
                pq.push({it.second,it.first});

            }
            else if(pq.top().first<it.second){
                pq.pop();
                pq.push({it.second,it.first});
            }
        }
        vector<int>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};