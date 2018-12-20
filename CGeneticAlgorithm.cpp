//
// Created by qivi on 11/29/18.
//

#include "CGeneticAlgorithm.h"

template<class T>
void CGeneticAlgorithm<T>::cr_fst_gen() {

        for(int i = 0; i < this->POP_SIZE; i++){

                F_GEN.push_back(new CIndividual<T>(this->CROSS_PROBA,this->MUTATION_PROBA,this->KNAPSACK));
               // CInARRAY[i]->print_gen();
        }
        F_GEN.push_back(this->find_cur_leader(F_GEN));

        this->LEADER = this->find_cur_leader(F_GEN);
}

template<class T>
void CGeneticAlgorithm<T>::next_gen(int LAST_GEN) {

        CIndividual<T>* PARENT_A;
        CIndividual<T>* PARENT_B;
        CIndividual<T>* CHILD_1;
        CIndividual<T>* CHILD_2;
        int C_PART1, C_PART2;


        for(int POP_ITER = 0; POP_ITER < this->POP_SIZE /2; POP_ITER++){

            //cout<<CURRENT_GEN<<"<-"<<endl;
            PARENT_A = this->parent(F_GEN);
            PARENT_B = this->parent(F_GEN);

            C_PART1 = (rand()%(this->KNAPSACK->size()-2))+1;
            C_PART2 = (rand()%(this->KNAPSACK->size()-2))+1;

            PARENT_A->set_cross_place(C_PART1,C_PART2);
            PARENT_B->set_cross_place(C_PART1,C_PART2);

           // this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_A->cross(PARENT_B,CROSS_PART);


           //WHOLE__GENS(LAST_GEN+1).push_back(PARENT_A->cross(PARENT_B,C_PART1,C_PART2));  // OLD ONES
           //WHOLE__GENS(LAST_GEN+1).push_back(PARENT_B->cross(PARENT_A,C_PART1,C_PART2));

           CHILD_1 = *PARENT_A + *PARENT_B;
           CHILD_2 = *PARENT_B + *PARENT_A;


           S_GEN.push_back(CHILD_1);
           S_GEN.push_back(CHILD_2);

        }


        /**  MUTATION */
        for(int i = 0; i < S_GEN.size(); i++){
                ++(*SGEN(i));
        }

        CIndividual<T> * N_LEADER = this->find_cur_leader(S_GEN);

        S_GEN.push_back(N_LEADER);

        this->LEADER = this->get_leader(N_LEADER);

        SWAP_GEN();
}

template<class T>
CIndividual<T>* CGeneticAlgorithm<T>::find_cur_leader(vector< CIndividual<T>* > GEN) {

        CIndividual<T>* LEADER = GEN.at(0);


        for(int i = 0; i < this->POP_SIZE; i++){

                if( *GEN.at(i) > *LEADER ){

                        LEADER = GEN.at(i);
                }
        }

        return new CIndividual<T>(*LEADER);
}

template<class T>
CIndividual<T>* CGeneticAlgorithm<T>::parent(vector< CIndividual<T>* > GEN) {

        int CANDIDATE_A = rand()%(this->POP_SIZE);
        int CANDIDATE_B = rand()%(this->POP_SIZE);

        if( (*GEN.at(CANDIDATE_A)) > (*GEN.at(CANDIDATE_B))){
                return GEN.at(CANDIDATE_A);
        }

        return GEN.at(CANDIDATE_B);

}


template<class T>
CIndividual<T>* CGeneticAlgorithm<T>::wh_gen_leader() {

        return this->LEADER;
}

template<class T>
void CGeneticAlgorithm<T>::run_ga() {

        if(this->POP_SIZE < 2){
                cout<<" POP_SIZE must be greater than 1"<<endl;
                return;
        }

        time_t CURRENT_TIME,END_TIME;
        CURRENT_TIME = time(NULL);
        END_TIME = CURRENT_TIME + this->END_TIME;

        CIndividual<T>* LEADER;


        this->cr_fst_gen();

        END_GENERATION = 1;

        while(CURRENT_TIME < END_TIME){

                this->next_gen(END_GENERATION-1);


                END_GENERATION++;
                CURRENT_TIME = time(NULL);

        }



        /*  OLD ONE
        for(int i = 1; i < this->END_GENERATION; i++){

                this->next_gen(i-1);
        } */

        this->DONE = true;


        cout<<"Leader: ";
        this->wh_gen_leader()->print_gen();
        cout<<endl;
        cout<<"no. of ITERATIONS: "<<END_GENERATION<<endl;


}

template<class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(int POP_SIZE, int END_TIME, double CROSS_PROBA, double MUTATION_PROBA,
                                     Knapsack *KNAPSACK) {

        this->POP_SIZE = POP_SIZE;
        this->KNAPSACK = KNAPSACK;
        this->CROSS_PROBA = CROSS_PROBA;
        this->MUTATION_PROBA = MUTATION_PROBA;
        this->END_TIME = END_TIME;
        this->DONE = false;

        if(this->POP_SIZE%2 == 1)
                this->POP_SIZE++;


}

template<class T>
CGeneticAlgorithm<T>::~CGeneticAlgorithm() {

        for(int i = 0; i < F_GEN.size(); i++){
                delete FGEN(i);
                //delete SGEN(i);
        }

        F_GEN.clear();
        S_GEN.clear();

        //delete KNAPSACK;
}


template<class T>
void CGeneticAlgorithm<T>::print_gen(vector< CIndividual<T>* > GEN) {


        for (int i = 0; i < this->POP_SIZE; i++) {
                GEN.at(i)->print_gen();
                cout << " ";
        }
        cout << endl;
}


        /*
template <class T>
void CGeneticAlgorithm<T>::fit_of_gen(int X, int Y) {

        if( ( X >= 0 && X < this->WHOLE_GENS.size() ) && ( Y >= 0 && Y < this->POP_SIZE)){
                cout<<"Fitnes of genotype number  "<<Y<<"  from  "<<Y<<" generation  = " <<WHOLE_GENS(X,Y)->fitness()<<endl;
        }

        else{
                cout<<"WRONG (X,Y)"<<endl;
        }

} */

template<class T>
CIndividual<T> *CGeneticAlgorithm<T>::get_leader(CIndividual<T>* N_LEADER) {

        if(*N_LEADER > *this->LEADER){
                return N_LEADER;
        }
        return this->LEADER;
}


template class CGeneticAlgorithm<bool>;
template class CGeneticAlgorithm<int>;
template class CGeneticAlgorithm<double>;