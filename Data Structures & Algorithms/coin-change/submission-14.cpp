class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;

        for(int i = 1;i<=amount;i++)
        {
             for(int j = 0;j<n;j++){
                if(coins[j]<=i){
                    /*
                    dp[i - coins[j]] → best (minimum) coins to make the remaining part

+1 → the current coin we are using now

min(...) → because there may be multiple coins that could make i, and we want the fewest total coins
                    */
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
             }
        }
        return dp[amount]>amount? -1 : dp[amount];
    }
};
