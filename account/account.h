#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
#include<string>
// #include"../admin/admin.h"
// #include"../user/user.h"
using namespace std;

class Account {
private:

    string userName;
    string passWord;
    // vector<Account> accounts;

public:

    Account();
    Account(string userName, string passWord);
    ~Account();
    //userName
    string getUserName();
    void setUserName(string userName);
    //passWord
    string getPassWord();
    void setPassWord(string passWord);

    //read data from file
    void readData(string s);
    //write data
    void writeData(FILE* dataFile);

};

#endif