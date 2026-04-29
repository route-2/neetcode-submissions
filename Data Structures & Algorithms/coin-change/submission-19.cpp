class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        // dp[i] means minimum number of coins needed to make amount i
        // initially I assume every amount is impossible, so I fill with amount+1
        // amount+1 works like "infinity" because we can never need more than amount coins
        vector<int> dp(amount + 1, amount + 1);

        // to make amount 0, we need 0 coins
        dp[0] = 0;

        // now I build answers from 1 up to the final amount
        for (int i = 1; i <= amount; i++) {

            // try every coin for this amount i
            for (int j = 0; j < n; j++) {

                // only try this coin if it is not bigger than i
                if (coins[j] <= i) {

                    /*
                    here is the main idea:

                    suppose:
                    coins = [1,2,5]
                    i = 11
                    coins[j] = 2

                    then remainder = i - coins[j] = 11 - 2 = 9

                    so I am basically asking:
                    "if I use coin 2 as my LAST coin,
                     can I already make 9?"

                    if dp[9] is already computed (which it is,
                    because we build from smaller to bigger),
                    then adding this one coin 2 will make total 11.

                    why does +1 work?
                    because dp[9] tells me how many coins were used to make 9.
                    +1 means I am using THIS coin (2) one time.

                    so:
                    dp[9] coins make value 9
                    + this 2 coin makes value 11

                    the subtraction (i - coin) guarantees:
                    remainder + coin = i

                    so nothing is assumed randomly.
                    we are literally choosing this coin in this loop iteration.
                    */

                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // if dp[amount] is still bigger than amount,
        // that means we never found a valid way
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
