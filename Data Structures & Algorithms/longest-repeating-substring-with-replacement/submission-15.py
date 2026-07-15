class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}      # char -> frequency in current window (plain dict, .get() supplies default)
        res = 0         # length of the longest valid window seen so far
        left = 0        # left edge of the sliding window
        maxf = 0        # highest single-char count seen in any window (never decreased — intentional)

        # right = right edge of the window; expand it one character at a time
        for right in range(len(s)):
            # add the new char to the window; .get(...,0) returns 0 if it's not in the dict yet
            count[s[right]] = 1 + count.get(s[right], 0)
            # update the most frequent char count in the current window
            maxf = max(maxf, count[s[right]])

            # window is invalid if the chars we'd need to replace exceeds k
            # (window size) - (most common char) = chars to replace
            while (right - left + 1) - maxf > k:
                count[s[left]] -= 1     # drop the leftmost char from the window
                left += 1               # shrink the window from the left
            # window is now valid — record its size if it's the biggest so far
            res = max(res, right - left + 1)

        return res      # longest window achievable with at most k replacements