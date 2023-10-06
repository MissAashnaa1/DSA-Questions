class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            
            priority_queue<int,vector<int>,greater<int>>minHeap;
            // for(int i=0;i<nums.size();i++){
                
            //     minHeap.push(nums[i]);
            //     if(minHeap.size()>k){
            //         minHeap.pop();
            //     };
            // }
            // return minHeap.top();
            for(int i=0;i<k;i++){
                minHeap.push(nums[i]);
            }
            for(int i=k;i<nums.size();i++){
                if(minHeap.top()<nums[i]){
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
            return minHeap.top();
    }
};