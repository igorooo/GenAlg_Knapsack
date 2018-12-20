//
// Created by qivi on 10/19/18.
//

#ifndef ZAD_2_ZMPO_CMENU_H
#define ZAD_2_ZMPO_CMENU_H

#include <vector>
#include <string>
#include <cstdlib>
#include "CMenuItem.h"
#include "CMenuCommand.h"
#define CMENU_ID 1
#define BACK "back"
#define EDIT_MENU "edit"
#define DELETE_ITEM "delete"


using namespace std;

class CMenu : public CMenuItem{

private:

    vector <CMenuItem*> VECTOR;


    string name_helper(string NAME);
    string command_helper(string COMMAND);

public:

    void run();
    int check_for_command(string COMMAND);
    int check_for_name(string NAME);
    void add_CMenuItem(CMenuItem *ITEM);
    void edit_menu();
    void remove();
    void delete_item(int POSITION);
    void delete_menu();
    int delete_command_helper(string COMMAND);
    int class_id();
    void show_leafs();


    CMenu(string S_NAME, string S_COMMAND);
    ~CMenu();


};


#endif //ZAD_2_ZMPO_CMENU_H
