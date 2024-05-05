def is_valid(board, row, col, num):
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False
    start_row = row - row % 3
    start_col = col - col % 3
    for i in range(3):
        for j in range(3):
            if board[i + start_row][j + start_col] == num:
                return False
    return True

def solve_sudoku(board, row=0, col=0):
    if row == 9:
        return True
    if col == 9:
        return solve_sudoku(board, row + 1, 0)
    if board[row][col] != 0:
        return solve_sudoku(board, row, col + 1)
    for num in range(1, 10):
        if is_valid(board, row, col, num):
            board[row][col] = num
            if solve_sudoku(board, row, col + 1):
                return True
        board[row][col] = 0
    return False
