#include "SudokuGenerator.hpp"
#include <random>
#include <vector>
#include <algorithm>

bool SudokuGenerator::solveSudoku(SudokuBoard &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board.Board[row][col] == 0)
            {
                std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                std::random_device rd;
                std::mt19937 rng(rd());
                shuffle(numbers.begin(), numbers.end(), rng); // Shuffle for randomness

                for (int i=0;i<9;i++)
                {
                    if (board.Checkvalidity(numbers[i], row, col))
                    {
                        board.Board[row][col] = numbers[i];
                        if (solveSudoku(board))
                        {
                            return true;
                        }
                        else
                        {
                        board.Board[row][col] = 0; 
                        }
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}
void SudokuGenerator::removeNumbers(SudokuBoard &board, int difficulty,SudokuSolver& solver)
{
    int removeCount = 9*9-difficulty,temp; //want only have clues equal difficulty number
    std::random_device rd;
    std::mt19937 gen(rd());

    while (removeCount != 0)
    {
        int row = gen() % 9;
        int col = gen() % 9;
        if (board.Board[row][col] != 0)
        {
            temp= board.Board[row][col];
            board.Board[row][col] = 0;

            if (solver.CheckUniqueSolution(board))
            {
                removeCount--; 
            }
            else
            {
                board.Board[row][col] = temp;
            }
        }
    }
}
void SudokuGenerator::Generate(SudokuBoard &board, int difficulty,SudokuSolver& solver)
{
    solveSudoku(board);//generate random solved board
    removeNumbers(board,difficulty,solver);//remove clues until having only rquired number while maintaing unique solution
}