#include <iostream>

#include "SudokuGame.hpp"

int main()
{
    MenuState state = MenuState::START;
    SudokuGame game;
    while (state != MenuState::EXIT)
    {
        switch (state)
        {
        case MenuState::START:
            game.start_menu(state);
            break;
        case MenuState::MAIN:
            game.main_menu(state);
            break;
        case MenuState::SUCCESS:
            game.sucess_menu(state);
            break;
        default:
            break;
        }
    }
}