//
// Created by qivi on 12/4/18.
//

#ifndef ZAD_4_ZMPO_KNAPSACK_H
#define ZAD_4_ZMPO_KNAPSACK_H

#include <iostream>
#include <vector>

#define ARR_LEN(ar) (sizeof(ar) / sizeof(*ar))

using namespace std;

class Knapsack {

private:
    int N_ITEMS;
    double MAX_LOAD;
    vector<double> WEIGHT_OF_ITEMS;
    vector<double> VALUE_OF_ITEMS;

public:
    int n_items();
    double max_load();
    double weight_of_item(int POS);
    double value_of_item(int POS);
    int size();

    Knapsack(int N_ITEMS, double MAX_LOAD, vector<double> WEIGHTS, vector<double> VALUES);
    ~Knapsack();


};


#endif //ZAD_4_ZMPO_KNAPSACK_H
