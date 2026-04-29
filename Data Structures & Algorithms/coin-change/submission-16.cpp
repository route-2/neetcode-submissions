class Solution {
public:
    // memo[amount] = minimum coins needed to make this amount
    // if it's INT_MAX, it means "not possible"
    unordered_map<int, int> memo;

    int dfs(int amount, vector<int>& coins) {
        // base case: to make 0, we need 0 coins
        if (amount == 0) return 0;

        // if we already solved this amount before, just reuse it
        // (this avoids doing the same recursion again and again)
        if (memo.find(amount) != memo.end())
            return memo[amount];

        // res = best answer we can find for this amount
        // start as INT_MAX = "haven't found any valid way yet"
        int res = INT_MAX;

        // try every coin as the "first coin we pick"
        for (int coin : coins) {
            // we can only use this coin if it doesn't make amount negative
            if (amount - coin >= 0) {

                // ask: "if i pick this coin, what's the best way to make the rest?"
                // rest = amount - coin
                int result = dfs(amount - coin, coins);

                // if the rest was possible to make,
                // then total coins = 1 (this coin) + result (coins for the rest)
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }

        // store the best answer for this amount so next time it's O(1)
        memo[amount] = res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(amount, coins);

        // if dfs says "impossible" (INT_MAX), return -1 like the problem wants
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};
