class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxCount = 0; // max frequency of any char in current window
        int left = 0;
        int res = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // total letters to change = window size - max freq char
            if ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++; // shrink window
            }

            res = max(res, right - left + 1); // valid window
        }

        return res;
    }
};
