class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:

        #transpose
        for i in range(len(matrix)):
            for j in range(i+1,len(matrix[0])):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = tmp
        
        # reverse each row
        # For a row of length n, you only need to swap 
        # the first n/2 elements with the last n/2 elements 
        # to reverse the entire row.
        # (till the midpoint)
        n = len(matrix)
        for i in range(len(matrix)):
            for j in range(len(matrix)//2):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[i][n-j-1]
                matrix[i][n-j-1] = tmp




        