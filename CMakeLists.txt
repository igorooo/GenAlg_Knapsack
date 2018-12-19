cmake_minimum_required(VERSION 3.12)
project(ZAD_5_zmpo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ZAD_5_zmpo
        CGeneticAlgorithm.cpp
        CGeneticAlgorithm.h
        CIndividual.cpp
        CIndividual.h
        CKnapsackProblem.cpp
        CKnapsackProblem.h
        Knapsack.cpp
        Knapsack.h
        main.cpp
        ReadFile.cpp
        ReadFile.h
        test
        test2
        values)
