//
// Created by panpi on 29.12.2022.
//

#ifndef KEEPASS2_0_MENU_H
#define KEEPASS2_0_MENU_H

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <conio.h>

class Menu
{
private:
    bool directoryChosen = false;
public:
    void RenderMenu();

    void EnterUserInput();

    void ChangeDirectory();

    void ChooseDirectory();

    bool VerifyKey();
};


#endif //KEEPASS2_0_MENU_H
