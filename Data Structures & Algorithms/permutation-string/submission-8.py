class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m = len(s1)
        n = len(s2)

        # edge case: s1 can't be a substring permutation if it's longer than s2
        if m > n:
            return False
        
        # PHASE 1 — build first window
        # count letters in all of s1, and first m chars of s2
        s1count, s2count = [0] * 26, [0] * 26
        for i in range(m):
            s1count[ord(s1[i]) - ord('a')] += 1
            s2count[ord(s2[i]) - ord('a')] += 1
        
        # PHASE 2 — initial matches check
        # how many of the 26 letters already have equal counts?
        matches = 0
        for i in range(26):
            matches += (1 if s1count[i] == s2count[i] else 0)
        
        # PHASE 3 — slide window from m to n
        l = 0
        for r in range(m, n):

            # if all 26 letters match, current window is a permutation
            if matches == 26:
                return True
            
            # ADD right character into window
            index = ord(s2[r]) - ord('a')
            s2count[index] += 1
            if s1count[index] == s2count[index]:
                matches += 1        # count just became equal, gained a match
            elif s1count[index] + 1 == s2count[index]:
                matches -= 1        # count was equal before increment, now too large, lost a match

            # REMOVE left character from window
            index = ord(s2[l]) - ord('a')
            s2count[index] -= 1
            if s1count[index] == s2count[index]:
                matches += 1        # count just became equal, gained a match
            elif s1count[index] - 1 == s2count[index]:
                matches -= 1        # count was equal before decrement, now too small, lost a match

            l += 1                  # shrink window from left to keep size m

        # PHASE 4 — check last window
        # loop ends before checking the final window position, so check it here
        return matches == 26