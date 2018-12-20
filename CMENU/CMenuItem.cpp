//
// Created by qivi on 10/20/18.
//

#include "CMenuItem.h"


string CMenuItem::s_command() {
    return this->S_COMMAND;
}

string CMenuItem::s_name() {
    return this->S_NAME;
}

void CMenuItem::show(){
    cout<<this->s_name()<<"("<<this->s_command()<<")"<<endl;
}

CMenuItem::~CMenuItem() {}




