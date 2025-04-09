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
<pre><code>soduku_project/ ├── data/ # Sample input/output puzzles and test data ├── include/ │ ├── SudokuBoard.hpp # Board representation and utilities │ ├── SudokuGame.hpp # Game manager class │ ├── SudokuGenerator.hpp # Puzzle generation logic │ └── SudokuSolver.hpp # Solver logic (backtracking algorithm) ├── src/ │ ├── SudokuBoard.cpp │ ├── SudokuGame.cpp │ ├── SudokuGenerator.cpp │ └── SudokuSolver.cpp ├── CMakeLists.txt # CMake build configuration └── .gitignore # Git ignore rules </code></pre>

