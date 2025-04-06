#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"

//filled numbers for each difficulty 
#define Easy 35
#define Medium 30
#define Hard 25

class SudokuGenerator
{
    private:
    //helper function
    bool solveSudoku(SudokuBoard& board);
    void removeNumbers(SudokuBoard& board,int difficulty,SudokuSolver& solver);
    public:
    void Generate(SudokuBoard& board,int difficulty,SudokuSolver& solver);
};

#endif