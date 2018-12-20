//
// Created by qivi on 12/20/18.
//

#include "KNPmenu.h"

void KNPmenu::run() {

    CMenu *MENU = new CMenu("Knapsack Problem","knp");

    CKnapsackProblem<bool> *b_KNP = new CKnapsackProblem<bool>();
    CKnapsackProblem<int> *i_KNP = new CKnapsackProblem<int>();;
    CKnapsackProblem<double> *d_KNP = new CKnapsackProblem<double>();;

    vector <CMenuCommand*> CMENU_COMMAND_ARRAY;

    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("BINARY Knapsack Problem","bool",b_KNP));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("INTEGER Knapsack Problem","int",i_KNP));
    CMENU_COMMAND_ARRAY.push_back(new CMenuCommand("REALN Knapsack Problem","double",d_KNP));

    for(int i = 0; i < CMENU_COMMAND_ARRAY.size(); i++) MENU->add_CMenuItem(CMENU_COMMAND_ARRAY[i]);

    MENU->run();

    delete b_KNP;
    delete i_KNP;
    delete d_KNP;
}

KNPmenu::~KNPmenu() {

}
