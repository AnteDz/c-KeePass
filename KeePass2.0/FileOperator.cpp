#include "FileOperator.h"

void FileOperator::SetFilePath(const std::string& path) {
    FileOperator::filePath = path;
}

std::string &FileOperator::GetFilePath() {
    return FileOperator::filePath;
}

std::string FileOperator::Encrypt(const std::string Encrypt) {

    std::string temp;
    for (char i : Encrypt) {
        char encrypted = (char) ((int)i + key);
        temp += encrypted;
    }
    return temp;
}

std::string FileOperator::Decrypt(const std::string Encrypt) {
    std::string temp;
    for (char i : Encrypt) {
        char encrypted = (char) ((int)i - key);
        temp += encrypted;
    }
    return temp;
}

void FileOperator::CreateFile(const std::string &file) {
    int inp;
    std::cout << "Enter a new secret key (number):";
    std::cin >> inp;
    FileOperator::UpdateKey(inp);
    FileOperator::UpdateTimestamp();

    std::ofstream writeStream;
    writeStream.open(file);
    writeStream << FileOperator::month << FileOperator::Encrypt("[key]") << std::endl;
    writeStream << FileOperator::day << FileOperator::Encrypt("jukan:lkasjdlkasjdlkasjdas") << std::endl;
    writeStream << FileOperator::year << FileOperator::Encrypt("akhw:SAD!ds!@#jh1asd@#1") << std::endl;
    writeStream << FileOperator::hour << FileOperator::Encrypt("kiqt:sakq,1sa") << std::endl;
    writeStream << FileOperator::min << FileOperator::Encrypt("bad:dlaj,1ks9,sad") << std::endl;
    writeStream.close();
}

void FileOperator::UpdateTimestamp() {
    std::time_t now = time(0);
    std::tm *local = std::localtime(&now);

    FileOperator::month = 1 + local->tm_mon;
    FileOperator::day = local->tm_mday;
    FileOperator::year = 1900 + local->tm_year - 2000;
    FileOperator::hour = local->tm_hour;
    FileOperator::min = local->tm_min;
}

void FileOperator::UpdateKey(int key) {
    FileOperator::key = key;
}