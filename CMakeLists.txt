cmake_minimum_required(VERSION 3.21)
project(Project_Phrases_Generator C)

set(CMAKE_C_STANDARD 99)

add_executable(Test_Projet main.c functions.c functions.h Trees.c Trees.h Generator.c Generator.h)
