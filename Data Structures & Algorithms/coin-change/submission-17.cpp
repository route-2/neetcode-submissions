class Solution {
public:
    unordered_map<int, int> memo;

    int dfs(int amount, vector<int>& coins) {
        // base case
        if (amount == 0) return 0;

        // memo hit
        if (memo.find(amount) != memo.end()) return memo[amount];

        int res = INT_MAX; // INF

        for (int coin : coins) {
            if (amount - coin >= 0) {
                int result = dfs(amount - coin, coins);

                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }

        memo[amount] = res;
        return res;

        /*
        --------------------------------------------
        example walk (coins = [1,2,5]):

        dfs(1)

        start of dfs(1):
          res = INF

        loop coins:
          coin=1:
            amount-coin = 1-1 = 0
            result = dfs(0) = 0  (base case)
            res = min(INF, 1 + 0) = 1

          coin=2:
            1-2 < 0 -> skip

          coin=5:
            1-5 < 0 -> skip

        end dfs(1):
          memo[1] = 1
          return 1

        memo now: {1:1}

        --------------------------------------------

        dfs(2)

        start dfs(2):
          res = INF

        loop coins:
          coin=1:
            amount-coin = 2-1 = 1
            dfs(1) is in memo -> returns memo[1] = 1
            result = 1
            res = min(INF, 1 + 1) = 2

          coin=2:
            amount-coin = 2-2 = 0
            result = dfs(0) = 0
            res = min(2, 1 + 0) = 1

          coin=5:
            2-5 < 0 -> skip

        end dfs(2):
          memo[2] = 1
          return 1

        memo now: {1:1, 2:1}

        --------------------------------------------

        dfs(3)

        start dfs(3):
          res = INF

        loop coins:
          coin=1:
            amount-coin = 3-1 = 2
            memo hit: dfs(2) = 1
            result = 1
            res = min(INF, 1 + 1) = 2

          coin=2:
            amount-coin = 3-2 = 1
            memo hit: dfs(1) = 1
            result = 1
            res = min(2, 1 + 1) = 2  (no change)

          coin=5:
            3-5 < 0 -> skip

        end dfs(3):
          memo[3] = 2
          return 2

        memo now: {1:1, 2:1, 3:2}
        --------------------------------------------
        */
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(amount, coins);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};
