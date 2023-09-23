class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
           vector<vector<int>>next(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int index=prices.size()-1;index>=0;index--){
            
            for(int buy=0;buy<=1;buy++){
                for(int cap=k-1;cap>=0;cap--){
        if(buy==1){//cap<2
            int buyy=-prices[index]+next[0][cap];
            //3
            int keep=next[1][cap];// 1
            curr[buy][cap]= max(buyy,keep);
        }
        //buy==0
        else{

            int sell=prices[index]+next[1][cap+1];
            int keep=next[0][cap];// 2
             curr[buy][cap]= max(sell,keep);                
            }
        }
    }
    next=curr;
        }
    return next[1][0];
    }
    
};