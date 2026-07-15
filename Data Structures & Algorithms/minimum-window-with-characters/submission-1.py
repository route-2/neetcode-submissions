class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""

        need = [0] * 128
        for char in t:
            need[ord(char)] += 1

        count = len(t)          # characters from t still needed
        left = 0
        min_len = float('inf')
        start = 0

        for right in range(len(s)):
            # include s[right] in the window
            if need[ord(s[right])] > 0:
                count -= 1
            need[ord(s[right])] -= 1

            # window is valid — try to shrink from the left
            while count == 0:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    start = left
                # remove s[left] from the window
                need[ord(s[left])] += 1
                if need[ord(s[left])] > 0:
                    count += 1
                left += 1

        return "" if min_len == float('inf') else s[start:start + min_len]