class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return s

        start = 0
        maxLen = 1

        def expand(left, right):
            nonlocal maxLen, start  #  Allow outer variable modification
            
            while left >= 0 and right < n and s[left] == s[right]:
                currLen = right - left + 1
                if currLen > maxLen:
                    maxLen = currLen
                    start = left
                left -= 1
                right += 1

        for i in range(n):
            expand(i, i)          # Odd length palindromes (single center)
            expand(i, i + 1)      # Even length palindromes (double center)

        return s[start:start + maxLen]  #  Use slicing, not substr()