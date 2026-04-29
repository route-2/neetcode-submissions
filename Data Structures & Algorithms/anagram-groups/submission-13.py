from collections import defaultdict
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # hashmap: key -> list of anagrams
        mp = defaultdict(list)

        for s in strs:
            # create frequency array for 26 lowercase letters
            count = [0] * 26

            # count frequency of each character
            for c in s:
                # map 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
                count[ord(c) - ord('a')] += 1

            # convert list to tuple (so it can be used as dict key)
            key = tuple(count)

            # append string to corresponding anagram group
            mp[key].append(s)

        # return all grouped anagrams
        return list(mp.values())