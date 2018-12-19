//
// Created by qivi on 11/28/18.
//

#ifndef ZAD_4_ZMPO_CINDIVIDUAL_H
#define ZAD_4_ZMPO_CINDIVIDUAL_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include "Knapsack.h"

#define EPSILON 0.001

using namespace std;


class CIndividual {

private:
    bool *GENOTYPE;

    int SIZE;
    double MAX_LOAD;
    double FITNESS;
    double CROSS_PROB,MUT_PROB;
    Knapsack* KNAPSACK;

    void create_genotype();
    bool brandom(double PROBA);
    void c_fitness();  // count fitness

public:

    double fitness();
    void mutation();   //  0 <= PROBABILITY <=1
    CIndividual* cross(CIndividual* PARENT_B, int C_PART1, int C_PART2);  // this = PARENT_A
    void print_gen();

    CIndividual(CIndividual &CLONE);
    CIndividual( double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK);
    CIndividual( double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK, bool* GENOTYPE);
    ~CIndividual();

    bool operator>(CIndividual &OBJECT);

    // ++  mutacja
    // =
    // +  krzyżowanie



};


#endif //ZAD_4_ZMPO_CINDIVIDUAL_H
