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

#define EPSILON 0.0001

using namespace std;

template <class T>
class CIndividual {

private:
    T *GENOTYPE;

    int SIZE;
    double MAX_LOAD;
    double FITNESS;
    double CROSS_PROB,MUT_PROB;
    int C_PART1,C_PART2;
    Knapsack* KNAPSACK;

    void create_genotype();
    bool brandom(double PROBA);
    void c_fitness();  // count fitness

public:

    double fitness();
    void mutation();   //  0 <= PROBABILITY <=1
    void print_gen();
    void set_cross_place(int CP1, int CP2);
    int max_multi(int POS);  // RETURN HOW MUCH ITEM A CAN KNAPSACK HOLD ( max_multi(POS of A) * weight of A = MAX_WEIGHT )

    CIndividual(CIndividual &CLONE);
    CIndividual( double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK);
    CIndividual( double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK, T* GENOTYPE);
    ~CIndividual();

    bool operator>(CIndividual &OBJECT);
    CIndividual* operator+(CIndividual &OBJECT);
    void operator++();
    void operator=(CIndividual<T>& OBJECT);

    // ++  mutacja
    // =
    // +  krzyżowanie



};


#endif //ZAD_4_ZMPO_CINDIVIDUAL_H
