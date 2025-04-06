#include "SudokuGame.hpp"

void SudokuGame::start_menu(MenuState &state)
{
    bool terminate = false, path_not_set = true;
    int choice, path;
    std::string file_path;
    while (!terminate)
    {
        std::cout << "-------------------------------------\n";
        std::cout << "     SUDOKU GAME MENU    \n";
        std::cout << "-------------------------------------\n";
        std::cout << "1) Easy Game\n";
        std::cout << "2) Medium Game\n";
        std::cout << "3) Hard Game\n";
        std::cout << "4) Load game from files\n";
        std::cout << "5) Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            temp.assign(9, std::vector<int>(9, 0));
            Board.set_board(temp);
            Generator.Generate(Board, Easy, Solver);
            Solver.solve_copy(Board);
            state = MenuState::MAIN;
            terminate = true;
            break;
        case 2:
            temp.assign(9, std::vector<int>(9, 0));
            Board.set_board(temp);
            Generator.Generate(Board, Medium, Solver);
            Solver.solve_copy(Board);
            state = MenuState::MAIN;
            terminate = true;
            break;
        case 3:
            temp.assign(9, std::vector<int>(9, 0));
            Board.set_board(temp);
            Generator.Generate(Board, Hard, Solver);
            Solver.solve_copy(Board);
            state = MenuState::MAIN;
            terminate = true;
            break;
        case 4:
            while (path_not_set)
            {
                std::cout << "choose file path 1)Easy_demo.txt  2)Medium_demo.txt 3)Hard_demo.txt 4)history.txt 5)Semisolved.txt 6)other :- ";
                std::cin >> path;
                switch (path)
                {
                case 1:
                    file.setFile("../../../data/Easy_demo.txt");
                    path_not_set = false;
                    break;
                case 2:
                    file.setFile("../../../data/Medium_demo.txt");
                    path_not_set = false;
                    break;
                case 3:
                    file.setFile("../../../data/Hard_demo.txt");
                    path_not_set = false;
                    break;
                case 4:
                    file.setFile("../../../data/history.txt");
                    path_not_set = false;
                    break;
                case 5:
                    file.setFile("../../../data/Semisolved.txt");
                    path_not_set = false;
                    break;
                case 6:
                    std::cout << "enter file path:- ";
                    std::cin >> file_path;
                    file.setFile(file_path);
                    path_not_set = false;

                default:
                    std::cout << "choose path from menu choices." << std::endl;
                }
            }
            file.redFromFile(Board);
            if (Board.checkBoardvalidity() && Solver.CheckUniqueSolution(Board))
            {
                Solver.solve_copy(Board);
                state = MenuState::MAIN;
                terminate = true;
            }
            else
            {
                std::cout << "Invalid Board!" << std::endl;
                temp.assign(9, std::vector<int>(9, 0));
                Board.set_board(temp);
                state = MenuState::START;
                terminate = true;
            }
            break;
        case 5:
            std::cout << "Program ends" << std::endl;
            state = MenuState::EXIT;
            terminate = true;
            break;
        default:
            std::cout << "choose integer from menu choices." << std::endl;
        }
    }
}
void SudokuGame::main_menu(MenuState &state)
{
    int choice;
    bool error, terminate = false;
    int row, column, value;
    while (!terminate)
    {
        Board.print();
        error = false;
        std::cout << "\n1) Enter a move \n";
        std::cout << "2) Solve automatically \n";
        std::cout << "3) Load puzzle from history \n";
        std::cout << "4) Save current puzzle to history \n";
        std::cout << "5) New game \n";
        std::cout << "6) Exit \n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";
            std::cin >> row >> column >> value;
            if (row < 1 || row > 9)
            {
                std::cout << "Row must be between 1 and 9. " << std::endl;
                error = true;
            }
            if (column < 1 || column > 9)
            {
                std::cout << "Column must be between 1 and 9. " << std::endl;
                error = true;
            }
            if (value < 1 || value > 9)
            {
                std::cout << "Value must be between 1 and 9. " << std::endl;
                error = true;
            }
            if (!error)
            {
                if (Board.Set(value, row - 1, column - 1))
                {
                    std::cout << "Move accepted!" << std::endl;
                    if (Board.Solved())
                    {
                        Board.print();
                        state = MenuState::SUCCESS;
                        terminate = true;
                    }
                }
                else
                {
                    std::cout << "Move declined!" << std::endl;
                }
            }
            break;
        case 2:
            if (Solver.solve(Board))
            {
                std::cout << "Board solved Automatically!" << std::endl;
                Board.print();
                state = MenuState::SUCCESS;
                terminate = true;
            }
            else
            {
                std::cout << "Board has no solution" << std::endl;
                state = MenuState::START;
                terminate = true;
            }
            break;
        case 3:
            Board.get_board(temp);
            file.setFile("../../../data/history.txt");
            file.redFromFile(Board);
            if (Board.checkBoardvalidity() && Solver.CheckUniqueSolution(Board))
            {
                Solver.solve_copy(Board);
            }
            else
            {
                std::cout << "Invalid Board!" << std::endl;
                Board.set_board(temp);
            }
            break;
        case 4:
            file.setFile("../../../data/history.txt");
            file.writeToFile(Board);
            break;
        case 5:
            state = MenuState::START;
            terminate = true;
            break;
        case 6:
            std::cout << "Saving Progress....Program ends" << std::endl;
            file.setFile("../../../data/history.txt");
            file.writeToFile(Board);
            state = MenuState::EXIT;
            terminate = true;
            break;
        default:
            std::cout << "choose integer from menu choices." << std::endl;
        }
    }
}
void SudokuGame::sucess_menu(MenuState &state)
{
    bool terminate = false;
    int choice;
    while (!terminate)
    {
        std::cout << "-------------------------------------\n";
        std::cout << "     CONGRATULATIONS    \n";
        std::cout << "-------------------------------------\n";
        std::cout << "1) New Game\n";
        std::cout << "2) Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            state = MenuState::START;
            terminate = true;
            break;
        case 2:
            std::cout << "Program ends" << std::endl;
            state = MenuState::EXIT;
            terminate = true;
            break;
        default:
            std::cout << "choose integer from menu choices." << std::endl;
        }
    }
}

void FileManger::writeToFile(SudokuBoard &Board)
{
    outputFile.open(fileName, std::ios::trunc);
    if (outputFile.is_open())
    {
        Board.saveToFile(outputFile);
        std::cout << "Sudoku board saved successfully" << std::endl;
        outputFile.close();
    }
    else
    {
        std::cout << "Error:Could not open file for writing!" << std::endl;
    }
}

void FileManger::redFromFile(SudokuBoard &Board)
{
    inputFile.open(fileName);
    if (inputFile.is_open())
    {
        Board.loadFromFile(inputFile);
        std::cout << "Sudoku board loaded successfully" << std::endl;
        inputFile.close();
    }
    else
    {
        std::cout << "Error:Could not open file for reading!" << std::endl;
    }
}
void FileManger::setFile(const std::string &name)
{
    fileName = name;
}