//
// Created by qivi on 11/29/18.
//

#include "CGeneticAlgorithm.h"

void CGeneticAlgorithm::cr_fst_gen() {

        for(int i = 0; i < this->POP_SIZE; i++){

                WHOLE__GENS(0).push_back(new CIndividual(this->CROSS_PROBA,this->MUTATION_PROBA,this->KNAPSACK));
               // CInARRAY[i]->print_gen();
        }
        WHOLE__GENS(0).push_back(this->find_cur_leader(0));
}

void CGeneticAlgorithm::next_gen(int LAST_GEN) {

        CIndividual* PARENT_A;
        CIndividual* PARENT_B;
        int C_PART1, C_PART2;


        for(int POP_ITER = 0; POP_ITER < this->POP_SIZE /2; POP_ITER++){

            //cout<<CURRENT_GEN<<"<-"<<endl;
            PARENT_A = this->parent(LAST_GEN);
            PARENT_B = this->parent(LAST_GEN);

            C_PART1 = (rand()%(this->KNAPSACK->size()-2))+1;
            C_PART2 = (rand()%(this->KNAPSACK->size()-2))+1;

           // this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_A->cross(PARENT_B,CROSS_PART);


           WHOLE__GENS(LAST_GEN+1).push_back(PARENT_A->cross(PARENT_B,C_PART1,C_PART2));
           WHOLE__GENS(LAST_GEN+1).push_back(PARENT_B->cross(PARENT_A,C_PART1,C_PART2));


        }

        /**  MUTATION */
        for(int i = 0; i < WHOLE__GENS(LAST_GEN+1).size(); i++){
                WHOLE_GENS(LAST_GEN+1,i)->mutation();
        }

        WHOLE__GENS(LAST_GEN+1).push_back(this->find_cur_leader(LAST_GEN+1));
}

CIndividual* CGeneticAlgorithm::find_cur_leader(int POS) {

        CIndividual* LEADER = WHOLE_GENS(POS,0);


        for(int i = 0; i < this->POP_SIZE; i++){

                if( *WHOLE_GENS(POS,i) > *LEADER ){

                        LEADER = WHOLE_GENS(POS,i);
                }
        }

        return new CIndividual(*LEADER);
}

CIndividual* CGeneticAlgorithm::parent(int POS) {

        int CANDIDATE_A = rand()%(this->POP_SIZE);
        int CANDIDATE_B = rand()%(this->POP_SIZE);

        if( WHOLE_GENS(POS,CANDIDATE_A) > WHOLE_GENS(POS,CANDIDATE_B)){
                return WHOLE_GENS(POS,CANDIDATE_A);
        }

        return WHOLE_GENS(POS,CANDIDATE_B);

}



CIndividual* CGeneticAlgorithm::wh_gen_leader() {

        CIndividual* WH_LEADER = WHOLE_GENS(0,this->POP_SIZE);

        for(int POP_ITER = 0; POP_ITER < this->END_GENERATION; POP_ITER++){

                if(*WHOLE__GENS(POP_ITER).back() > *WH_LEADER){
                        WH_LEADER = WHOLE__GENS(POP_ITER).back();
                }
        }

        return WH_LEADER;
}

void CGeneticAlgorithm::run_ga() {

        if(this->POP_SIZE < 2){
                cout<<" POP_SIZE must be greater than 1"<<endl;
                return;
        }

        this->cr_fst_gen();

        for(int i = 1; i < this->END_GENERATION; i++){

                this->next_gen(i-1);
        }

        this->DONE = true;

        this->print_wh_gen();

        cout<<"Leader: ";
        this->wh_gen_leader()->print_gen();
        cout<<endl;


}

CGeneticAlgorithm::CGeneticAlgorithm(int POP_SIZE, int END_GENERATION, double CROSS_PROBA, double MUTATION_PROBA,
                                     Knapsack *KNAPSACK) {

        this->POP_SIZE = POP_SIZE;
        this->KNAPSACK = KNAPSACK;
        this->CROSS_PROBA = CROSS_PROBA;
        this->MUTATION_PROBA = MUTATION_PROBA;
        this->END_GENERATION = END_GENERATION;
        this->DONE = false;

        if(this->POP_SIZE%2 == 1)
                this->POP_SIZE++;

        for(int i = 0; i < this->END_GENERATION; i++)
                WHOLE_GENS.push_back( VCIND() );

}

CGeneticAlgorithm::~CGeneticAlgorithm() {

        for(int i = 0; i < this->WHOLE_GENS.size(); i++){
                for(int j = 0; j < WHOLE__GENS(i).size(); j++){
                        delete WHOLE_GENS(i,j);
                }
                WHOLE__GENS(i).clear();
        }
        WHOLE_GENS.clear();
        //delete KNAPSACK;
}

void CGeneticAlgorithm::print_wh_gen() {

        if(!this->DONE){
                cout<<"AG is not done yet!"<<endl;
                return;
        }


        for(int i = 0; i < this->END_GENERATION; i++){

                cout<<"GEN "<<i<<" : ";
                this->print_gen(i);
        }


}

void CGeneticAlgorithm::print_gen(int POS) {


        for (int i = 0; i < this->POP_SIZE; i++) {
                WHOLE_GENS(POS,i)->print_gen();
                cout << " ";
        }
        cout << endl;
}

void CGeneticAlgorithm::print_leaders() {

        cout<<endl<<endl<<"print leaders"<<endl;

        for(int i = 0; i < this->WHOLE_GENS.size(); i++){
                WHOLE_GENS(i,this->POP_SIZE)->print_gen();
        }

}

void CGeneticAlgorithm::fit_of_gen(int X, int Y) {

        if( ( X >= 0 && X < this->WHOLE_GENS.size() ) && ( Y >= 0 && Y < this->POP_SIZE)){
                cout<<"Fitnes of genotype number  "<<Y<<"  from  "<<Y<<" generation  = " <<WHOLE_GENS(X,Y)->fitness()<<endl;
        }

        else{
                cout<<"WRONG (X,Y)"<<endl;
        }

}

