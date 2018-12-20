//
// Created by qivi on 10/21/18.
//

#include "CMenuCommand.h"


void CMenuCommand::run() {

    if(this->COMMAND == NULL){
        cout<<EMPTY_COMMAND<<endl;

    }

    else{
        this->COMMAND->run_command();
    }
}


int CMenuCommand::class_id() {
    return CMENUCOMMAND_ID;
}

void CMenuCommand::remove() {

}



CMenuCommand::CMenuCommand(string S_NAME, string S_COMMAND ,CCommand *COMMAND) {
    this->COMMAND = COMMAND;
    this->S_COMMAND = S_COMMAND;
    this->S_NAME = S_NAME;
}

CMenuCommand::CMenuCommand(string S_NAME, string S_COMMAND) {
    this->COMMAND = COMMAND;
    this->S_COMMAND = S_COMMAND;
    this->S_NAME = S_NAME;
}

CMenuCommand::~CMenuCommand() {
    delete COMMAND;
    cout<<"removing: "<<this->S_NAME<<endl;
}

void CMenuCommand::show_leafs() {}


