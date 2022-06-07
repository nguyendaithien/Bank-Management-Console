#ifndef _UTILITIES_H_
#define _UTILITIES_H_
#include<vector>
#include "../user/user.h"
using namespace std;

// Draw line
void drawline(int number, char symbol);

//Enter number valid
__int16 choiceNumber(__int16 minRange, __int16 maxRange, string warning);

//display menu Sign In
void listsModesToSignIn();

//choice mode to sign in
void choiseModeToSignIn();

//Display modes of Admin's Account
void displayModeOfAdmin();

//Display modes of User's Account
void displayModeOfUser();

//Choice Modes of Admin's Account
void choiceModeOfAdmin();

//choice Mode of User's Account
void choiceModeOfUser(User& user, Account& accounts, vector<User> &users);

//write data acount in file
void writeAccountDataInFileUserMode(vector<Account>& accounts, vector<User>& users);

#endif