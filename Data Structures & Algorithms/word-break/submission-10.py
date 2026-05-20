class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        # dp[i] = can we form s[0:i]?
        dp = [False] * (n + 1)
        dp[0] = True  # Empty string is valid
        
        # For each position in string
        for i in range(1, n + 1):
            # For each word in dictionary
            for word in wordDict:
                # Check if this word matches at position (i - len(word))
                word_len = len(word)
                
                # Does the word fit and match?
                if word_len <= i and s[i - word_len:i] == word and dp[i - word_len]:
                    dp[i] = True
                    break  # Found a valid word, move to next position
        
        return dp[n]