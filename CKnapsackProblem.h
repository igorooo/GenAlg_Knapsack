//
// Created by qivi on 11/29/18.
//

#ifndef ZAD_4_ZMPO_CKNAPSACKPROBLEM_H
#define ZAD_4_ZMPO_CKNAPSACKPROBLEM_H


#include "Knapsack.h"
#include "CGeneticAlgorithm.h"
#include "ReadFile.h"
#include <cstdlib>

class CKnapsackProblem {

private:
    Knapsack* KNAPSACK;
    CGeneticAlgorithm* CGA;
    bool RDY;

public:

    void configure();
    void start();
    void fit_of_gen(int X, int Y);
    CKnapsackProblem();
    ~CKnapsackProblem();







};


#endif //ZAD_4_ZMPO_CKNAPSACKPROBLEM_H
