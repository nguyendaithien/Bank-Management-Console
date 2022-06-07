#include<iostream>
#include<string>
// #include"../admin/admin.h"
#include"../user/user.h"
#include"../account/account.h"
using namespace std;


Account::Account() {}
Account::Account(string userName, string passWord) {}
Account::~Account() {}
//userName
string Account::getUserName() {
    return this->userName;
}
void Account::setUserName(string userName) {
    this->userName = userName;
}
//passWord
string Account::getPassWord() {
    return this->passWord;
}
void Account::setPassWord(string passWord) {
    this->passWord = passWord;
}

// read user from string
void Account::readData(string s) {
    for(__int16 i = 0; i < 20; i++) {
        if (s[i] == ' ' && s[i+1] == ' ') {
            //VD : hàm subtr(0, 3) : lấy kí tự trong chuỗi là stt 0,1,2
            this->userName = s.substr(0, i - 0);
            break;
        }
    }
    for(__int16 i = 20; i < 50; i++) {
        if (s[i] == ' ' && s[i+1] == ' ') {
            this->passWord = s.substr(20, i - 20);
            break;
        }
    }
}
// write data
void Account::writeData(FILE* dataFile) {
    fprintf(dataFile, "%-20s%-30s\n", this->userName.c_str(), this->passWord.c_str());
}