class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128, 0);
        int n = s.length();
        int longest = 0;
        int i = 0, j = 0;

        while (j < n) {
            if (chars[s[j]] == 0) {
                chars[s[j]]++;
                longest = max(longest, j - i + 1);
                j++;
            } else {
                chars[s[i]]--;
                i++;
            }
        }

        return longest;
    }
};
