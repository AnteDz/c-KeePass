//
// Created by panpi on 29.12.2022.
//

#ifndef KEEPASS2_0_FILEOPERATOR_H
#define KEEPASS2_0_FILEOPERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <bits/stdc++.h>

class FileOperator {
private:
    inline static std::string filePath;
    inline static int key;
    inline static int month;
    inline static int day;
    inline static int year;
    inline static int hour;
    inline static int min;

public:
    static void SetFilePath(const std::string& path);

    static std::string& GetFilePath();

    static std::string Encrypt(const std::string Encrypt);

    static std::string Decrypt(const std::string Encrypt);

    static void CreateFile(const std::string &file);

    static void UpdateTimestamp();

    static void UpdateKey(int key);
};


#endif //KEEPASS2_0_FILEOPERATOR_H
