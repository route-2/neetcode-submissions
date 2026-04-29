class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> chars(128, 0); // for ASCII
        int n = s.length();
        int left = 0, right = 0;
        int longest = 0;

        while (right < n) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                // shrink from the left
                chars[s[left]]--;
                left++;
            }

            longest = max(longest, right - left + 1);
            right++;
        }

        return longest;
        
    }
};
