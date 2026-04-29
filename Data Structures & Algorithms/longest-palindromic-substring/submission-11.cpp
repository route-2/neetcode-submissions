class Solution {
public:
/*
for each i
    try odd center
        keep expanding while palindrome holds
        stop when it breaks
    try even center
        keep expanding while palindrome holds
        stop when it breaks
move to next i
*/
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);       // odd length
            expand(i, i + 1);   // even length
        }

        return s.substr(start, maxLen);
    }
};