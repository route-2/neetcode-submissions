class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}      # plain dict, no keys
        res = 0
        left = 0
        maxf = 0


        for right in range(len(s)):
            count[s[right]]=1+count.get(s[right],0)   # .get supplies 0 if missing
            maxf = max(maxf,count[s[right]])          # most frequent char in window

            while(right-left+1)-maxf > k:             # invalid: replacements > k
                count[s[left]]-=1
                left+=1
            res = max(res,right-left+1)               # track longest valid window

        return res