class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
      int currProfit=0;
      int mini=prices[0];
      for(int i=1;i<prices.size();i++){
        currProfit=max(currProfit,prices[i]-mini);
        mini=min(prices[i],mini);
      }
      return currProfit;
    }
    
};