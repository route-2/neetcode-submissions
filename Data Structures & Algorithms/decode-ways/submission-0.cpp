class Solution {
public:
    unordered_map<int, int> memo; // ✅ Memoization table

    int dfs(int i, string& s) {
        if (i == s.size()) return 1;  // ✅ Base case: If we reached the end, we found a valid decoding
        if (s[i] == '0') return 0;   // ❌ Invalid case: '0' alone can't be decoded
        if (memo.count(i)) return memo[i]; // 🚀 Use cached result

        int res = dfs(i + 1, s);  // 🟢 Try decoding `s[i]` as a single digit

        if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
            res += dfs(i + 2, s);  // 🟢 Try decoding `s[i:i+1]` as a two-digit number
        }

        return memo[i] = res;  // 📝 Store result in `memo`
    }

    int numDecodings(string s) {
        return dfs(0, s);  // 🔥 Start DFS from index `0`
    }
};
