class Solution {
public:
    int maxProfit(vector<int>& prices) {
     vector<int> cur(2,0);
    vector<int> front1(2,0);
    vector<int> front2(2,0);
    //   return  helper(prices,0,1,dp);
    for(int index=prices.size()-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
                  if(buy==1){//can buy
            int buyy=-prices[index]+front1[0];//bought
            int keep=front1[1];//keep dont buy new
             cur[buy]=max(buyy,keep);//return jo max de
        }
        else{
        int sell=prices[index]+front2[1];//sold

        int keep=front1[0];//keep
             cur[buy]=max(sell,keep);
        }
        //buy nhi krskte ab sell krskte hain ya purana hi rkh skte
        }
        front2=front1;
        front1=cur;
    }
    return cur[1];
    }
};