class Solution:
    def countBits(self, n: int) -> List[int]:
        result = []
        
        for i in range(n + 1):
            # Count 1s in i using hamming weight trick
            num = i
            count = 0
            while num > 0:
                num = num & (num - 1)
                count += 1
            result.append(count)
        
        return result