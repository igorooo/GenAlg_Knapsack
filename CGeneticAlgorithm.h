//
// Created by qivi on 11/29/18.
//

#ifndef ZAD_4_ZMPO_CGENETICALGORITHM_H
#define ZAD_4_ZMPO_CGENETICALGORITHM_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include "CIndividual.h"
#include "Knapsack.h"

#define WHOLE_GENS(X,Y) WHOLE_GENS.at(X).at(Y)
#define WHOLE__GENS(X) WHOLE_GENS.at(X)

typedef vector<CIndividual*> VCIND;

class CGeneticAlgorithm {

private:
    int POP_SIZE; // only even numbers
    int END_GENERATION;  //amount of iterations
    double CROSS_PROBA;  //PROBABILITY
    double MUTATION_PROBA; //PROBABILITY

    vector< vector<CIndividual*> > WHOLE_GENS;

    Knapsack* KNAPSACK;
    bool DONE;

public:
    void cr_fst_gen();  //create first generation
    void next_gen(int LAST_GEN);  //create next gen
    CIndividual* find_cur_leader(int POS); //current generation leader
    CIndividual* wh_gen_leader(); //whole generations leader
    CIndividual* parent(int POS);  // random parent
    void fit_of_gen(int X, int Y);


    void run_ga();
    void print_wh_gen();
    void print_gen(int POS);
    void print_leaders();

    CGeneticAlgorithm(int POP_SIZE,int END_GENERATION, double CROSS_PROBA, double MUTATION_PROBA, Knapsack* KNAPSACK );
    ~CGeneticAlgorithm();







};


#endif //ZAD_4_ZMPO_CGENETICALGORITHM_H
