//
// Created by qivi on 12/6/18.
//

#ifndef ZAD_4_ZMPO_READFILE_H
#define ZAD_4_ZMPO_READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Knapsack.h"

#define MAX_WEIGHT 1000000
#define MAX_VALUE 1000000


using namespace std;


class ReadFile {

private:
    bool good(int N);
    bool good(double N);

public:
     Knapsack* readfile();
     void again();


};



#endif //ZAD_4_ZMPO_READFILE_H
