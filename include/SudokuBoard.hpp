#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>
#include <iostream>
#include <iostream>
#include <stdexcept>
#include <fstream>

class SudokuBoard
{
private:
    std::vector<std::vector<int>> Board;
    std::vector<std::vector<int>> Solved_Board;
    // helper function
    bool Checkvalidity(int value, int row, int column);//check the number dont break uniuqnness constrain
    bool Correct_play(int value, int row, int column);//check the number is correct to reach final solution
    friend class SudokuSolver;
    friend class SudokuGenerator;
public:
    SudokuBoard();
    bool Solved();//check that board has been solved
    bool checkBoardvalidity();//check loaded board is valied
    bool Set(int value, int row, int column);
    void get_board(std::vector<std::vector<int>>& board);
    void set_board(const std::vector<std::vector<int>>& board);
    void print();
    void saveToFile(std::ofstream& outputFile);
    void loadFromFile(std::ifstream& inputFile);
};

#endif