class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int maxLim=0;

public:
    KthLargest(int k, vector<int>& nums) {
        maxLim=k;
        for(auto num : nums){
            if(pq.size()<k){
                pq.push(num);
            }
            else if(pq.top()<num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<maxLim){
            pq.push(val);
        }
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        if(pq.size()<maxLim){
            return -1;
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */