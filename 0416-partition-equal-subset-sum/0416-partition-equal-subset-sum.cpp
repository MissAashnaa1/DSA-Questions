class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
           
            if((sum%2)==0)
                sum=sum/2;
            else return false;


        vector<bool>prev(sum+1,false);
        if(arr[0]<=sum)
        prev[arr[0]]=true;
        prev[0]=true;
        vector<bool>curr(sum+1,false);
        for(int i=1;i<arr.size();i++){
            curr[0]=true;
            for(int target=1;target<=sum;target++){
            
                bool take=false;
                if(target>=arr[i])
                    take=prev[target-arr[i]];
                bool notTake=prev[target];
                curr[target]=take||notTake;
            }
            if(curr[sum])
                return true;
            prev=curr;
        }
        return prev[sum];
    }
};