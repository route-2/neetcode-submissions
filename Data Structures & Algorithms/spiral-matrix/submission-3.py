class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        
        # Track boundaries
        top = 0
        bottom = len(matrix) - 1
        left = 0
        right = len(matrix[0]) - 1
        
        while top <= bottom and left <= right:
            # 1. Go RIGHT (top row, left to right)
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1
            
            # 2. Go DOWN (right column, top to bottom)
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1
            
            # 3. Go LEFT (bottom row, right to left)
            # Check if there's still a row to process
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1
            
            # 4. Go UP (left column, bottom to top)
            # Check if there's still a column to process
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1
        
        return result