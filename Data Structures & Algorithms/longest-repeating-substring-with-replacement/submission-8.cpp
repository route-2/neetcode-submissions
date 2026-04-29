class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = (int)s.size();
        if (n == 0) return 0;

        vector<int> cnt(26, 0);
        int left = 0;
        int maxCount = 0;   // max frequency of a single char in current window
        int res = 0;

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'A';
            cnt[idx]++;
            maxCount = max(maxCount, cnt[idx]);

            // if replacements needed > k, shrink window
            while ((i - left + 1) - maxCount > k) {
                cnt[s[left] - 'A']--;
                left++;
            }

            res = max(res, i - left + 1);
        }

        return res;

        /*
        Shrinking the window means “throw away” characters from the left.
So you must “undo” their effect on your frequency table.
        */
    }
};
