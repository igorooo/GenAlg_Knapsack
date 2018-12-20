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
        values CMENU/CMenuItem.cpp CMENU/CMenuItem.h CMENU/CMenu.cpp CMENU/CMenu.h CMENU/CCommand.cpp CMENU/CCommand.h CMENU/CMenuCommand.cpp CMENU/CMenuCommand.h CMENU/KNPmenu.cpp CMENU/KNPmenu.h)
