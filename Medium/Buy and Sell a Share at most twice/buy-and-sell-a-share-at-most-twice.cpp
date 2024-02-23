//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
      int solve(int i, bool allowed, int transactions, vector<int>& price, vector<vector<vector<int>>>& dp) {
            if(i >= price.size()) {
                return 0;
            }
            if(transactions == 0) {
                return 0;
            }
            if(dp[i][allowed][transactions] != -1) {
                return dp[i][allowed][transactions];
            }
            
            int profit = 0;
            if(allowed) {
                int buy = -price[i] + solve(i+1, false, transactions, price, dp);
                int leave = 0 + solve(i+1, allowed, transactions, price, dp);
                
                profit = max(buy, leave);
            } else {
                int sell = price[i] + solve(i+1, true, transactions-1, price, dp);
                int leave = 0 + solve(i+1, allowed, transactions, price, dp);
                
                profit = max(sell, leave);
            }
            
            return dp[i][allowed][transactions] = profit;
        }
        // TABULATION
        int solveTab(vector<int>& price) {
            int n = price.size();
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (4, 0)));
            
            for(int i=n-1; i>=0; i--) {
                for(int allowed=0; allowed<=1; allowed++) {
                    for(int transactions=0; transactions<=2; transactions++) {
                        if(transactions == 0) {
                            dp[i][allowed][transactions] = 0;
                        } else {
                            int profit = 0;
                            if(allowed) {
                                int buy = -price[i] + dp[i+1][false][transactions];
                                int leave = 0 + dp[i+1][allowed][transactions];
                                
                                profit = max(buy, leave);
                            } else {
                                int sell = price[i] + dp[i+1][1][transactions-1];
                                int leave = 0 + dp[i+1][allowed][transactions];
                                
                                profit = max(sell, leave);
                            }
                            
                            dp[i][allowed][transactions] = profit;
                        }
                    }
                }
            }
            
            return dp[0][1][2];
        }
        // SPACE OPTIMISATION
        int spaceOptimised(vector<int>& price) {
            int n = price.size();
            vector<vector<int>> curr(2, vector<int> (3, 0)), next(2, vector<int> (3, 0));
            
            for(int i=n-1; i>=0; i--) {
                for(int allowed=0; allowed<=1; allowed++) {
                    for(int transactions=0; transactions<=2; transactions++) {
                        if(transactions == 0) {
                            curr[allowed][transactions] = 0;
                        } else {
                            int profit = 0;
                            if(allowed) {
                                int buy = -price[i] + next[false][transactions];
                                int leave = 0 + next[allowed][transactions];
                                
                                profit = max(buy, leave);
                            } else {
                                int sell = price[i] + next[1][transactions-1];
                                int leave = 0 + next[allowed][transactions];
                                
                                profit = max(sell, leave);
                            }
                            
                            curr[allowed][transactions] = profit;
                        }
                    }
                }
                next = curr;
            }
            
            return curr[1][2];
        }
         
        int maxProfit(vector<int>&price){
            //Write your code here..
            // vector<vector<vector<int>>> dp(price.size(), vector<vector<int>> (2, vector<int> (3, -1)));
            // return solve(0, true, 2, price, dp);
            
            // return solveTab(price);
            
            return spaceOptimised(price);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends