//
// Created by qivi on 12/4/18.
//

#include "Knapsack.h"

int Knapsack::n_items() {
    return this->N_ITEMS;
}

double Knapsack::max_load() {
    return this->MAX_LOAD;
}

double Knapsack::weight_of_item(int POS) {
    return this->WEIGHT_OF_ITEMS[POS];
}

double Knapsack::value_of_item(int POS) {
    return this->VALUE_OF_ITEMS[POS];
}


Knapsack::Knapsack(int N_ITEMS, double MAX_LOAD, vector<double> WEIGHTS, vector<double> VALUES) {

    this->N_ITEMS = N_ITEMS;
    this->MAX_LOAD = MAX_LOAD;

    this->WEIGHT_OF_ITEMS = WEIGHTS;
    this->VALUE_OF_ITEMS = VALUES;

}

Knapsack::~Knapsack() {
    WEIGHT_OF_ITEMS.clear();
    VALUE_OF_ITEMS.clear();

}

int Knapsack::size() {
    return this->N_ITEMS;
}
