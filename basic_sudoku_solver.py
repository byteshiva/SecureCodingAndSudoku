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

def print_board(board):
    for row in board:
        print(row)

if __name__ == '__main__':
    # Test the solver with the easy example
    board = [
        [0, 1, 3, 8, 0, 0, 4, 0, 5],
        [0, 2, 4, 6, 0, 5, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 9, 3, 0],
        [4, 9, 0, 3, 0, 6, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 5, 0, 0],
        [0, 0, 0, 7, 0, 1, 0, 9, 3],
        [0, 6, 9, 0, 0, 0, 7, 4, 0],
        [0, 0, 0, 2, 0, 7, 6, 8, 0],
        [1, 0, 2, 0, 0, 8, 3, 5, 0]
    ]

    print("\nEasy Sudoku board:")
    print_board(board)
    solve_sudoku(board)
    print("\nSolution:")
    print_board(board)


    # Test the solver with the difficult example
    board = [
        [0, 0, 2, 0, 0, 0, 0, 4, 1],
        [0, 0, 0, 0, 8, 2, 0, 7, 0],
        [0, 0, 0, 0, 4, 0, 0, 0, 9],
        [2, 0, 0, 0, 7, 9, 3, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 8, 0],
        [0, 0, 6, 8, 1, 0, 0, 0, 4],
        [1, 0, 0, 0, 9, 0, 0, 0, 0],
        [0, 6, 0, 4, 3, 0, 0, 0, 0],
        [8, 5, 0, 0, 0, 0, 4, 0, 0]
    ]

    print("\nDifficult Sudoku board:")
    print_board(board)
    solve_sudoku(board)
    print("\nSolution:")
    print_board(board)
