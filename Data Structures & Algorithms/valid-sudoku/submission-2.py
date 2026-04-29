class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [[False]*9 for _ in range(9)]
        cols = [[False]*9 for _ in range(9)]
        boxes = [[False]*9 for _ in range(9)]

        for r in range(9):
            for c in range(9):
                ch = board[r][c]
                if ch == '.':
                    continue
                
                d = int(ch) - 1
                b = (r//3) * 3 + c//3

                if rows[r][d] or cols[c][d] or boxes[b][d] :
                    return False
                
                rows[r][d] = cols[c][d] = boxes[b][d] = True
        
        return True


        