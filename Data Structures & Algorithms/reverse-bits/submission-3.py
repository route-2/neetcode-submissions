class Solution:
    def reverseBits(self, n: int) -> int:
        # Step 1: Build binary string from LSB to MSB
        binary = ""
        for i in range(32):
            if n & (1 << i):
                binary += '1'
            else:
                binary += '0'
        
        # Step 2: Build result by reading string backwards
        result = 0
        for i in range(32):
            if binary[31 - i] == '1':
                result |= (1 << i)
        
        return result