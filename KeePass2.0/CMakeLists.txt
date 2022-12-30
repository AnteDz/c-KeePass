cmake_minimum_required(VERSION 3.23)
project(KeePass2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(KeePass2_0 main.cpp Menu.cpp Menu.h CommandManager.cpp CommandManager.h FileOperator.cpp FileOperator.h PasswordOperator.cpp PasswordOperator.h)
