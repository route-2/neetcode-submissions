class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        

        for word in strs:
            
            count = [0]*26
            for c in word:
                count[ord(c)-ord('a')]+=1
            key = tuple(count)# <-- snapshot AFTER filling counts
            res[key].append(word)
        return list(res.values())
        
                



        
