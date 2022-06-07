#ifndef _USER_H_
#define _USER_H_
#include<vector>
#include "../account/account.h"


using namespace std;

class User {
private:

    string fullName;
    string citizenID;  // CCCD
    string phoneNumber;
    __int64 balance;  // long long = _int64


public:

    User();
    User(string fullName, string citizenID, string phoneNumber, __int64 balance);
    ~User();
    //Getter, Setter
    //Fullname
    string getFullName();
    void setFullName(string fullName);
    //citizenID
    string getCitizenID();
    void setCitizenID(string citizenID);
    //ID
    string getPhoneNumber();
    void setPhoneNumber(string phoneNumber);
    //balance
    __int64 getBalance();
    void setBalance(__int64 balance);
    //in Data
    void inData(string phoneNumber);

    //display infor
    void displayData();

    //out data format
    void outData();

    //read user Data from string
    void readData(string s);

    //write data into File
    void writeData(FILE* dataFile);

    //Updating Account
    void updatingAccount();

    //change Password
    void changePassword(Account& accounts);

    //tranfer money
    void transferMoney(Account& account, vector<User>& users);

    //withdraw money
    void withdrawMoney(Account& accounts);

    //view transaction history
    void viewTransactionHistory();

};

#endif