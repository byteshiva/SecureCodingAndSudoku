import sys
import os
import unittest

# Add the root directory to the system path
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from sudoku.solver import solve_sudoku
from sudoku.printer import print_board

class TestSolver(unittest.TestCase):
    def test_solve_sudoku(self):
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
        solve_sudoku(board)
        expected_board = [
            [6, 3, 2, 9, 5, 7, 8, 4, 1],
            [4, 9, 1, 6, 8, 2, 5, 7, 3],
            [7, 8, 5, 3, 4, 1, 2, 6, 9],
            [2, 4, 8, 5, 7, 9, 3, 1, 6],
            [3, 1, 9, 2, 6, 4, 7, 8, 5],
            [5, 7, 6, 8, 1, 3, 9, 2, 4],
            [1, 2, 4, 7, 9, 5, 6, 3, 8],
            [9, 6, 7, 4, 3, 8, 1, 5, 2],
            [8, 5, 3, 1, 2, 6, 4, 9, 7]
        ]
        self.assertEqual(board, expected_board)

if __name__ == '__main__':
    unittest.main()
