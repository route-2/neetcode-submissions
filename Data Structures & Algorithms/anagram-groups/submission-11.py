from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
         mp = defaultdict(list)
       

         for s in strs:
            count = [0] * 26
            for c in s:
                count [ord(c)-ord('a')]+=1

            key = tuple(count)

            mp[key].append(s)
            
         return list(mp.values())




        