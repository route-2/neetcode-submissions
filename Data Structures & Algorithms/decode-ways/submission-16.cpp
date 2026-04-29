class Solution {
public:
    int dfs(int i, string& s) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s);
        if (i < s.size() - 1) {
            if (s[i] == '1' ||
               (s[i] == '2' && s[i + 1] < '7')) {
                res += dfs(i + 2, s);
            }
        }
        return res;
    }

    int numDecodings(string s) {
        return dfs(0, s);
    }
};
/*
dfs(0)
  └─ dfs(1)
       └─ dfs(2)
            └─ dfs(3)
                 └─ dfs(4)



time complexity = O(2^n)
space cpmplexity = O(n)

*/

// s="1112" (n=4)
//
// dfs(4) = 1  (hit end)
//
// dfs(3): res=dfs(4)=1 -> return 1
//
// dfs(2): res=dfs(3)=1
//         "12" valid -> +dfs(4)=1
//         return 2
//
// dfs(1): res=dfs(2)=2
//         "11" valid -> +dfs(3)=1
//         return 3
//
// dfs(0): res=dfs(1)=3
//         "11" valid -> +dfs(2)=2
//         return 5
