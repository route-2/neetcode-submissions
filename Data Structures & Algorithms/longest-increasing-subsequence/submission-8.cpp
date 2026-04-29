class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs(0, -1, nums);
    }

    int dfs(int i, int prev, vector<int>& nums) {
        if (i == nums.size()) return 0;

        int notTake = dfs(i + 1, prev, nums);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + dfs(i + 1, i, nums);
        }

        return max(take, notTake);
    }
};
/*
At every index:

skip the current number

take it if it is bigger than the previously chosen one

This creates a recursion tree of choices.

dfs(0, -1)  // 9
├── skip 9 -> dfs(1, -1)  // 1
│   ├── skip 1 -> dfs(2, -1)  // 4
│   └── take 1 -> 1 + dfs(2, 1)
│       ├── take 4 -> 1 + dfs(3, 2)
│       └── skip 4 -> dfs(3, 1)
│           ├── take 2 -> 1 + dfs(4, 3)
│           │   ├── take 3 -> 1 + dfs(5, 4)
│           │   │   ├── skip 3 -> dfs(6, 4)
│           │   │   │   └── take 7 -> 1
│           │   │   return 2
│           │   return 3
│           return 3
│       total becomes 4
│
└── take 9 -> 1 + dfs(1, 0)
    └── nothing smaller can be taken after 9 except larger later,
        but this path is worse than starting from 1
*/