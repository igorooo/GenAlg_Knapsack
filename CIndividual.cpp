//
// Created by qivi on 11/28/18.
//

#include "CIndividual.h"


template <class T>
void CIndividual<T>::c_fitness() {

    double SUM_OF_VALUE = 0, SUM_OF_WEIGHT = 0;

    for(int i = 0; i < this->SIZE; i++){

        if( (double)this->GENOTYPE[i] > 0){

            SUM_OF_VALUE += this->KNAPSACK->value_of_item(i) * (double)this->GENOTYPE[i];
            SUM_OF_WEIGHT += this->KNAPSACK->weight_of_item(i) * (double)this->GENOTYPE[i];
        }
    }

    if( (this->MAX_LOAD - SUM_OF_WEIGHT > 0) || (fabs(this->MAX_LOAD - SUM_OF_WEIGHT) < EPSILON )){   // LESS OR EQUAL FOR FLOAT N
        this->FITNESS = SUM_OF_VALUE;
    }

    else{
        this->FITNESS = 0;
    }

}

template <class T>
double CIndividual<T>::fitness() {
    return this->FITNESS;
}


template <class T>
bool CIndividual<T>::brandom(double PROBA) {

    double R = double(rand()%1001) / 1000.0;

    return (PROBA - R > 0);
}



template <class T>
CIndividual<T>::CIndividual(CIndividual &CLONE) {



    this->SIZE = CLONE.SIZE;
    this->MAX_LOAD = CLONE.MAX_LOAD;
    this->CROSS_PROB = CLONE.CROSS_PROB;
    this->MUT_PROB = CLONE.MUT_PROB;
    this->KNAPSACK = CLONE.KNAPSACK;
    this->FITNESS = CLONE.FITNESS;

    this->GENOTYPE = new T[CLONE.SIZE];

    for(int i = 0; i < CLONE.SIZE; i++){
        this->GENOTYPE[i] = CLONE.GENOTYPE[i];
    }
}

template <class T>
CIndividual<T>::CIndividual( double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK) {

    this->SIZE = KNAPSACK->size();
    this->MAX_LOAD = KNAPSACK->max_load();
    this->CROSS_PROB = CROSS_PROB;
    this->MUT_PROB = MUT_PROB;
    this->KNAPSACK = KNAPSACK;

    this->GENOTYPE = new T[this->SIZE +1];
    this->create_genotype();

    this->c_fitness();
}


template <class T>
CIndividual<T>::CIndividual( double CROSS_PROB, double MUT_PROB,Knapsack* KNAPSACK, T *GENOTYPE) {

    this->SIZE = KNAPSACK->size();
    this->MAX_LOAD = KNAPSACK->max_load();
    this->CROSS_PROB = CROSS_PROB;
    this->MUT_PROB = MUT_PROB;
    this->KNAPSACK = KNAPSACK;

    this->GENOTYPE = new T[this->SIZE+1];


    for(int i = 0; i < this->SIZE; i++){
        this->GENOTYPE[i] = GENOTYPE[i];
    }

    this->c_fitness();
}

template <class T>
CIndividual<T>::~CIndividual() {

    delete[] GENOTYPE;
}

template <class T>
CIndividual<T>* CIndividual<T>::operator+(CIndividual &OBJECT) {
    int PART1 = min(C_PART1,C_PART2);
    int PART2 = max(C_PART1,C_PART2);

    if(brandom(this->CROSS_PROB)){

        T N_GENOTYPE[this->SIZE];

        for(int i = 0; i < PART1; i++){
            N_GENOTYPE[i] = this->GENOTYPE[i];
        }

        for(int i = PART1; i < PART2; i++){
            N_GENOTYPE[i] = OBJECT.GENOTYPE[i];
        }

        for(int i = PART2; i < this->SIZE; i++){
            N_GENOTYPE[i] = this->GENOTYPE[i];
        }


        /*   //------- DEBUG ------
        this->print_gen();
        cout<<" + ";
        PARENT_B->print_gen();
        cout<<"  =  ";
        for(int i = 0; i < this->SIZE; i++)
            cout<<N_GENOTYPE[i];
        cout<<"     PART 1 = "<<PART1<<"PART 2 = "<<PART2<<endl; */


        return (new CIndividual(this->CROSS_PROB, this->MUT_PROB,this-> KNAPSACK, N_GENOTYPE));
    }

    else{
        return new CIndividual( *this );
    }
}

template<>
void CIndividual<bool>::operator++() {

    for(int i = 0; i < this->SIZE ; i++){

        if(brandom(this->MUT_PROB)){
            this->GENOTYPE[i] = !(this->GENOTYPE[i]);
        }
    }
    this->c_fitness();
}

template<>
void CIndividual<int>::operator++() {

    for(int i = 0; i < this->SIZE ; i++){

        if(brandom(this->MUT_PROB)){
            this->GENOTYPE[i] = (int)(rand()%10);
        }
    }
    this->c_fitness();
}

template<>
void CIndividual<double>::operator++() {

    for(int i = 0; i < this->SIZE ; i++){

        if(brandom(this->MUT_PROB)){
            this->GENOTYPE[i] = (double)((rand()%10000)/1000.0);
        }
    }
    this->c_fitness();
}

template <class T>
bool CIndividual<T>::operator>(CIndividual &OBJECT) {
    return (this->FITNESS > OBJECT.FITNESS);
}

template<class T>
void CIndividual<T>::operator=(CIndividual<T> &OBJECT) {

    this->SIZE = OBJECT.SIZE;
    this->MAX_LOAD = OBJECT.MAX_LOAD;
    this->CROSS_PROB = OBJECT.CROSS_PROB;
    this->MUT_PROB = OBJECT.MUT_PROB;
    this->KNAPSACK = OBJECT.KNAPSACK;
    this->FITNESS = OBJECT.FITNESS;

    this->GENOTYPE = new T[OBJECT.SIZE];


    for(int i = 0; i < this->SIZE; i++){
        this->GENOTYPE[i] = OBJECT.GENOTYPE[i];
    }
}

template<>
void CIndividual<bool>::create_genotype() {

    for(int i = 0; i < this->SIZE; i++){

        this->GENOTYPE[i] = (bool)(rand()%2);
    }

}

template<>
void CIndividual<int>::create_genotype() {

    for(int i = 0; i < this->SIZE; i++){

        this->GENOTYPE[i] = (int)(rand()%max_multi(i));
    }

}

template<>
void CIndividual<double>::create_genotype() {

    for(int i = 0; i < this->SIZE; i++){

        this->GENOTYPE[i] = (double)((rand()%(this->max_multi(i)*1000))/1000.0);
        cout<<GENOTYPE[i]<<endl;
    }

}


template <class T>
void CIndividual<T>::print_gen() {

    cout<<"|";

    for(int i = 0; i < this->SIZE; i++){
        cout<<"["<<this->GENOTYPE[i]<<"]";
    }

    cout<<"| ("<<this->fitness()<<") ";
    //cout<<" fitness: "<<this->FITNESS<<endl;

}

template<class T>
void CIndividual<T>::set_cross_place(int CP1, int CP2) {

    this->C_PART1 = CP1;
    this->C_PART2 = CP2;

}

template<class T>
int CIndividual<T>::max_multi(int POS) {
    return (int)(this->KNAPSACK->max_load()/this->KNAPSACK->weight_of_item(POS));
}


template class CIndividual<bool>;
template class CIndividual<int>;
template class CIndividual<double>;




