# Sudoku Solver

A simple Sudoku solver implemented in Python.

## Installation

To install the Sudoku solver, clone this repository and install the required packages:

```
git clone https://github.com/byteshiva/SecureCodingAndSudoku.git
cd sudoku-solver

```


# Development Environment with Python and Clang

This Nix Flake configuration sets up an isolated development environment with Python 3.9 and Clang (from LLVM packages version 18). Here's how to use it:

1. Run `nix develop` in your terminal. This command starts a new isolated development environment based on your Nix Flake configuration.

```bash
$ nix develop
```

2. After running step 1, you will be in the new environment. This environment includes Python 3.9 and Clang, which you can use for compilation and debugging. The necessary environment variables are set automatically, so you can start working right away.

For example, you can compile C programs using `clang`, and run Python scripts using `python3`. Additionally, you can use Clang for static analysis on your C files.


## Usage

To solve a Sudoku board, run the `main.py` script with the path to a config file as an argument:


## Contributing

Contributions are welcome! Please open an issue or a pull request to suggest changes or report bugs.

## License

This project is licensed under the Apache License.

