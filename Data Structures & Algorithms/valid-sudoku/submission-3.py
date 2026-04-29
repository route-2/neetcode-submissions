class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # one integer per row/col/box, each bit represents a digit 1-9
        # 0 means nothing seen yet  eg: 000000000
        rows    = [0] * 9
        cols    = [0] * 9
        squares = [0] * 9

        for r in range(9):
            for c in range(9):
                
                # skip empty cells
                if board[r][c] == ".":
                    continue

                # convert char to 0-based bit position
                # '1'->0, '2'->1, ... '9'->8
                val = int(board[r][c]) - 1

                # 1 << val creates a unique bitmask for this digit
                # eg: digit '5' -> val=4 -> 1<<4 -> 000010000

                # CHECK: if this bit is already ON, digit was seen before -> invalid
                if (1 << val) & rows[r]:
                    return False
                if (1 << val) & cols[c]:
                    return False
                if (1 << val) & squares[(r // 3) * 3 + (c // 3)]:
                    return False

                # MARK: turn this bit ON in all three trackers
                # |= turns the bit on without affecting other bits
                rows[r]    |= (1 << val)   # mark digit seen in this row
                cols[c]    |= (1 << val)   # mark digit seen in this col
                squares[(r // 3) * 3 + (c // 3)] |= (1 << val)  # mark digit seen in this box

        # all 81 cells passed, board is valid
        return True