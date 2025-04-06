#include "SudokuBoard.hpp"

bool SudokuBoard::Checkvalidity(int value, int row, int column)
{
    int i, j;
    for (i = 0; i < 9; i++) // row/column check
    {
        if (value == Board[row][i])
        {
            return false;
        }
        if (value == Board[i][column])
        {
            return false;
        }
    }
    int startrow = (row / 3) * 3;
    int startcolumn = (column / 3) * 3;
    for (i = startrow; i < startrow + 3; i++) // 3×3 constraints check
    {
        for (j = startcolumn; j < startcolumn + 3; j++)
        {
            if (value == Board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
SudokuBoard::SudokuBoard() : Board(9, std::vector<int>(9, 0)), Solved_Board(9, std::vector<int>(9, 0)) {}

bool SudokuBoard::Set(int value, int row, int column)
{
    if (Board[row][column]==0 && Checkvalidity(value, row, column) && Correct_play(value, row, column))
    {
        Board[row][column] = value;
        return true;
    }
    else
    {
        return false;
    }
}
void SudokuBoard::print()
{
    std::cout << "------------------------------------- " << std::endl;
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            std::cout << "------------------------------------- " << std::endl;
        for (int j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6)
                std::cout << " |";
            Board[i][j] == 0 ? std::cout << "." : std::cout << Board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------- " << std::endl;
}
void SudokuBoard::saveToFile(std::ofstream &outputFile)
{
    outputFile << "------------------------------------- " << std::endl;
    for (int i = 0; i < 9; i++)
    {
        if (i == 3 || i == 6)
            outputFile << "------------------------------------- " << std::endl;
        for (int j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6)
                outputFile << " |";
            Board[i][j] == 0 ? outputFile << "." : outputFile << Board[i][j];
        }
        outputFile << std::endl;
    }
    outputFile << "------------------------------------- " << std::endl;
}
void SudokuBoard::loadFromFile(std::ifstream &inputFile)
{
    char ch;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            while (inputFile.get(ch))
            {
                if (ch >= '1' && ch <= '9')
                {
                    Board[i][j] = ch - '0';
                    break;
                }
                else if (ch == '.')
                {
                    Board[i][j] = 0;
                    break;
                }
            }
        }
    }
}
bool SudokuBoard::Solved()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (Board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
bool SudokuBoard::Correct_play(int value, int row, int column)
{
    if (value == Solved_Board[row][column])
    {
        return true;
    }
    else
    {
        return false;
    }
}
void SudokuBoard::get_board(std::vector<std::vector<int>> &board)
{
    board = Board;
}
void SudokuBoard::set_board(const std::vector<std::vector<int>> &board)
{
    Board = board;
}
bool SudokuBoard::checkBoardvalidity()
{
    int temp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (Board[i][j] != 0)
            {
                temp = Board[i][j];
                Board[i][j] = 0;
                if (!Checkvalidity(temp, i, j))
                {
                    return false;
                }
                Board[i][j] = temp;
            }
        }
    }
    return true;
}