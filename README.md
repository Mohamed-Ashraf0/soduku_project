# Sudoku Project

A modular C++ implementation of the classic **Sudoku** puzzle game. This project includes the ability to generate Sudoku puzzles, solve them using backtracking, and verify their validity.

## 🧩 Features

### ✅ Sudoku Solver
- Uses backtracking to find solutions for valid Sudoku puzzles.
- Can solve puzzles of varying difficulty levels.

### 🎲 Puzzle Generator
- Randomly generates Sudoku puzzles with unique solutions.
- Ensures logical consistency and puzzle validity.

### 🧪 Validator
- Verifies if a given puzzle configuration is valid according to Sudoku rules:
  - No repeating numbers in rows, columns, or 3×3 subgrids.

### 🔧 Modular Design
- Separated into well-defined components:
  - `SudokuBoard` – Handles board operations.
  - `SudokuSolver` – Implements solving logic.
  - `SudokuGenerator` – Generates puzzles with varying levels of difficulty.
  - `SudokuGame` – Manages overall game logic.
## 🗂️ Project Structure
- `src/`: Contains the C++ source files implementing the Sudoku board, solver, generator, and game logic.
- `include/`: Header files defining the interfaces for each module.
- `data/`: Sample Sudoku puzzles and data used for testing.
- `CMakeLists.txt`: Build configuration file for compiling the project using CMake.
- `.gitignore`: Specifies untracked files to be ignored by Git.
- `README.md`: Project documentation and usage instructions.
