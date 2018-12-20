//
// Created by qivi on 10/19/18.
//

#ifndef ZAD_2_ZMPO_CMENUITEM_H
#define ZAD_2_ZMPO_CMENUITEM_H


#include <string>
#include <iostream>

using namespace std;

class CMenuItem{

protected:
    string S_COMMAND;
    string S_NAME;

public:
    virtual void run() = 0;
    virtual int class_id() = 0;
    virtual void remove() = 0;
    virtual void show_leafs() = 0;
    string s_command();
    string s_name();
    void show();

    virtual ~CMenuItem();



};

#endif //ZAD_2_ZMPO_CMENUITEM_H
