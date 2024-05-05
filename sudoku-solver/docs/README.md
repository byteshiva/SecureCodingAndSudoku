# Sudoku Solver Architecture and Design

This document describes the architecture and design decisions made for the Sudoku solver project.

## Architecture

The Sudoku solver is implemented as a Python package called `sudoku`. The package contains two modules: `printer` and `solver`. The `printer` module provides a function for printing Sudoku boards, and the `solver` module provides a function for solving Sudoku boards.

The `main.py` script loads a config file containing one or more Sudoku boards, solves each board using the `solve_sudoku` function from the `solver` module, and prints the solutions using the `print_board` function from the `printer` module.

## Design Decisions

### Backtracking Algorithm

The Sudoku solver uses a backtracking algorithm to solve Sudoku boards. The algorithm works by iteratively filling in the next empty cell on the board with a valid number, and then recursively calling itself to fill in the remaining cells. If a cell cannot be filled in with a valid number, the algorithm backtracks to the previous cell and tries a different number.

### Config File Format

The Sudoku solver uses a JSON config file to specify the Sudoku boards to be solved. The config file contains an array of board objects, each of which has a `name`, `difficulty`, and `values` field. The `name` field is a string that identifies the board, the `difficulty` field is a string that specifies the difficulty level of the board, and the `values` field is a 2D array that specifies the initial values of the board.

### Test-Driven Development

The Sudoku solver was developed using test-driven development (TDD). The `test_solver.py` file contains unit tests for the `solve_sudoku` function, and the `run_tests.sh` script runs the unit tests using the `unittest` module.

## Future Work

Possible areas for future work include:

* Optimizing the backtracking algorithm to improve performance on large or difficult boards.

