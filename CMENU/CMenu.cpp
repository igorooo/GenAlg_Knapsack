//
// Created by qivi on 10/20/18.
//

#include "CMenu.h"


int CMenu::check_for_command(string COMMAND) {

    int POSITION = 0,BOUND = this->VECTOR.size();

    for(POSITION ; POSITION < BOUND ; POSITION ++){
        if(VECTOR[POSITION]->s_command().compare(COMMAND) == 0)
            return POSITION;
    }

    return -1; //failed
}

int CMenu::check_for_name(string NAME) {

    int POSITION = 0,BOUND = this->VECTOR.size();

    for(POSITION ; POSITION < BOUND ; POSITION ++){
        if(VECTOR[POSITION]->s_name() == NAME)
            return POSITION;
    }

    return -1; //failed
}

string CMenu::name_helper(string NAME) {

    string S_NAME = NAME;

    while(check_for_name(S_NAME) != -1){

        cout<<"Given name already exist on current menu, try again: ";
        cin>>S_NAME;

    }

    return S_NAME;

}

string CMenu::command_helper(string COMMAND) {

    string S_COMMAND = COMMAND;

    while(check_for_command(S_COMMAND) != -1){

        cout<<"Given command already exist on current menu, try again: ";
        cin>>S_COMMAND;

    }

    return S_COMMAND;

}

int CMenu::delete_command_helper(string COMMAND) {

    string S_COMMAND = COMMAND;
    int POSITION = check_for_command(S_COMMAND);

    while(POSITION == -1 || S_COMMAND == this->S_COMMAND){

        cout<<"Cant find given command, try again: ";
        cin>>S_COMMAND;
        POSITION = check_for_command(S_COMMAND);
    }

    return POSITION;

}





void CMenu::run() {

    string OPTION_COMMAND = "";
    int BOUND,COMMAND_POSITION;


    while(OPTION_COMMAND.compare(BACK) != 0){


        BOUND = this->VECTOR.size();

        cout<<"\n\n";
        cout<<"To add positions in menu enter: (edit), to remove positions enter: (delete)"<<endl<<endl;


        for(int i = 0 ; i < BOUND ; i++){

            if(i == 0) cout<<"current menu: ";
            VECTOR[i]->show();

            if(i < BOUND-1) cout<<i+1<<". ";

        }

        cin>>OPTION_COMMAND;

        COMMAND_POSITION = check_for_command(OPTION_COMMAND);

        if(COMMAND_POSITION != -1){

            this->VECTOR[COMMAND_POSITION]->run();

        }

        if(COMMAND_POSITION == -1 && OPTION_COMMAND != BACK){

            if(OPTION_COMMAND == EDIT_MENU){
                this->edit_menu();
            }

            else if(OPTION_COMMAND == DELETE_ITEM){
                this->delete_menu();
            }

            else{
                cout<<"There is no such a position!"<<endl;
            }

        }
    }
}



void CMenu::add_CMenuItem(CMenuItem *ITEM) {

    this->VECTOR.push_back(ITEM);
}

void CMenu::edit_menu() {

    cout<<"1. To add new menu here enter (menu)\n2. To add new command here enter (command)\n";

    string OPTION,S_NAME,S_COMMAND;

    cin>>OPTION;

    if(OPTION == "menu"){


        cout<<"Enter new menu name: ";
        cin>>S_NAME;
        S_NAME = this->name_helper(S_NAME);


        cout<<"Enter new menu command: ";
        cin>>S_COMMAND;
        S_COMMAND = this->command_helper(S_COMMAND);

        this->add_CMenuItem(new CMenu(S_NAME,S_COMMAND));

    }

    if(OPTION == "command"){

        string OPTION_2,MESSAGE;

        cout<<"Enter new command name: ";
        cin>>S_NAME;

        cout<<"Enter command for this function: ";
        cin>>S_COMMAND;

        cout<<"Do you want to add CCommand for this function? if yes enter (yes): ";
        cin>>OPTION_2;

        if( OPTION_2 == "yes"){

            cout<<"Enter message for CCommand"<<endl;
            cin>>MESSAGE;

            this->add_CMenuItem(new CMenuCommand( S_NAME, S_COMMAND,   new CCommand(MESSAGE)  ));

        }

        else{
            this->add_CMenuItem(new CMenuCommand(S_NAME , S_COMMAND));
        }
    }
}



void CMenu::remove() {

    CMenuItem *TEMP;

    while(this->VECTOR.size() > 1){

        TEMP = VECTOR.back();
        VECTOR.pop_back();

        if(TEMP->class_id() == 1){

            TEMP->remove();
        }

        delete TEMP;
    }
}



void CMenu::delete_item(int POSITION) {

    CMenuItem *TEMP = VECTOR[POSITION];

    VECTOR.erase(VECTOR.begin()+POSITION);

    if(TEMP->class_id() == 1){
        TEMP->remove();
    }

    delete TEMP;
}

void CMenu::delete_menu() {

    string COMMAND;

    cout<<"Enter command of item u want to remove: ";

    cin>>COMMAND;


    delete_item(delete_command_helper(COMMAND));

}



int CMenu::class_id() {
    return CMENU_ID;
}

void CMenu::show_leafs() {

    CMenuItem *TEMP;

    // cout<<"entered: "<<this->S_NAME<<endl;

    if(VECTOR.size() > 1){

        for(int ITER = 1; ITER < VECTOR.size(); ITER++){

            TEMP = VECTOR[ITER];

            if(TEMP->class_id() == 2){
                cout<<"Leaf: ";
                TEMP->show();
            }

            if(TEMP->class_id() == 1){
                TEMP->show_leafs();
            }

            //cout<<"-->Cur. TEMP:";
            //TEMP->show();
        }

        // cout<<"end of: "<<this->S_NAME<<endl;
    }

    else{
        cout<<"Leaf: ";
        this->show();
    }

}


CMenu::CMenu(string S_NAME, string S_COMMAND) {
    this->S_NAME = S_NAME;
    this->S_COMMAND = S_COMMAND;
    this->VECTOR.push_back(this);


}

CMenu::~CMenu() {

    this->remove();
    cout<<"removing: "<<this->S_NAME<<endl;

}