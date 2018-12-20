//
// Created by qivi on 11/29/18.
//

#include "CGeneticAlgorithm.h"

template<class T>
void CGeneticAlgorithm<T>::cr_fst_gen() {

        for(int i = 0; i < this->POP_SIZE; i++){

                WHOLE__GENS(0).push_back(new CIndividual<T>(this->CROSS_PROBA,this->MUTATION_PROBA,this->KNAPSACK));
               // CInARRAY[i]->print_gen();
        }
        WHOLE__GENS(0).push_back(this->find_cur_leader(0));
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
            PARENT_A = this->parent(LAST_GEN);
            PARENT_B = this->parent(LAST_GEN);

            C_PART1 = (rand()%(this->KNAPSACK->size()-2))+1;
            C_PART2 = (rand()%(this->KNAPSACK->size()-2))+1;

            PARENT_A->set_cross_place(C_PART1,C_PART2);
            PARENT_B->set_cross_place(C_PART1,C_PART2);

           // this->WHOLE_GENERATION[this->CURRENT_GEN+1][POP_ITER++] = PARENT_A->cross(PARENT_B,CROSS_PART);


           //WHOLE__GENS(LAST_GEN+1).push_back(PARENT_A->cross(PARENT_B,C_PART1,C_PART2));  // OLD ONES
           //WHOLE__GENS(LAST_GEN+1).push_back(PARENT_B->cross(PARENT_A,C_PART1,C_PART2));

           CHILD_1 = *PARENT_A + *PARENT_B;
           CHILD_2 = *PARENT_B + *PARENT_A;


           WHOLE__GENS(LAST_GEN+1).push_back(CHILD_1);
           WHOLE__GENS(LAST_GEN+1).push_back(CHILD_2);

        }


        /**  MUTATION */
        for(int i = 0; i < WHOLE__GENS(LAST_GEN+1).size(); i++){
                ++(*WHOLE_GENS(LAST_GEN+1,i));
        }



        WHOLE__GENS(LAST_GEN+1).push_back(this->find_cur_leader(LAST_GEN+1));
}

template<class T>
CIndividual<T>* CGeneticAlgorithm<T>::find_cur_leader(int POS) {

        CIndividual<T>* LEADER = WHOLE_GENS(POS,0);


        for(int i = 0; i < this->POP_SIZE; i++){

                if( *WHOLE_GENS(POS,i) > *LEADER ){

                        LEADER = WHOLE_GENS(POS,i);
                }
        }

        return new CIndividual<T>(*LEADER);
}

template<class T>
CIndividual<T>* CGeneticAlgorithm<T>::parent(int POS) {

        int CANDIDATE_A = rand()%(this->POP_SIZE);
        int CANDIDATE_B = rand()%(this->POP_SIZE);

        if( WHOLE_GENS(POS,CANDIDATE_A) > WHOLE_GENS(POS,CANDIDATE_B)){
                return WHOLE_GENS(POS,CANDIDATE_A);
        }

        return WHOLE_GENS(POS,CANDIDATE_B);

}


template<class T>
CIndividual<T>* CGeneticAlgorithm<T>::wh_gen_leader() {

        CIndividual<T>* WH_LEADER = WHOLE_GENS(0,this->POP_SIZE);

        for(int POP_ITER = 0; POP_ITER < this->END_GENERATION; POP_ITER++){

                if(*WHOLE__GENS(POP_ITER).back() > *WH_LEADER){
                        WH_LEADER = WHOLE__GENS(POP_ITER).back();
                }
        }

        return WH_LEADER;
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

        this->print_wh_gen();

        cout<<"Leader: ";
        this->wh_gen_leader()->print_gen();
        cout<<endl;


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

        for(int i = 0; i < this->END_GENERATION; i++)
                WHOLE_GENS.push_back( VCIND() );

}

template<class T>
CGeneticAlgorithm<T>::~CGeneticAlgorithm() {

        for(int i = 0; i < this->WHOLE_GENS.size(); i++){
                for(int j = 0; j < WHOLE__GENS(i).size(); j++){
                        delete WHOLE_GENS(i,j);
                }
                WHOLE__GENS(i).clear();
        }
        WHOLE_GENS.clear();
        //delete KNAPSACK;
}

template<class T>
void CGeneticAlgorithm<T>::print_wh_gen() {

        if(!this->DONE){
                cout<<"AG is not done yet!"<<endl;
                return;
        }


        for(int i = 0; i < this->END_GENERATION; i++){

                cout<<"GEN "<<i<<" : ";
                this->print_gen(i);
        }


}

template<class T>
void CGeneticAlgorithm<T>::print_gen(int POS) {


        for (int i = 0; i < this->POP_SIZE; i++) {
                WHOLE_GENS(POS,i)->print_gen();
                cout << " ";
        }
        cout << endl;
}

template<class T>
void CGeneticAlgorithm<T>::print_leaders() {

        cout<<endl<<endl<<"print leaders"<<endl;

        for(int i = 0; i < this->WHOLE_GENS.size(); i++){
                WHOLE_GENS(i,this->POP_SIZE)->print_gen();
        }

}

template <class T>
void CGeneticAlgorithm<T>::fit_of_gen(int X, int Y) {

        if( ( X >= 0 && X < this->WHOLE_GENS.size() ) && ( Y >= 0 && Y < this->POP_SIZE)){
                cout<<"Fitnes of genotype number  "<<Y<<"  from  "<<Y<<" generation  = " <<WHOLE_GENS(X,Y)->fitness()<<endl;
        }

        else{
                cout<<"WRONG (X,Y)"<<endl;
        }

}


template class CGeneticAlgorithm<bool>;
template class CGeneticAlgorithm<int>;
template class CGeneticAlgorithm<double>;