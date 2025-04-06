#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include "SudokuBoard.hpp"

class SudokuSolver
{
private:
//helper function
    void SolutionCounter(SudokuBoard& board,int& soltions);
public:
    bool solve(SudokuBoard& board);         // solve board
    void solve_copy(SudokuBoard& board);   // solve solved_board
    bool CheckUniqueSolution(SudokuBoard board); // check the board is solvable with unique solution
};

#endif