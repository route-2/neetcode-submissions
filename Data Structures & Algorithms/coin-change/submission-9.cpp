class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;

        for(int i = 1;i<=amount;i++){

            /*
            Say i = 6, and you're considering coin = 5:

6 - 5 = 1

If dp[1] = 1 (you already know how to make 1),

Then you can build 6 by taking that dp[1] and adding 1 coin (the 5):

So, dp[6] = dp[1] + 1 = 2
            */

            for(int j = 0;j<n;j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
            



        }
        return dp[amount] > amount ? -1 : dp[amount];
        
    }
};
