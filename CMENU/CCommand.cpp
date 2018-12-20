//
// Created by qivi on 10/21/18.
//

#include "CCommand.h"

void CCommand::run_command() {

    cout<<this->MESSAGE<<endl;
}

CCommand::CCommand(string MESSAGE) {
    this->MESSAGE = MESSAGE;
}

CCommand::CCommand() {
    this->MESSAGE = DEFAULT_COMMAND;
}

