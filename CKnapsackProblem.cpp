//
// Created by qivi on 11/29/18.
//

#include "CKnapsackProblem.h"

void CKnapsackProblem::configure() {

    ReadFile RF;
    int POP_S,N_ITER;
    double CROSS_PROB, MUT_PROB;
    this->KNAPSACK = RF.readfile();

    if(this->KNAPSACK == NULL){
        this->RDY = false;
        return;
    }

    cout<<"Enter POP SIZE: ";
    cin>>POP_S;

    while(POP_S < 2){
        cout<<"Wrong number, try again! : ";
        cin>>POP_S;
    }

    cout<<"Enter NUMBER OF ITERATIONS: ";
    cin>>N_ITER;

    while(N_ITER < 2){
        cout<<"Wrong number, try again! : ";
        cin>>N_ITER;
    }

    cout<<"Enter CROSSING PROBABILITY: ";
    cin>>CROSS_PROB;

    while(CROSS_PROB < 0.0 || CROSS_PROB > 1.0){
        cout<<"Wrong number, try again! : ";
        cin>>CROSS_PROB;
    }

    cout<<"Enter MUTATION PROBABILITY: ";
    cin>>MUT_PROB;

    while(MUT_PROB < 0.0 || MUT_PROB > 1.0){
        cout<<"Wrong number, try again! : ";
        cin>>MUT_PROB;
    }

    this->CGA = new CGeneticAlgorithm(POP_S,N_ITER,CROSS_PROB,MUT_PROB,this->KNAPSACK);
    this->RDY = true;

}

void CKnapsackProblem::start() {

    if(this->RDY){
        this->CGA->run_ga();
    }

    else{
        cout<<"CKnapsackProblem not ready"<<endl;
    }

}

CKnapsackProblem::CKnapsackProblem() {
    srand(time(0));
    this->RDY = false;
}

CKnapsackProblem::~CKnapsackProblem() {

    delete KNAPSACK;
    delete CGA;
}

void CKnapsackProblem::fit_of_gen(int X, int Y) {

    if(this->RDY){
        this->CGA->fit_of_gen(X,Y);
    }
    else{
        cout<<"CKnapsackProblem not ready"<<endl;
    }

}
