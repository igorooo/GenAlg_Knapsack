//
// Created by qivi on 10/20/18.
//

#ifndef ZAD_2_ZMPO_CMENUCOMMAND_H
#define ZAD_2_ZMPO_CMENUCOMMAND_H

#include "CCommand.h"
#include "CMenuItem.h"
#include <iostream>
#define EMPTY_COMMAND "empty command"
#define CMENUCOMMAND_ID 2

using namespace std;

class CMenuCommand : public CMenuItem{

private:
    CCommand *COMMAND;

public:

    void test();
    void run();
    int class_id();
    void remove();
    void show_leafs();
    CMenuCommand(string S_NAME, string S_COMMAND ,CCommand *COMMAND);
    CMenuCommand(string S_NAME, string S_COMMAND);
    ~CMenuCommand();

};





#endif //ZAD_2_ZMPO_CMENUCOMMAND_H
