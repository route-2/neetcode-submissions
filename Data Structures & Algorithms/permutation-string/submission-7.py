class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m = len(s1)
        n = len(s2)
        if m>n:
            return False
        
        s1count,s2count = [0] * 26 , [0] * 26

        for i in range(m):
            s1count[ord(s1[i])-ord('a')]+=1
            s2count[ord(s2[i])-ord('a')]+=1
        
        matches=0
        for i in range(26):
            matches+=(1 if s1count[i]==s2count[i] else 0)
        
        l = 0
        for r in range(m,n):
            if matches == 26:
                return True
            
            index = ord(s2[r]) - ord('a')
            s2count[index]+=1
            if s1count[index]==s2count[index]:
                matches+=1
            elif s1count[index]+1==s2count[index]:
                matches-=1

            index = ord(s2[l])-ord('a')
            s2count[index]-=1
            if s1count[index]==s2count[index]:
                matches+=1
            elif s1count[index]-1==s2count[index]:
                matches-=1
            l+=1
        
        return matches ==26


        
        