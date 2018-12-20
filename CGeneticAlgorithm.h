//
// Created by qivi on 11/29/18.
//

#ifndef ZAD_4_ZMPO_CGENETICALGORITHM_H
#define ZAD_4_ZMPO_CGENETICALGORITHM_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "CIndividual.h"
#include "Knapsack.h"

//#define WHOLE_GENS(X,Y) WHOLE_GENS.at(X).at(Y)
//#define WHOLE__GENS(X) WHOLE_GENS.at(X)
#define FGEN(X) F_GEN.at(X)
#define SGEN(X) S_GEN.at(X)
#define SWAP_GEN() F_GEN=S_GEN


template <class T>
class CGeneticAlgorithm {

    typedef vector<CIndividual<T>*> VCIND;

private:
    int POP_SIZE; // only even numbers
    int END_GENERATION,END_TIME;  //amount of iterations
    double CROSS_PROBA;  //PROBABILITY
    double MUTATION_PROBA; //PROBABILITY

   // vector< vector<CIndividual<T>*> > WHOLE_GENS;
    vector< CIndividual<T>* > F_GEN;  //first gen
    vector< CIndividual<T>* > S_GEN;  //second gen

    CIndividual<T>* LEADER;



    Knapsack* KNAPSACK;
    bool DONE;

public:
    void cr_fst_gen();  //create first generation
    void next_gen(int LAST_GEN);  //create next gen
    CIndividual<T>* find_cur_leader(vector< CIndividual<T>* > S_GEN); //current generation leader
    CIndividual<T>* get_leader(CIndividual<T>* N_LEADER);  // comparing current leader with new one
    CIndividual<T>* wh_gen_leader(); //whole generations leader
    CIndividual<T>* parent(vector< CIndividual<T>* > GEN);  // random parent
   // void fit_of_gen(int X, int Y);



    void run_ga();
    void print_gen(vector< CIndividual<T>* > GEN);

    CGeneticAlgorithm(int POP_SIZE,int END_GENERATION, double CROSS_PROBA, double MUTATION_PROBA, Knapsack* KNAPSACK );
    ~CGeneticAlgorithm();







};


#endif //ZAD_4_ZMPO_CGENETICALGORITHM_H
