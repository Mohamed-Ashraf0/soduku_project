#include "SudokuSolver.hpp"

bool SudokuSolver::solve(SudokuBoard &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board.Board[i][j] == 0)
            {
                for (int choosen_num = 1; choosen_num < 10; choosen_num++)
                {
                    if (board.Checkvalidity(choosen_num, i, j))
                    {
                        board.Board[i][j] = choosen_num;
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            board.Board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void SudokuSolver::SolutionCounter(SudokuBoard &board, int &soltions)
{
    if (soltions > 1)
    {
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board.Board[i][j] == 0)
            {
                for (int choosen_num = 1; choosen_num < 10; choosen_num++)
                {
                    if (board.Checkvalidity(choosen_num, i, j))
                    {
                        board.Board[i][j] = choosen_num;
                        SolutionCounter(board, soltions);
                        board.Board[i][j] = 0;
                        if (soltions > 1)
                        {
                            return;
                        }
                    }
                }
                return;
            }
        }
    }
    soltions++;
}
bool SudokuSolver::CheckUniqueSolution(SudokuBoard board)
{
    int solutions = 0;
    SolutionCounter(board, solutions);
    return solutions == 1; // just return true if one valid solution
}
void SudokuSolver::solve_copy(SudokuBoard& board)
{
    std::vector<std::vector<int>> temp=board.Board;
    (*this).solve(board);
    board.Solved_Board=board.Board;
    board.Board=temp;
}
