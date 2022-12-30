//
// Created by panpi on 29.12.2022.
//

#include "Menu.h"
#include "FileOperator.h"
#include "CommandManager.h"

void Menu::RenderMenu()
{
    if (!directoryChosen) {
        return Menu::ChooseDirectory();
    }
    if (!Menu::VerifyKey()) {
        std::cout << "Wrong key!" << std::endl;
        return Menu::RenderMenu();
    }
    std::cout << "[1] Search Password" << std::endl;
    std::cout << "[2] Sort Password" << std::endl;
    std::cout << "[3] Add Password" << std::endl;
    std::cout << "[4] Edit Password" << std::endl;
    std::cout << "[5] Delete Password" << std::endl;
    std::cout << "[6] Add Category" << std::endl;
    std::cout << "[7] Change Directory" << std::endl;
    std::cout << "[8] Exit" << std::endl;

    return EnterUserInput();
}

void Menu::EnterUserInput()  {
    std::cout << "Enter Input:";

    int input;
    std::cin >> input;

    switch (input) {
        case 1:
            CommandManager::FindPasswords();
            break;
        case 2:
            CommandManager::SortPasswords();
            break;
        case 3:
            CommandManager::AddPassword();
            break;
        case 4:
            CommandManager::EditPassword();
            break;
        case 5:
            CommandManager::DeletePassword();
            break;
        case 6:
            CommandManager::AddCategory();
            break;
        case 7:
            ChangeDirectory();
        case 8:
            exit(0);
        default:
            return EnterUserInput();
    }
}

void Menu::ChangeDirectory() {
}

void Menu::ChooseDirectory() {
    std::string fileName, filePath;
    char confirm;
    std::cout << "Which directory you want to open?";
    std::cin >> fileName;

    if (fileName.length() > 1 && fileName.at(1) == ':') {
        filePath = (std::filesystem::current_path() / (fileName + ".txt")).generic_string();
    }
    else {
        filePath = fileName;
    }

    if(!std::filesystem::exists(filePath)) {
        std::cout << "You're about to create new file!" << std::endl;
    }

    printf("Are you sure you want to open \n%s ? y/n:", filePath.c_str());
    std::cin >> confirm;

    if (confirm == 'y') {
        FileOperator::SetFilePath(filePath);
        if (!std::filesystem::exists(filePath)) {
            FileOperator::CreateFile(filePath);
        }

        Menu::directoryChosen = true;
        return this->RenderMenu();
    }
    return this->ChooseDirectory();
}

bool Menu::VerifyKey() {
    std::string line, part;
    std::ifstream readStream;
    int key;

    std::cout << "Enter a key to open a file:";
    std::cin >> key;
    FileOperator::UpdateTimestamp();
    readStream.open(FileOperator::GetFilePath());
    std::getline(readStream, line);

    if (line.length() == 6) {
        part = line.substr(1, line.length()-1);
    }
    else {
        part = line.substr(2, line.length()-2);
    }
    readStream.close();

    if (FileOperator::Decrypt(part) == "[key]") {
        return true;
    }
    return false;
}