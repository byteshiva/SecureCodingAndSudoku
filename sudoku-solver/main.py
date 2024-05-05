import json
from sudoku.printer import print_board
from sudoku.solver import solve_sudoku

# Defining the constant
CONFIG_JSON_PATH = 'config/config.json'

if __name__ == '__main__':
    with open(CONFIG_JSON_PATH) as f:
        config = json.load(f)

    for board in config['boards']:
        print(f"\n{board['name']} Sudoku board ({board['difficulty']} difficulty):")
        print_board(board['values'])
        solve_sudoku(board['values'])
        print("\nSolution:")
        print_board(board['values'])
