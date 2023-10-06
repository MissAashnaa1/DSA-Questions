class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int>pq;
        // for(auto num : nums){
        //     pq.push(num);
        // }
        // int ans=0;
        // //o(nlogk)
        // while(k){
        //     ans=pq.top();
        //     pq.pop();
        //     k--;
        // }
        // return ans;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k){
                minHeap.pop();
            };
        }
        return minHeap.top();
    }
};