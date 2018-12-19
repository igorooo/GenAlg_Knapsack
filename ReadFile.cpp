//
// Created by qivi on 12/6/18.
//

#include "ReadFile.h"

Knapsack* ReadFile::readfile() {

    string FILE_NAME,FILE;

    cout<<"Enter file name (also PATH if not in the same directory for e.g ../test2 ) : ";
    cin>>FILE_NAME;

    ifstream READER;

    READER.open(FILE_NAME.c_str());

    while(! READER.good() ){

        cout<<"wrong path or file name, try again!"<<endl;
        cout<<"Enter file name (also PATH if not in the same directory for e.g ../SAVES/main.txt ) : ";
        cin>>FILE_NAME;
        READER.open(FILE_NAME.c_str());

        if(FILE_NAME == "stop"){
            cout<<"aborted"<<endl;
            return NULL;
        }
    }


    int N_ITEMS;
    double MAX_LOAD,TEMP,WART,WART2;

    READER>>N_ITEMS;
    READER>>WART;

    if(WART != -1 || !good(N_ITEMS) ){
        READER.clear();
        READER.close();
        again();
        return NULL;
    }

    READER>>MAX_LOAD;
    READER>>WART;

    if(WART != -1 || !good(MAX_LOAD) ){
        READER.clear();
        READER.close();
        again();
        return NULL;
    }


    vector<double> WEIGHTS;
    vector<double> VALUES;

    for(int i = 0; i < N_ITEMS; i++){
        READER>>TEMP;
        if(TEMP > 0 && TEMP < MAX_WEIGHT){
            WEIGHTS.push_back(TEMP);
        }
    }

    READER>>WART;

    for(int i = 0; i < N_ITEMS; i++){
        READER>>TEMP;
        if(TEMP > 0 && TEMP < MAX_VALUE){
            VALUES.push_back(TEMP);
        }

    }

    READER>>WART2;

    READER.clear();
    READER.close();

    if(WEIGHTS.size() != N_ITEMS || VALUES.size() != N_ITEMS || WART != -1 || WART2 != -1){
        again();
        return NULL;
    }

    else{
        return (new Knapsack(N_ITEMS,MAX_LOAD,WEIGHTS,VALUES));
    }

}

void ReadFile::again() {

    cout<<"WRONG FORMAT OF TEXT FILE, TRY AGAIN!"<<endl;
    cout<<"SAVE CORRECT FILE AND REPEAT"<<endl;

}

bool ReadFile::good(double N) {
    return (N >= 0 && N < MAX_VALUE);
}

bool ReadFile::good(int N) {
    return (N >= 0 && N < MAX_VALUE);
}
