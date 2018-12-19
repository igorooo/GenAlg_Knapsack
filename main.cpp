#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "CIndividual.h"
#include "Knapsack.h"
#include "CGeneticAlgorithm.h"
#include "ReadFile.h"
#include "CKnapsackProblem.h"
#include <fstream>

// testing:   ../test2 30 100 0.8 0.1

int main() {

    CKnapsackProblem KNP;

    KNP.configure();
    KNP.start();

    //KNP.fit_of_gen(99,0);


    return 0;
}

    /*

    double vTab[] = {1.0, 2.1, 3, 4, 5};   //WART
    double wTab[] = {1.5, 2.6, 2, 4, 4.5};  //WAGI

    vector<double> weights;
    vector<double> values;

    for(int i = 0; i < SIZE; i++){
        weights.push_back(wTab[i]);
        values.push_back(vTab[i]);
    }


    Knapsack* KN = new Knapsack(5,12.0,weights,values);


    int POP_SIZE = 10;
    int END_GEN = 10;
    double CROSS_PROB = 0.7;
    double MUT_PROB = 0.1;

    bool tt[] = {1,1,0,0,1};
    bool tt1[] = {1,0,0,1,1};

    CIndividual* CII1 = new CIndividual(CROSS_PROB,MUT_PROB,KN,tt1);
    CIndividual* CII = new CIndividual(CROSS_PROB,MUT_PROB,KN,tt);

    cout<<"CII "<<CII->fitness()<<endl;
    cout<<"CII1 "<<CII1->fitness()<<endl;
    cout<<(*CII1 > *CII) <<endl;

    CGeneticAlgorithm* CGA = new CGeneticAlgorithm(POP_SIZE,END_GEN,CROSS_PROB,MUT_PROB,KN);

    CGA->run_ga();

    delete CGA;



    return 0;
} */