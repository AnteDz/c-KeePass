//
// Created by panpi on 29.12.2022.
//

#ifndef KEEPASS2_0_COMMANDMANAGER_H
#define KEEPASS2_0_COMMANDMANAGER_H

#include <vector>
#include <string>
#include "FileOperator.h"
#include "PasswordOperator.h"

class CommandManager {
public:
    static void FindPasswords();

    static void SortPasswords();

    static void AddPassword();

    static void EditPassword();

    static void DeletePassword();

    static void AddCategory();

    static bool AddCategory(const std::string& category);

    static void DeleteCategory(const std::string& category);
};

#endif //KEEPASS2_0_COMMANDMANAGER_H
