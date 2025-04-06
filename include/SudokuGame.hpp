#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H

enum class MenuState
{
    START,
    MAIN,
    SUCCESS,
    EXIT
};

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SudokuGenerator.hpp"

class FileManger
{
private:
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string fileName;

public:
    void writeToFile(SudokuBoard &Board);
    void redFromFile(SudokuBoard &Board);
    void setFile(const std::string &name);
};

class SudokuGame
{
private:
    SudokuBoard Board;
    SudokuSolver Solver;
    SudokuGenerator Generator;
    FileManger file;
    std::vector<std::vector<int>> temp;
public:
    void main_menu(MenuState &state);
    void sucess_menu(MenuState &state);
    void start_menu(MenuState &state);
};

#endif