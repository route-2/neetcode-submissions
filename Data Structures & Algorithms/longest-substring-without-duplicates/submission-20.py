class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = [0] * 128
        l, res = 0,0

        for r in range(len(s)):
            count[ord(s[r])]+=1

            while count[ord(s[r])]>1:
                count[ord(s[l])]-=1
                l+=1
            
            res = max(res,r-l+1)
        
        return res


        