//
// Created by qivi on 10/20/18.
//

#define DEFAULT_COMMAND "default command"

#ifndef ZAD_2_ZMPO_CCOMMAND_H
#define ZAD_2_ZMPO_CCOMMAND_H

#include <string>
#include <iostream>

using namespace std;

class CCommand{


protected:
    string MESSAGE;


public:

    virtual void run_command();
    CCommand(string MESSAGE);
    CCommand();


};

#endif //ZAD_2_ZMPO_CCOMMAND_H
